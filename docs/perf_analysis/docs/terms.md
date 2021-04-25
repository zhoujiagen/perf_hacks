# Terminology

|term|description|source|
|:---|:---|:---|
|profiling|剖析||
|tracing| event-based recording.||
|snooping| snooping, event dumping, and tracing usually refer to the same thing.||
|sampling| take a subset of measurements to paint a coarse picture of the target.||
|observability| refers to understanding a system through observation, and classifies the tools that accomplish this. These tools includes tracing tools, sampling tools, and tools based on fixed counters. It does not include benchmark tools.||
|dynamic instrumentation| dynamic tracing, insert instrumentation points into live software, in production. kprobes for kernel functions, uprobes for user-level functions.||
|static instrumentation| stable event names are coded into the software and manintained by the developers. tracepoints for kernel, user-level statically defined tracing(USDT) for user-level.||
|instrument| 探查||
|flame-graph|火焰图, 剖析器输出的可视化图.|Brendan Gregg|
|vmstat|系统级别虚拟内存和物理内存的统计.||
|mpstat|CPU的使用情况统计.||
|iostat|磁盘I/O的使用情况统计.||
|netstat|网络接口的统计, TCP/IP栈的统计.||
|sar|监视单一操作系统的工具.|AT&T UNIX|
|ps|显示进程状态.||
|top|将进程按统计数据排序.||
|pmap|进程的内存段和使用统计.||
|tcpdump|网络包跟踪, 使用了libpcap库.||
|blktrace|块I/O跟踪.|Linux|
|perf|Linux性能工具集.|Linux|
|oprofile|Linux系统剖析.|Linux|
|`/proc`|提供内核统计信息的文件系统接口.||
|`/sys`|sysfs文件系统, 为内核统计提供一个基于目录的结构.|Linux|
|strace|基于Linux系统的系统调用跟踪.|Linux|
|DTrace|一个包括了编程语言和工具的观测框架. 通过称为探针的指令点, 可以观察所有用户级和内核级的代码.||
|SystemTap|对用户级和内核级的代码提供静态和动态跟踪能力: 静态探针使用tracepoint, 动态探针使用kprobes, 用户级别的探针使用uprobes.|Linux|
|tracepoint| A tracepoint placed in code provides a hook to call a function (probe) that you can provide at runtime. A tracepoint can be “on” (a probe is connected to it) or “off” (no probe is attached).<br/>Using the Linux Kernel Tracepoints: https://www.kernel.org/doc/html/latest/trace/tracepoints.html ||
|probe| 探针 ||
|event tracing|Tracepoints can be used without creating custom kernel modules to register probe functions using the event tracing infrastructure.<br/>Event Tracing: https://www.kernel.org/doc/html/latest/trace/events.html||
|ftrace|Ftrace is an internal tracer designed to help out developers and designers of systems to find what is going on inside the kernel. It can be used for debugging or analyzing latencies and performance issues that take place outside of user-space.<br/>ftrace - Function Tracer: https://www.kernel.org/doc/html/latest/trace/ftrace.html ||
|Kprobes|Kprobes enables you to dynamically break into any kernel routine and collect debugging and performance information non-disruptively. You can trap at almost any kernel code address, specifying a handler routine to be invoked when the breakpoint is hit.<br/>Kernel Probes (Kprobes): https://www.kernel.org/doc/html/latest/trace/kprobes.html ||
|BPF|Berkeley Packet Filter<br/>BPF Documentation: https://www.kernel.org/doc/html/latest/bpf/index.html ||
|BCC|BPF Compiler Collection. It provides a C programming environment for writing kernel BPF code and other languages for the user-level interface: Python, Lua, and C++.||
|bpftrace|A front end that provides a special-purpose, high-level language for developing BPF tools.||
