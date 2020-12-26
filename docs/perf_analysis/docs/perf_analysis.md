# Performacnce Analysis

## 资源

- Brendan Gregg. Systems performance : enterprise and the cloud. 2013.


## Linux 60-Second Analysis

|#|步骤|说明|描述|
|-|---|:---|:---|
|1|`uptime`| 查看平均负载. |Tell how long the system has been running |
|2| `dmesg | tail` | 查看最后几条系统消息. |print or control the kernel ring buffer|
|3|`vmstat 1`| 每秒输出虚拟内存统计信息. |Report virtual memory statistics|
|4|`mpstat -P ALL 1`| 查看每个CPU的统计时间. |Report processors related statistics |
|5|`pidstat 1`| 查看每个进程的CPU使用情况. |Report statistics for Linux tasks|
|6|`iostat -xz 1`| 查看存储设备I/O情况. |Report Central Processing Unit (CPU) statistics and input/output statistics for devices and partitions|
|7|`free -m`| 查看可用内存. |Display amount of free and used memory in the system|
|8|`sar -n DEV 1`| 查看网络设备情况. |Collect, report, or save system activity information|
|9|`sar -n TCP,ETCP 1`| 查看TCP情况. |同上 |
|10|`top`| 查看系统和进程汇总信息. |display Linux processes|


`sysstat`:

```
$ sudo apt install sysstat
$ apt info sysstat
Description: system performance tools for Linux
 The sysstat package contains the following system performance tools:
  - sar: collects and reports system activity information;
  - iostat: reports CPU utilization and disk I/O statistics;
  - tapestat: reports statistics for tapes connected to the system;
  - mpstat: reports global and per-processor statistics;
  - pidstat: reports statistics for Linux tasks (processes);
  - sadf: displays data collected by sar in various formats;
  - cifsiostat: reports I/O statistics for CIFS filesystems.
```

## BCC Tool Checklist

|#|步骤|说明|描述|
|-|---|:---|:---|
|1|`execsnoop`|输出系统调用`execve(2)`创建的新进程.|Trace new processes via exec() syscalls. Uses Linux eBPF/bcc.|
|2|`opensnoop`|输出系统调用`open(2)`及其变种的调用情况.|Trace open() syscalls. Uses Linux eBPF/bcc.|
|3|`ext4slower`<br>`btrfsslower`<br>`xfsslower`<br>`zfsslower`| 查看文件系统中慢的磁盘I/O.|Trace slow ext4/btrfs/xfs/zfs file operations, with per-event details.|
|4|`biolatency`|以直方图形式输出磁盘I/O延迟.|Summarize block device I/O latency as a histogram.|
|5|`biosnoop`|输出每个磁盘I/O详情及其延迟.|Trace block device I/O and print details incl. issuing PID.|
|6|`cachestat`|每秒输出文件系统缓存的统计信息.|Statistics for linux page cache hit/miss ratios. Uses Linux eBPF/bcc.|
|7|`tcpconnect`|输出主动TCP连接的信息.|Trace TCP active connections (connect()). Uses Linux eBPF/bcc.|
|8|`tcpaccept`|输出被动TCP连接信息.|Trace TCP passive connections (accept()). Uses Linux eBPF/bcc.|
|9|`tcpretrans`|输出每个TCP重传报文.|Trace or count TCP retransmits and TLPs. Uses Linux eBPF/bcc.|
|10|`runqlat`|以直方图形式输出线程等待CPU的时间.|Run queue (scheduler) latency as a histogram.|
|11|`profile`|CPU探查器, 用于理解消耗CPU资源的代码路径.|Profile CPU usage by sampling stack traces. Uses Linux eBPF/bcc.|


## 分析目标

### CPU

