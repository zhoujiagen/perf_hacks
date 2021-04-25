# 虚拟化性能分析

## 分析目标

### 容器

- 每个容器的运行队列延迟
- 调度器是否在同一个CPU上切换容器
- 是否遇到CPU或磁盘的软限制

### Hypervisor

- 虚拟化硬件资源的性能如何
- 如果使用了半虚拟化(paravirtualization), hypercall的延迟是多少
- 被偷的CPU时间的频率和持续时间
- hypervisor中断回调是否影响应用
