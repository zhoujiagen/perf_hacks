# Performacnce Analysis

## 资源

- Brendan Gregg. Systems performance : enterprise and the cloud. 2013.


## Linux 60-Seconds Analysis

|#|<div style="width: 150px;">步骤</div>|描述|
|:---|:---|:---|
|1|`uptime`| 查看平均负载. <br/>Tell how long the system has been running |
|2| `dmesg | tail` | 查看最后几条系统消息. <br/>print or control the kernel ring buffer|
|3|`vmstat 1`| 每秒输出虚拟内存统计信息. <br/>Report virtual memory statistics|
|4|`mpstat -P ALL 1`| 查看每个CPU的统计时间. <br/>Report processors related statistics |
|5|`pidstat 1`| 查看每个进程的CPU使用情况. <br/>Report statistics for Linux tasks|
|6|`iostat -xz 1`| 查看存储设备I/O情况. <br/>Report Central Processing Unit (CPU) statistics and input/output statistics for devices and partitions|
|7|`free -m`| 查看可用内存. <br/>Display amount of free and used memory in the system|
|8|`sar -n DEV 1`| 查看网络设备情况. <br/>Collect, report, or save system activity information|
|9|`sar -n TCP,ETCP 1`| 查看TCP情况.|
|10|`top`| 查看系统和进程汇总信息. <br/>display Linux processes|

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

|#|<div style="width: 150px;">步骤</div>|描述|
|:---|:---|:---|
|1|`execsnoop`|输出系统调用`execve(2)`创建的新进程.<br/>Trace new processes via exec() syscalls. Uses Linux eBPF/bcc.|
|2|`opensnoop`|输出系统调用`open(2)`及其变种的调用情况.<br/>Trace open() syscalls. Uses Linux eBPF/bcc.|
|3|`ext4slower`<br>`btrfsslower`<br>`xfsslower`<br>`zfsslower`| 查看文件系统中慢的磁盘I/O.<br/>Trace slow ext4/btrfs/xfs/zfs file operations, with per-event details.|
|4|`biolatency`|以直方图形式输出磁盘I/O延迟.<br/>S<br/>ummarize block device I/O latency as a histogram.|
|5|`biosnoop`|输出每个磁盘I/O详情及其延迟.<br/>Trace block device I/O and print details incl. issuing PID.|
|6|`cachestat`|每秒输出文件系统缓存的统计信息.<br/>Statistics for linux page cache hit/miss ratios. Uses Linux eBPF/bcc.|
|7|`tcpconnect`|输出主动TCP连接的信息.<br/>Trace TCP active connections (connect()). Uses Linux eBPF/bcc.|
|8|`tcpaccept`|输出被动TCP连接信息.<br/>Trace TCP passive connections (accept()). Uses Linux eBPF/bcc.|
|9|`tcpretrans`|输出每个TCP重传报文.<br/>Trace or count TCP retransmits and TLPs. Uses Linux eBPF/bcc.|
|10|`runqlat`|以直方图形式输出线程等待CPU的时间.<br/>Run queue (scheduler) latency as a histogram.|
|11|`profile`|CPU探查器, 用于理解消耗CPU资源的代码路径.<br/>Profile CPU usage by sampling stack traces. Uses Linux eBPF/bcc.|

## 方法论

### 循环诊断

```
 --------------------
 |                  ^
 v                  |
假设 -> 仪器检验 -> 数据
```

### USE方法(Utilization, Saturation, Errors)

对所有的资源, 查看它的使用率(utilization)、饱和度(saturation)和错误(errors):

- 使用率: 在给定的时间间隔内, 资源用于服务工作的时间百分比.
- 饱和度: 资源不能再服务更多的额外工作的程度, 通常有等待队列.
- 错误: 错误事件的个数.


### 工作负载特征归纳

通过回答问题:

- 负载是由谁产生的: 进程ID、用户ID、远端的IP地址?
- 负载为什么会被调用: 代码路径、堆栈跟踪?
- 负载的特征是什么: IOPS、吞吐量、方向类型(读取/写入)、包含变动(标准方法)?
- 负载是怎样随时间变化的, 有日常模式吗?

### 延时分析

检查完成一项操作所用的时间, 然后把时间再分成小的时间段, 再对有最大延时的时间段做再次的划分, 最后定位并量化问题的根本原因.

例: MySQL的请求延时分析

1. 存在请求延时问题吗? - 是的
2. 请求时间大量的花在CPU上吗? - 不在CPU上
3. 不花在CPU上的时间在等待什么? - 文件系统I/O
4. 文件系统的I/O时间是花在磁盘I/O还是锁竞争上? - 磁盘I/O
5. 磁盘I/O时间主要是随机寻址的时间还是数据传输的时间? - 数据传输时间


## 建模

### 扩展定律

Amdahl扩展定律: 早期的扩展特性是竞争, 主要是对串行的资源或工作负载的竞争

$$
C(N) = \frac{N}{1} + \alpha (N - 1), 0 \le \alpha \le 1
$$

- $C(N)$: 容量;
- $N$: 扩展的维度, 如CPU数量或用户负载;
- $\alpha$: 系数, 表示串行的程序/偏离线性扩展的程度.

通用扩展定律(Universal Scalability Law):

$$
C(N) = \frac{N}{1} + \alpha (N - 1) + \beta N (N - 1)
$$

- $C(N)$、$N$、$\alpha$: 与Amdahl扩展定律一致;
- $\beta$: 处理延时的一致性系数, 为$0$时该定律变成Amdahl扩展定律.

### 排队理论(Queuing Theory)

用数学方法研究带有队列的系统, 提供了对队列长度、等待时间/延时、基于时间的使用率的分析方法.

Little's定律: 系统请求的平均数量$L$由平均到达率$\lambda$乘以平均服务时间$W$得到

$$
L = \lambda W
$$

排队系统的要素:

- 到达过程$\texttt{A}$: 描述请求到达排队系统的间隔时间, 这个时间间隔可以是随机的、固定的, 或是一个过程, 如泊松分布;
- 服务时间分布$\texttt{S}$: 描述服务中心的服务时间, 可以是确定性分布、指数型分布等;
- 服务中心数量$\texttt{c}$.

Kendall标记法: $\texttt{A/S/c}$, 例:

- $\texttt{M/M/1}$: 马尔科夫指数分布到达, 马尔科夫指数分布服务时间, 一个服务中心;
- $\texttt{M/M/c}$: 与$\texttt{M/M/1}$一样, 但有多个服务中心;
- $\texttt{M/G/1}$: 马尔科夫到达, 一般分布的服务时间, 一个服务中心;
- $\texttt{M/D/1}$: 马尔科夫到达, 固定时间的服务时间, 一个服务中心.
