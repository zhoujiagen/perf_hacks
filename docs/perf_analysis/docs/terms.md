# Terminology

|term|description|source|
|:---|:---|:---|
| tracing| event-based recording.||
| snooping| snooping, event dumping, and tracing usually refer to the same thing.||
| sampling| take a subset of measurements to paint a coarse picture of the target.||
| observability| refers to understanding a system through observation, and classifies the tools that accomplish this. These tools includes tracing tools, sampling tools, and tools based on fixed counters. It does not include benchmark tools.||
| dynamic instrumentation| dynamic tracing, insert instrumentation points into live software, in production. kprobes for kernel functions, uprobes for user-level functions.||
| static instrumentation| stable event names are coded into the software and manintained by the developers. tracepoints for kernel, user-level statically defined tracing(USDT) for user-level.||
| instrument| 探查||
| tracepoint| 跟踪点||
| probe| 探针 ||
