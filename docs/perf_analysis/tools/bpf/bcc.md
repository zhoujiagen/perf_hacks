# BCC: BPF Compiler Collection

> [BCC (BPF Compiler Collection)](https://github.com/iovisor/bcc) was the first higher-level tracing framework developed for BPF.
>
> It provides a C programming environment for writing kernel BPF code and other languages for the user-level interface: Python, Lua, and C++.

- [BCC - Tools for BPF-based Linux IO analysis, networking, monitoring, and more](https://github.com/iovisor/bcc): Github.
- [bcc Reference Guide](https://github.com/iovisor/bcc/blob/master/docs/reference_guide.md): 参考指南.
- [bcc Python Developer Tutorial](https://github.com/iovisor/bcc/blob/master/docs/tutorial_bcc_python_developer.md): Python开发教程.

## 特性

### 内核层特性

- dynamic instrumentation, kernel-level: kprobes
- dynamic instrumentation, user-level: uprobes
- static tracing, kernel-level: tracepoints
- timed sampling events: BPF with `perf_event_open()`
- PMC events: BPF with `perf_event_open()`
- filtering: via BPF programs
- debug output: `bpf_trace_printk()`
- per-event output: `bpf_perf_event_output()`
- basic variables: global and per-thread variables, via BPF maps
- associative arrays: via BPF maps
- frequency counting: via BPF maps
- histograms: power-of-two, linear, custom, via BPF maps
- timestamps and time deltas: `bpf_ktime_get_ns()` and BPF programs
- stack trace, kernel: BPF stackmap
- stack trace, user: BPF stackmap
- overwrite ring buffers: `perf_event_attr.write_backward`
- low-overhead instrumentation: BP JIT, BPF map summarizes
- production safe: BPF verifier

### 用户层特性

- static tracing, user-level: SystemTap-stype USDT probes, via uprobes
- debug output: Python with `BPF.trace_pipe()` and `BPF_.trace_fields()`
- per-event output: `BPF_PERF_OUTPUT` macro and `BPF.open_perf_buffer()`
- interval output: `BPF.get_table()` and `table.clear()`
- histogram printing: `table.print_log2_hist()`
- C struct navigation, kernel-level: BCC rewriter maps to `bpf_probe_read()`
- symbol resolution, kernel-level: `ksym()`, `ksymaddr()`
- symbol resolution, user-level: `usymaddr()`
- debuginfo symbol resolution support
- BPF tracepoint support: via `TRACEPOINT_PROBE`
- BPF stack trace support: `BPF_STACK_TRACE`
- various other helper macros and functions
- examples: under `/examples`
- tools: under `/tools`
- tutorials: under `/docs/tutorial*.md`
- reference guide: under `/docs/reference_guide.md`


## BCC工具汇总

- bpftool: tool for inspection and simple manipulation of eBPF programs and maps

|#|工具|说明|描述|
|-|:---|:---|:---|
|1 | [argdist](#argdist)    | 函数参数的频率或直方图. | Trace a function and display a histogram or frequency count of its parameter values. Uses Linux eBPF/bcc.|
|2 | bashreadline    | | |
|3 | biolatency    | | |
|4 | biosnoop    | | |
|5 | biotop    | | |
|6 | bitesize    | | |
|7 | bpflist    | | Display processes currently using BPF programs and maps.|
|8 | btrfsdist    | | |
|9 | btrfsslower    | | |
|10 | cachestat    | | |
|11 | cachetop    | | |
|12 | capable    | | |
|13 | cobjnew    | | |
|14 | [cpudist](#cpudist)    | on-CPU、off-CPU任务时间的直方图. | On- and off-CPU task time as a histogram.|
|15 | cpuunclaimed    | | |
|16 | criticalstat    | | |
|17 | dbslower    | | |
|18 | dbstat    | | |
|19 | dcsnoop    | | |
|20 | dcstat    | | |
|21 | deadlock    | | |
|22 | deadlock.c    | | |
|23 | drsnoop    | | |
|24 | execsnoop    | | |
|25 | [exitsnoop](#exitsnoop)    | 跟踪进程退出, 展示其存活时间和退出原因.| Trace all process termination (exit, fatal signal). Uses Linux eBPF/bcc.|
|26 | ext4dist    | | |
|27 | ext4slower    | | |
|28 | filelife    | | |
|29 | fileslower    | | |
|30 | filetop    | | |
|31 | [funccount](#funccount)    | 函数调用事件计数. | Count function, tracepoint, and USDT probe calls matching a pattern. Uses Linux eBPF/bcc.|
|32 | funclatency    | | |
|33 | funcslower    | | |
|34 | gethostlatency    | | |
|35 | [hardirqs](#hardirqs)    | 硬件中断的耗时.| Measure hard IRQ (hard interrupt) event time. Uses Linux eBPF/bcc.|
|36 | inject    | | |
|37 | javacalls    | | |
|38 | javaflow    | | |
|39 | javagc    | | |
|40 | javaobjnew    | | |
|41 | javastat    | | |
|42 | javathreads    | | |
|43 | killsnoop    | | |
|44 | klockstat    | | |
|45 | [llcstat](#llcstat)    | 使用PMC展示LLC(last-level cache)个各进程的命中率和未命中率. | Summarize CPU cache references and misses by process. Uses Linux eBPF/bcc.|
|46 | mdflush    | | |
|47 | memleak    | | |
|48 | mountsnoop    | | |
|49 | mysqld_qslower    | | |
|50 | nfsdist    | | |
|51 | nfsslower    | | |
|52 | nodegc    | | |
|53 | nodestat    | | |
|54 | [offcputime](#offcputime)    |汇总线程阻塞及off-CPU的时间. | Summarize off-CPU time by kernel stack trace. Uses Linux eBPF/bcc.|
|55 | offwaketime    | | |
|56 | oomkill    | | |
|57 | [opensnoop](#opensnoop)    |跟踪`open()`系统调用. |Trace open() syscalls. Uses Linux eBPF/bcc. |
|58 | perlcalls    | | |
|59 | perlflow    | | |
|60 | perlstat    | | |
|61 | phpcalls    | | |
|62 | phpflow    | | |
|63 | phpstat    | | |
|64 | pidpersec    | | |
|65 | [profile](#profile)    | 定时采样调用栈, 报告调用栈的频率. | Profile CPU usage by sampling stack traces. Uses Linux eBPF/bcc.|
|66 | pythoncalls    | | |
|67 | pythonflow    | | |
|68 | pythongc    | | |
|69 | pythonstat    | | |
|70 | reset-trace    | | |
|71 | rubycalls    | | |
|72 | rubyflow    | | |
|73 | rubygc    | | |
|74 | rubyobjnew    | | |
|75 | rubystat    | | |
|76 | [runqlat](#runqlat)    | 测量CPU调度器的延迟, 称为运行队列延迟.| Run queue (scheduler) latency as a histogram.|
|77 | [runqlen](#runqlen)    | 采样CPU运行队列的长度, 以直方图形式展示等待运行的任务数量. | Scheduler run queue length as a histogram.|
|78 | [runqslower](#runqslower)    | 列出运行队列延迟超过给定阈值的进程.|Trace long process scheduling delays. |
|79 | shmsnoop    | | |
|80 | slabratetop    | | |
|81 | sofdsnoop    | | |
|82 | [softirqs](#softirqs)    | 软件中断的耗时. | Measure soft IRQ (soft interrupt) event time. Uses Linux eBPF/bcc.|
|83 | solisten    | | |
|84 | sslsniff    | | |
|85 | [stackcount](#stackcount)    | 产生事件的调用栈计数. | Count function calls and their stack traces. Uses Linux eBPF/bcc.|
|86 | statsnoop    | | |
|87 | syncsnoop    | | |
|88 | [syscount](#syscount)    |系统调用计数. | Summarize syscall counts and latencies.|
|89 | tclcalls    | | |
|90 | tclflow    | | |
|91 | tclobjnew    | | |
|92 | tclstat    | | |
|93 | tcpaccept    | | |
|94 | tcpconnect    | | |
|95 | tcpconnlat    | | |
|96 | tcpdrop    | | |
|97 | tcplife    | | |
|98 | tcpretrans    | | |
|99 | tcpstates    | | |
|100 | tcpsubnet    | | |
|101 | tcptop    | | |
|102 | tcptracer    | | |
|103 | [tplist](#tplist)    | 展示内核跟踪点或USDT探针及其格式. | Display kernel tracepoints or USDT probes and their formats.|
|104 | [trace](#trace)    | 多种源(kprobes, uprobes, tracepoints, USDT probes)的每事件跟踪. | Trace a function and print its arguments or return value, optionally evaluating a filter. Uses Linux eBPF/bcc. |
|105 | ttysnoop    | | |
|106 | vfscount    | | |
|107 | vfsstat    | | |
|108 | wakeuptime    | | |
|109 | xfsdist    | | |
|110 | xfsslower    | | |
|111 | zfsdist    | | |
|112 | zfsslower     | | |

### 1 所有层

#### tplist

```
$ tplist -v syscalls:sys_enter_read
syscalls:sys_enter_read
    int __syscall_nr;
    unsigned int fd;
    char * buf;
    size_t count;

```

#### trace

```
trace [options] probe [probe ...]
```

`probe`:

```
eventname(signature) (boolean filter) "format string", arguments
```

`eventname`:

- `name`, `p:name`: 探查内核函数`name()`
<br>`r::name`: 探查内核函数`name()`的返回
- `lib:name`, `p:lib:name`: 探查库`lib`中用户层的函数`name()`
<br>`r:lib:name`: 探查库`lib`中用户层的函数`name()`的返回值
- `path:name`: 探查路径`path`下用户层函数`name()`
<br>`r:path:name`: 探查路径`path`下用户层函数`name()`的返回值
- `t:system:name`: 探查跟踪点`system:name`
- `u:lib:name`: 探查库`lib`中名称为`name`的USDT探针
- `*`: 通配符. 选项`-r`允许使用正则表达式.


The `format string` is based on `printf()`.

```
## fs/open.c
trace 'do_sys_open "%s", arg2'
trace 'r::do_sys_open "ret: %d", retval'

## kernel/time/hrtimer.c
trace -U 'do_nanosleep "mode: %d", arg2'
trace 'do_nanosleep(struct hrtimer_sleeper *t) "task: %x", t->task'

## pam lib
trace 'pam:pam_start "%s: %s", arg1, arg2'

## trace structs
trace 'do_nanosleep(struct hrtimer_sleeper *t) "task: %x", t->task'
trace -I 'net/sock.h' 'udpv6_sendmsg(struct sock *sk) (sk->sk_dport == 13568)'
```


#### argdist

```
argdist {-C|-H} [options] probe
```

- `-C`: frequency count
- `-H`: power-of-two histogram

`probe`:

```
eventname(signature) [ :type[,type...] :expr[,expr...] [:filter] ] [#label]
```

- `eventname`, `signature`: 同[eventname](#trace), 但不支持内核函数的简写
- `type`: 汇总的值的类型
- `expr`: 汇总的表达式; 特殊的变量: `$retval`、`$latency`、`$entry(param)`
- `filter`: 可选的过滤事件的布尔表达式
- `label`: 可选的添加到输出的标记性文本

```
## 内核函数vfs_read()的返回值的直方图
argdist -H 'r::vfs_read()'
## 进程1005中用户级libc中read()的返回值的直方图
argdist -p 1005 -H 'r:c:read()' # PID=1005
## 按系统调用ID计数
argdist -C 't:raw_syscalls:sys_enter():int:args->id'
## tcp_sendmsg(...)中size参数的计数
argdist -C 'p::tcp_sendmsg(struct sock *sk, struct msghdr *msg, size_t size):u32:size'
argdist -H 'p::tcp_sendmsg(struct sock *sk, struct msghdr *msg, size_t size):u32:size'
## 进程181中libc的write(...)中fd参数的计数
argdist -p 181 -C 'p:c:write(int fd):int:fd'
## 延迟>0.1ms的进程的频率
argdist -C 'r::__vfs_read():u32:$PID:$lantency > 100000'
```

#### funccount

```
funccount [options] eventname
```

`eventname`:

- `name`, `p:name`: 探查内核函数`name()`
- `lib:name`, `p:lib:name`: 探查库`lib`中用户层的函数`name()`
- `path:name`: 探查路径`path`下用户层函数`name()`
- `t:system:name`: 探查跟踪点`system:name`
- `u:lib:name`: 探查库`lib`中名称为`name`的USDT探针
- `*`: 通配符. 选项`-r`允许使用正则表达式.

```
funccount 'tcp_*'
funccount -i 1 'tcp_send*'
funccount -i 1 't:block:*'
funccount -i 1 t:sched:sched_process_fork
funccount -i 1 c:getaddrinfo
funccount 'go:os.*'
```

```
$ bpftrace -e 'k:tcp_* { @[probe] = count(); }'
Attaching 333 probes...
^C

@[kprobe:tcp_recv_timestamp]: 1
@[kprobe:tcp_write_xmit]: 1
@[kprobe:tcp_init_cwnd]: 1
@[kprobe:tcp_rate_skb_delivered]: 1
@[kprobe:tcp_wfree]: 1
......
```

#### funcslower
#### funclatency
#### stackcount

```
stackcount [options] eventname
```

`eventname` see [eventname](#funccount)


```
stackcount t:block:block_rq_insert
stackcount ip_output
statckcount t:sched:sched_switch
stackcount t:syscalls:sys_enter_read
```

#### profile

```
# -a: include kernel annotation
# -f: output in folded format
profile -af 30 > profile.output
# 生成火焰图
flamegraph.pl --color=java < profile.output > profile.svg
```


### 2 应用

传统工具: 系统调试器.

#### ucalls
#### uflow
#### uobjnew
#### ustat
#### uthreads
#### ugc
#### mysqld_qslower
#### dbstat
#### dbslower
#### bashreadline
#### mysqld_clat
#### bashfunc
#### bashfunclat

### 3 运行时

传统工具: 运行时调试器.

#### javathreads
#### jnistacks

### 4 系统库

传统工具: ltrace(1).

#### gethostlatency
#### memleak
#### sslsniff
#### threadssnoop
#### pmlock
#### pmheld

### 5 系统调用接口

传统工具: strace(1), perf(1).

#### scread
#### opensnoop

```
## 跟踪所有open()系统调用
opensnoop
## 跟踪10内的所有open()系统调用
opensnoop -d 10
```

字段:

- TIME(s): Time of the call, in seconds.
- UID: User ID
- PID: Process ID
- TID: Thread ID
- COMM: Process name
- FD: File descriptor (if success), or -1 (if failed)
- ERR: Error number (see the system's errno.h)
- FLAGS: Flags passed to open(2), in octal
- PATH: Open path

#### statsnoop
#### syncsnoop
#### ioprofile
#### syscount

```
# 每秒的系统调用计数: top10
$ syscount -i 1
Tracing syscalls, printing top 10... Ctrl+C to quit.
[09:22:36]
SYSCALL                   COUNT
rt_sigprocmask               24
bpf                          13
select                       13
write                         9
read                          7
getpid                        6
futex                         3
gettid                        2
epoll_wait                    2
ioctl                         2

[09:22:37]
SYSCALL                   COUNT
rt_sigprocmask               16
bpf                          11
select                        9
write                         6
getpid                        4
read                          4
futex                         3
clock_nanosleep               1
```

```
$ bpftrace -e 't:syscalls:sys_enter_* { @[probe] = count(); }'
Attaching 332 probes...
^C

@[tracepoint:syscalls:sys_enter_prctl]: 1
@[tracepoint:syscalls:sys_enter_epoll_create1]: 1
@[tracepoint:syscalls:sys_enter_bind]: 1
@[tracepoint:syscalls:sys_enter_kill]: 1
@[tracepoint:syscalls:sys_enter_clone]: 1
@[tracepoint:syscalls:sys_enter_sendmmsg]: 1
@[tracepoint:syscalls:sys_enter_socket]: 1
......
```

#### killsnoop
#### shellsnoop
#### signals
#### naptime
#### eperm
#### setuids
#### elfsnoop
#### modsnoop
#### execsnoop

works by tracing the execve(2) system call


#### exitsnoop

```
$ exitsnoop
PCOMM            PID    PPID   TID    AGE(s)  EXIT_CODE
ls               1410   942    1410   0.00    0
tree             1412   942    1412   0.02    0
^C
```

#### pidpersec

### 6 内核

传统工具: Ftrace, perf(1).


#### 6.1 虚拟文件系统(VFS)

##### filetop
##### filelife
##### fileslower
##### vfscount
##### vfsstat
##### filetype
##### fsrwstat
##### vfssize
##### mmapfiles
##### writesync
##### cacheestat
##### cachetop
##### dcstat
##### dcsnoop
##### mountsnoop
##### icstat
##### bufgrow
##### readahead
##### writeback

#### 6.2 文件系统

##### btrfsslower, btrfsdist
##### ext4slower, ext4dist
##### nfsslower, nfsdist
##### xfsslower, xfsdist
##### zfsslower, zfsdist
##### overlayfs

#### 6.3 卷管理器

##### mdflush

#### 6.4 块设备

##### biotop
##### biosnoop
##### biolatency

summarizes block device I/O (disk I/O) as a latency histogram


##### bitesize
##### seeksize
##### biopattern
##### biostacks
##### bioerr
##### issched
##### blkthrot

#### 6.5 Sockets

##### sofdsnoop
##### sockstat
##### sofamily
##### soprotocol
##### sormem
##### soconnect
##### soaccept
##### socketio
##### socksize
##### soconnlat
##### so1stbyte
##### skbdrop
##### skblife

#### 6.6 TCP/UDP

##### tcptop
##### tcplife
##### tcptracer
##### tcpconnect
##### tcpaccept
##### tcpconnlat
##### tcpretrans
##### tcpsubnet
##### tcpdrop
##### tcpstates
##### tcpsynbl
##### tcpwin
##### tcpnagle
##### tcpreset
##### updconnect

#### 6.7 IP

##### ipecn
##### superping
##### qdisc-fq

#### 6.8 调度器

##### cpudist

```
# 运行10秒, 输出一次
$ cpudist 10 1
Tracing on-CPU time... Hit Ctrl-C to end.

     usecs               : count     distribution
         0 -> 1          : 0        |                                        |
         2 -> 3          : 0        |                                        |
         4 -> 7          : 1        |                                        |
         8 -> 15         : 2        |*                                       |
        16 -> 31         : 5        |****                                    |
        32 -> 63         : 0        |                                        |
        64 -> 127        : 5        |****                                    |
       128 -> 255        : 3        |**                                      |
       256 -> 511        : 0        |                                        |
       512 -> 1023       : 2        |*                                       |
      1024 -> 2047       : 0        |                                        |
      2048 -> 4095       : 35       |**********************************      |
      4096 -> 8191       : 28       |***************************             |
      8192 -> 16383      : 12       |***********                             |
     16384 -> 32767      : 36       |***********************************     |
     32768 -> 65535      : 27       |**************************              |
     65536 -> 131071     : 41       |****************************************|
    131072 -> 262143     : 19       |******************                      |
```

##### cpuwalk
##### runqlat

```
# 运行10秒, 输出一次
$ runqlat 10 1
Tracing run queue latency... Hit Ctrl-C to end.

     usecs               : count     distribution
         0 -> 1          : 7        |**                                      |
         2 -> 3          : 43       |*************                           |
         4 -> 7          : 63       |********************                    |
         8 -> 15         : 123      |****************************************|
        16 -> 31         : 56       |******************                      |
        32 -> 63         : 15       |****                                    |
        64 -> 127        : 3        |                                        |
       128 -> 255        : 6        |*                                       |
       256 -> 511        : 4        |*                                       |
       512 -> 1023       : 0        |                                        |
      1024 -> 2047       : 1        |                                        |

```

##### runqlen

```
# 运行10秒, 输出一次
$ runqlen 10 1
Sampling run queue length... Hit Ctrl-C to end.

     runqlen       : count     distribution
        0          : 991      |****************************************|
```

##### runqslower

```
$ runqslower 100
Tracing run queue latency higher than 100 us
TIME     COMM             PID           LAT(us)
09:40:00 b'kworker/u2:2'  1472              156
09:40:00 b'runqslower' 1643              162
09:40:00 b'runqslower' 1643              181
09:40:00 b'runqslower' 1643              400
09:40:01 b'systemd-journal' 1644              121
09:40:01 b'runqslower' 1643              144
09:40:01 b'runqslower' 1643              271
09:40:01 b'runqslower' 1643              151
09:40:01 b'runqslower' 1643              181
09:40:01 b'jbd2/sda2-8'   327               517
09:40:01 b'jbd2/sda2-8'   327               865
09:40:01 b'journal-offline' 1645              896
09:40:01 b'journal-offline' 1644              994
09:40:01 b'sshd'          1039             2033
```

##### cppunclaimed
##### deadlock
##### offcputime

```
# -u     Only trace user threads (no kernel threads).
# -k     Only trace kernel threads (no user threads).
# -U     Show stacks from user space only (no kernel space stacks).
# -K     Show stacks from kernel space only (no user space stacks).
# -f     Print output in folded stack format.

offcputime -fKu 10 > offcputime.output
# 生成火焰图
flamegraph.pl < offcputime.output > offcputime.svg
```

##### wakeuptime
##### offwaketime
##### softirqs

```
$ softirqs 10 1
Tracing soft irq event time... Hit Ctrl-C to end.
^C
SOFTIRQ          TOTAL_usecs
net_tx                     5
rcu                       15
block                    125
net_rx                   294
timer                   1445
```

```
$ bpftrace -e 'tracepoint:irq:softirq_entry { @[args->vec] = count(); }'
Attaching 1 probe...
^C

@[2]: 1
@[4]: 2
@[3]: 5
@[9]: 9
@[1]: 50
```

##### offcpuhist
##### threaded
##### pidnss
##### mlock
##### mheld
##### smpcalls

```
$ bpftrace smpcalls.bt
Attaching 8 probes...
Tracing SMP calls. Hit Ctrl-C to stop.
^C


@time_ns[__cpa_flush_tlb]:
[512, 1K)              1 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|

@time_ns[do_kernel_range_flush]:
[2K, 4K)               1 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|

@time_ns[do_flush_tlb_all]:
[1K, 2K)               1 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|

@time_ns[remote_function]:
[2K, 4K)               1 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
[4K, 8K)               1 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|
```

##### workq

#### 6.9 虚拟内存

##### slabratetop
##### oomkill
##### memleak
##### shmsnoop
##### drssnoop
##### kmem
##### kpages
##### numamove
##### mmapsnoop
##### brkstack
##### faults
##### ffaults
##### fmapfault
##### hfaults
##### vmscan
##### swapin

### 7 硬件

传统工具: perf, sar, /proc计数器.

#### 7.1 网络设备

##### ieee80211scan

#### 7.2 设备驱动器

##### hardirqs

```
$ hardirqs 10 1
Tracing hard irq event time... Hit Ctrl-C to end.
^C
HARDIRQ                    TOTAL_usecs
ata_piix                            98
enp0s3                             254
```

##### criticalstat
##### ttysnoop
##### scsilatency
##### scsiresult
##### nvmelatency

#### 7.3 CPU

##### llcstat

```
# 在虚拟机中无法运行
$ llcstat
perf_event_open failed: No such file or directory
Failed to attach to a hardware event. Is this a virtual machine?
```

##### cpufreq

> NOT WORK ON VIRTUALBOX INSTANCE.

### 8 其他

##### capable
##### xenhyper
##### kvmexits
