# Notes of Distributed Tracing


|时间|内容|
|:---|:---|
|20201015|kick off.|
|20201021|TODO: 复习Go, 使用Jaeger.|

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->

distributed tracing: 分布式跟踪; an observability tool to address the challenges of monitoring and troubleshooting distributed systems.

end-to-end tracing<br/>
workflow-centric tracing

trace: 轨迹; 分布式系统中请求被处理的完整路径, 由事件图构成, 节点为事件, 边为事件间的因果关系.

trace point: 代码中编排的跟踪点, 例如客户端代码在Web服务器请求中可以编排两个跟踪点: 发送请求和接收响应.

instrumentation: 编排; 织入.

observability: 可观察性.

service dependency graph: 服务依赖图.

distributed transaction: 处理请求的链.

execution, request: 系统代客户端或请求发起者执行的工作.


## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

了解分布式跟踪解决的问题;
学习分布式跟踪的机制;
掌握分布式跟踪如何在分布式中间件中使用.


## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->

```
Part I Introduction
1 Why Distributed Tracing
2 Taking Tracing for a HotROD ride
3 Distributed Tracing Fundamentals
Part II Data Gathering Problem
4 Instrumentation Basics with OpenTracing
5 Instrumentation of Asynchronous Applications
6 Tracing Standards and Ecosystem
7 Tracing with Service Mesh
8 All About Sampling
Part III Getting Value from Tracing
9 Turning the Lights On
10 Distributed Context Propagation
11 Integration with Metrics and Logs
12 Gathering Insights Through Data Mining
Part IV Deploying and Operating Tracing Infrastructure
13 Implementing tracing in large organizations
14 Under the Hood of a Distributed Tracing System
```

### 1 分布式跟踪解决什么问题

分布式组件在处理请求的协同流程中上下文信息和处理顺序信息的可观察性问题.


### 2 分布式跟踪的工作机制

分布式跟踪是以请求为核心的, 捕捉分布式系统组件在处理请求的过程中执行的因果相关活动的详细信息.

- (1) 跟踪基础设施在每个请求上附加上下文元数据(contextual metadata), 确保元数据会随请求的执行传递;
- (2) 在代码中的跟踪点(trace point), 记录标记了相关信息的事件(event), 这些信息包括HTTP请求的URL、数据库查询的SQL语句等;
- (3) 记录的事件标记有上下文元数据和与之前的事件的显式因果联系(causality reference).

anatomy of distributed tracing


- Execution Flow: 执行流
- Causality, profiling data: 因果性, 测量数据
- Trace points: 跟踪点
- Inject/Extract Trace points: 注入/提取跟踪点. 跨进程传递的元数据的编解码

- Req: 请求
- Res: 响应
- Microservice-N: 微服务实例
- Tracing API: 跟踪API
- Tracing library: 跟踪库是跟踪API的实现, 将收集的数据报告给跟踪后端
- Collection/Normalization(Trace Model): 跟踪后端接收到跟踪数据, 将其按通用的跟踪模型表示来标准化, 并存储到跟踪存储中
- Trace Storage: 跟踪数据的存储
- Trace Reconstruction: 重构轨迹
- Data Mining: 跟踪数据的聚合和数据挖掘
- Presentation, Visualization: 轨迹的表示和可视化

- 因果性关系: Lamport的happens-before关系


### 3 运用分布式跟踪

OpenTracing项目

解决的问题: 提供厂商独立的API和常见框架的编排织入库.

两个主要实体:

- tracer: 负责创建span, 暴露出跨进程和组件边界传递上下文信息的方法的单例.
- span: 实现应用中特定跟踪点的接口. 在span模型上下文中, span表示应用在一次分布式执行中的工作单元, 这个工作单元的名称称为操作名称(operation name). 每个span有开始和结束时间, 大多数情况下还包含在一次执行中到其前继的因果连接.


## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

- Yuri Shkuro. Mastering Distributed Tracing. Packt Publishing, 2019.
- The OpenTracing Semantic Specification: https://opentracing.io/specification/
- OpenTracing API for Go: https://github.com/opentracing/opentracing-go
- Jaeger: open source, end-to-end distributed tracing: https://www.jaegertracing.io/

## 其他备注