- 各进程的CPU利用率
- 上下文切换频率
- 运行队列长度
- 创建了哪些新进程, 它们的存活时间
- 为什么系统时间比较长, 是哪些系统调用造成的, 它们在做什么事情
- 每次唤醒后线程on-CPU的时间
- 线程在运行队列中等待的时间
- 运行队列的最大长度
- 运行队列在CPU间是否是平衡的
- 为什么线程自愿离开CPU, 离开多长时间
- 哪些软/硬IRQ在消耗CPU
- 当其它CPU的运行队列中有工作时, 是否有空闲的CPU
- 应用请求的LLC(last-level cache)命中率

### 内存

- 物理内存和虚拟内存的使用情况
- 页操作的频率
- 为什么进程的物理内存(RSS)在持续增长
- 哪些代码路径导致页错误, 是哪个文件
- 哪些进程在阻塞等待换入
- 系统创建了哪些内存映射
- 发生OOM杀死进程时的系统状态
- 哪些应用代码路径在分配内存
- 应用分配的对象的类型
- 是否有内存分配一段时间后没有释放(指示出内存泄漏)

### 文件系统

- 有哪些类型的文件系统请求, 各类型有多少次请求
- 读操作的字节数
- 异步写操作的数量
- 文件负载的访问模式: 随机的还是顺序的
- 访问了哪些文件, 被哪些进程或代码路径访问, 访问的字节数和访问次数
- 发生了哪些文件系统错误, 各类型有多少次, 是由哪些进程产生的
- 文件系统延迟的原因: 是磁盘, 代码路径还是锁
- 文件系统延迟的分布
- 数据缓存、指令缓存的命中率、未命中率
- 读操作的页缓存命中率
- 预取或预读是否有效, 是否需要调整

### 磁盘I/O

- 各进程的IOPS、平均延迟、队列长度
- 有哪些I/O请求, I/O的大小
- 请求时间、队列中时间
- 有哪些比较大的延迟
- 延迟分布是否是多模态的
- 是否有磁盘错误
- 发送了哪些SCSI指令
- 是否有超时

### 网络

- 发生了哪些socket I/O, 为什么会发生, 用户层栈是什么
- 哪些进程创建了新的TCP会话
- 是否发生socket、TCP或IP层错误
- TCP窗口大小, 是否有零大小传输
- 不同栈层的I/O大小
- 网络栈是否丢弃了报文, 为什么丢弃
- TCP连接中的延迟: 第一个字节的延迟, 整个存活期间的延迟
- 内核的网络栈内部的延迟
- 报文在qdisc队列中、网络驱动器队列中的时间
- 使用了哪些高层协议

### 安全

- 有哪些进程在执行
- 哪些进程建立了哪些网络连接
- 进程请求了哪些系统权限
- 系统中是否出现了权限拒绝错误
- 内核/用户函数是否用特定的参数执行

### 语言

- 调用了哪些函数
- 函数使用的实际参数
- 函数的返回值, 是否是错误
- 产生事件的代码路径(栈跟踪)
- 函数消耗的时间

### 应用

- 有哪些应用请求, 请求的延迟
- 处理应用请求的时间消耗在哪里
- 为什么应用on-CPU
- 为什么应用阻塞、切换CPU
- 应用执行了哪些I/O操作, 代码路径是什么
- 应用阻塞在哪些锁上, 阻塞多长时间
- 应用使用了哪些内核资源, 为什么使用

### 内核

- 为什么线程离开CPU, 离开了多长时间
- off-CPU的线程在等待什么事件
- 谁在使用内核SLAB分配器
- NUMA架构下, 内核是否在移动页
- 有哪些工作队列事件, 延迟是多少
- 对内核开发者: 哪些函数被调用, 实际参数和返回值是什么, 延迟是多少

### 容器

- 每个容器的运行队列延迟
- 调度器是否在同一个CPU上切换容器
- 是否遇到CPU或磁盘的软限制

### Hypervisor

- 虚拟化硬件资源的性能如何
- 如果使用了半虚拟化(paravirtualization), hypercall的延迟是多少
- 被偷的CPU时间的频率和持续时间
- hypervisor中断回调是否影响应用
