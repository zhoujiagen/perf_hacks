# bpftrace

[bpftrace](https://github.com/iovisor/bpftrace) is a newer front end that provides a special-purpose, high-level language for developing BPF tools.

## Features

### Event Sources

- dynamic instrumentation, kernel-level: kprobe
- dynamic instrumentation, user-level: uprobe
- static tracing, kernel-level: tracepoint, software
- static tracing, user-level: usdt, via libbcc
- timed sampling events: profile
- interval events: interval
- PMC events: hardware
- synthetic events: BEGIN, END

### Actions

- filtering: predicates
- per-event output: `printf()`
- base variables: `global`, `$local`, `per[tid]`
- built-in variables: `pid`, `tid`, `comm`, `nsecs`, ...
- associative arrays: `key[value]`
- frequency counting: `count()`, `++`
- statistics: `min()`, `max()`, `sum()`, `avg()`, `stats()`
- histogram: `hist()`, `lhist()`
- timestamps and time deltas: `nsecs`, hash storage
- stack trace, kerbel: kstack
- stack trace, user: ustack
- symbol resolution, kernel-level: `ksym()`, `kaddr()`
- symbol resolution, user-level: `usym()`, `uaddr()`
- C struct navifation: `->`
- array access: `[]`
- shell commands: `system()`
- printing files: `cat()`
- positional parameter: `$1`, `$2`, ...

### General Features

- low-overhead instrumentation: BPF JIT, maps
- production safe: BPF verifier
- tools: under `/tools`
- tutorial: `/docs/tutorial_one_liners_chinese.md`
- reference guide: `/docs/reference_guide.md`


## bpftrace编程

usage:

```
bpftrace -e program
bpfrace file.bt
```

program structure:

```
program:
  // regular probes
  probes { actions }
  probes { actions }
  /*
  * probes with fitler
  */
  probes /filter/ { actions }
  // probes to execute same actions
  probe1,probe2,... { actions }

probes:
  type:identifier1[:identifier2[:...]]
  kprobe:vfs_read
  kprobe:vfs_*
  uprobe:/bin/bash:readline
  // 查看通配符适配的探针: bpftrace -l 'kprobe:vfs_*'

filter:
  /pid = 123/
  /pid/
  /pid > 100 && pid < 1000/

actions:
  { action one; action two; action three;}
  { $x = 42; printf("$x is %d", $x); }

functions:
  printf()
  exit()        // exit bpftrace
  str(char *)   // return a string from a pointer
  system(format[, arguments ...]) // run a command at the shell

variables:
  // built-in
  pid           // process id
  comm          // process name
  nsecs         // timestamp in nanoseconds
  curtask       // address of the current thread's task_struct
  tid           // current thread ID
  // scratch
  $1 = 1;
  $y = "hello";
  $z = (struct task_struct *) curtask;
  // map: global storage
  probe1 { @a = 1; }
  probe2 { $x = @a; }
  @start[tid] = nsecs;
  @path[pid, $fd] = str(arg0);  // multi-key map

map-functions:
  @x = count();   // a per-CPU map
  @x++;           // a global CPU map
  @y = sum($x);
  @z = hist($x);
  print(@x);
  delete(@start[tid]);
```

### bpftrace Probe Types

查看所有探针:

```
bpfrace -l '*'
```


- tracepoint(t): 内核静态探查点

```
tracepoint:tracepoint_name

tracepoint:syscalls:sys_enter_read
tracepoint:syscalls:sys_exit_read

// ssize_t read(int fd, void *buf, size_t count);
$ bpftrace -lv tracepoint:syscalls:sys_enter_read
tracepoint:syscalls:sys_enter_read
    int __syscall_nr;
    unsigned int fd;
    char * buf;
    size_t count;
// 引用参数: args->fd, args->buf, args->count, args->ret

$ bpftrace -e 'tracepoint:syscalls:sys_enter_read {
printf("-> clone() by %s PID %d\n", comm, pid); }
tracepoint:syscalls:sys_exit_read {
printf("<- clone() return %d, %s PID %d\n", args->ret, comm, pid); }'
$ bpftrace -e 't:syscalls:sys_*_execve { printf("%s %s PID %d\n", probe, comm, pid); }'
```

- usdt(U): 用户级静态定义的跟踪

```
usdt:binary_path:probe_name
usdt:libraty_path:probe_name
usdt:binary_path:probe_namespace:probe_name
usdt:library_path:probe_namespace:probe_name

bpftrace -l 'usdt:/usr/bin/python3'
```

- kprobe(k), kretprobe(kr): 内核动态函数(返回)探查

```
kprobe:function_name
kretprobe:function_name

// 参数arg0, arg1, ..., argN
// 返回值retval
```

- uprobe(u), uretprobe(ur): 用户层动态函数(返回)探查

```
uprobe:binary_path:function_name
uprobe:library_path:function_name
uretprobe:binary_path:function_name
uretprobe:library_path:function_name

// 参数arg0, arg1, ..., argN
// 返回值retval
```

- software(s),  hardware(h): 内核基于软件的事件, 硬件基于计数器的探查

```
software:event_name:count
software:event_name:
hardware:event_name:count
hardware:event_name:
```

`event_name`:

```
// software
cpu-clock
task-clock
page-faults
context-switches
cpu-migrations
minor-faults
major-faults
alignment-faults
emulation-faults
dummy
bpf-output

// hardware
cpu-cycles
instructions
cache-references
cache-misses
branch-instructions
bus-cycles
frontend-stalls
backend-stalls
ref-cycles
```

- profile(p), interval(i): 跨所有CPU的基于时间的采样, (单个CPU)的基于时间的报告

```
profile:hz:rate     // Hertz(events per second)
profile:s:rate      // seconds
profile:ms:rate     // milliseconds
profile:us:rate     // microseconds
interval:s:rate
interval:ms:rate
```

- BEGIN: bpftrace的开始
- END: bpftrace的结束

### Flow Control

- tests: fitler, ternary operator, if statement
- tests: `==`, `!=`, `>`, `<`, `>=`, `<=`, `&&`, `||`
- 表达式可以使用括号括起来
- 有限的支持循环
- ternary operator:

```
test ? true_statement : false_statement

$abs = $x >= 0 ? $x : -$x;
```

- if statement:

```
if (test) { true_statements }
if (test) { true_statements } else { false_statements }
```

- unrolles loop

```
unroll (count) { statements }
// count最大值为20
```

### Operators

- `=`: 赋值
- `+`, `-`, `*`, `/`: 加减乘除
- `++`, `--`: 自增, 自减
- `&`, `|`, `^`: 二进制与/或/异或
- `!`: 逻辑非
- `<<`, `>>`: 左移, 右移
- `+=`, `-=`, `*=`, `%=`, `&=`, `^=`, `<<=`, `>>=`: 复合操作符

### Variables

内建变量:

- pid: 进程ID
- tid: 线程ID
- uid: 用户ID
- username: 用户名称
- nsecs: 时间戳, 纳秒
- elapsed: 自bpftrace初始化开始的时间戳, 纳秒
- cpu: 处理器ID
- comm: 进程名称
- kstatck: 内核调用栈
- ustack: 用户层调用栈
- arg0, ..., argN: 一些探针类型的参数
- args: 一些探针类型的参数
- retval: 一些探针类型的范沪指
- func: 被跟踪的函数的名称
- probe: 当前探针的全名
- curtask: 内核`task_struct`
- cgroup: Cgroup ID
- $1, ..., $N: bpftrace程序的位置参数

临时变量:

```
$name
```

map变量:

```
@name
@name[key]
@name[key1, key2[, ...]]

@start = nsecs;           // integer type
@last[tid] = nsecs;       // key: integer, value: integer
@bytes = hist(retval);    // power-of-two histogram type
@who[pid, comm] = count();  // key: integer+string, value: count() map function

```

### Functions

```
printf(char *fmt, [, ...])    // 格式化输出
time(char *fmt)               // 输出格式化的时间
join(char *arr[]);            // 输出字符串数组, 按空格拼接
str(char *s [, int len])      // 返回指针s处的字符串
kstack(int limit)             // 返回内核栈, 有深度限制
kstack(mode [, limit])        // mode: bpftrace, perf
ustack(int limit)             // 返回用户栈, 有深度限制
ustack(mod [, limit])
ksym(void *p)                 // 接卸内核地址, 返回字符串符号
usym(void *p)                 // 解析用户控件地址, 返回字符串符号
kaddr(char *name)             // 解析内核符号名称到地址
uaddr(char *name)             // 解析用户空间符号名称到地址
reg(char *name)               // 返回寄存器中存储的值
ntop([int af, ] int addr)     // 返回IP地址的字符串表示
system(char *fmt, [, ...])    // 执行shell命令
cat(char *filename)           // 输出文件内容
exit()                        // 退出bpftrace
```

#### Map Functions

```
count()                     // 出现次数计数
sum(int n)                  // 和
avg(int n)                  // 平均值
min(int n)                  // 最小值
max(int n)                  // 最大值
stats(int n)                // 次数, 平均值, 和
hist(int n)                 // 值的power-of-two之防护
lhist(int n, int min, int max, int step) // 值的线性直方图
delete(@m[key])             // 删除键值对
print(@m[, top [, div]])    // 输出map
clean(@m)                   // 清空map
zero(@m)                    // 将所有值设置为0
```

### Debugging

## bpftrace One-Liners

```
bpftrace -e 'tracepoint:syscalls:sys_enter_execve { printf("%s -> %s\n", comm, str(args->filename)); }'
bpftrace -e 'tracepoint:syscalls:sys_enter_execve { join(args->argv); }'
bpftrace -e 'tracepoint:syscalls:sys_enter_openat { printf("%s %s\n", comm, str(args->filename)); }'
bpftrace -e 'tracepoint:raw_syscalls:sys_enter { @[comm] = count(); }'
bpftrace -e 'tracepoint:syscalls:sys_enter_* { @[probe] = count(); }'
bpftrace -e 'tracepoint:raw_syscalls:sys_enter { @[pid, comm] = count(); }'
bpftrace -e 'tracepoint:syscalls:sys_exit_read /args->ret/ { @[comm] = sum(args->ret); }'
bpftrace -e 'tracepoint:syscalls:sys_exit_read { @[comm] = hist(args->ret); }'
bpftrace -e 'tracepoint:block:block_rq_issue { printf("%d %s %d\n", pid, comm, args->bytes); }'
bpftrace -e 'software:major-faults:1 { @[comm] = count(); }'
bpftrace -e 'software:faults:1 { @[comm] = count(); }'
bpftrace -e 'profile:hz:49 /pid == 189/ { @[ustack] = count(); }'
```


## bpftrace工具汇总

- [bashreadline.bt](https://github.com/iovisor/bpftrace/tree/master/tools/bashreadline.bt)
- [biolatency.bt](https://github.com/iovisor/bpftrace/tree/master/tools/biolatency.bt)
- [biosnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/biosnoop.bt)
- [biostacks.bt](https://github.com/iovisor/bpftrace/tree/master/tools/biostacks.bt)
- [bitesize.bt](https://github.com/iovisor/bpftrace/tree/master/tools/bitesize.bt)
- [capable.bt](https://github.com/iovisor/bpftrace/tree/master/tools/capable.bt)
- [cpuwalk.bt](https://github.com/iovisor/bpftrace/tree/master/tools/cpuwalk.bt)
- [dcsnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/dcsnoop.bt)
- [execsnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/execsnoop.bt)
- [gethostlatency.bt](https://github.com/iovisor/bpftrace/tree/master/tools/gethostlatency.bt)
- [killsnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/killsnoop.bt)
- [loads.bt](https://github.com/iovisor/bpftrace/tree/master/tools/loads.bt)
- [mdflush.bt](https://github.com/iovisor/bpftrace/tree/master/tools/mdflush.bt)
- [naptime.bt](https://github.com/iovisor/bpftrace/tree/master/tools/naptime.bt)
- [oomkill.bt](https://github.com/iovisor/bpftrace/tree/master/tools/oomkill.bt)
- [opensnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/opensnoop.bt)
- [pidpersec.bt](https://github.com/iovisor/bpftrace/tree/master/tools/pidpersec.bt)
- [runqlat.bt](https://github.com/iovisor/bpftrace/tree/master/tools/runqlat.bt)
- [runqlen.bt](https://github.com/iovisor/bpftrace/tree/master/tools/runqlen.bt)
- [setuids.bt](https://github.com/iovisor/bpftrace/tree/master/tools/setuids.bt)
- [statsnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/statsnoop.bt)
- [swapin.bt](https://github.com/iovisor/bpftrace/tree/master/tools/swapin.bt)
- [syncsnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/syncsnoop.bt)
- [syscount.bt](https://github.com/iovisor/bpftrace/tree/master/tools/syscount.bt)
- [tcpaccept.bt](https://github.com/iovisor/bpftrace/tree/master/tools/tcpaccept.bt)
- [tcpconnect.bt](https://github.com/iovisor/bpftrace/tree/master/tools/tcpconnect.bt)
- [tcpdrop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/tcpdrop.bt)
- [tcplife.bt](https://github.com/iovisor/bpftrace/tree/master/tools/tcplife.bt)
- [tcpretrans.bt](https://github.com/iovisor/bpftrace/tree/master/tools/tcpretrans.bt)
- [tcpsynbl.bt](https://github.com/iovisor/bpftrace/tree/master/tools/tcpsynbl.bt)
- [threadsnoop.bt](https://github.com/iovisor/bpftrace/tree/master/tools/threadsnoop.bt)
- [vfscount.bt](https://github.com/iovisor/bpftrace/tree/master/tools/vfscount.bt)
- [vfsstat.bt](https://github.com/iovisor/bpftrace/tree/master/tools/vfsstat.bt)
- [writeback.bt](https://github.com/iovisor/bpftrace/tree/master/tools/writeback.bt)
- [xfsdist.bt](https://github.com/iovisor/bpftrace/tree/master/tools/xfsdist.bt)
