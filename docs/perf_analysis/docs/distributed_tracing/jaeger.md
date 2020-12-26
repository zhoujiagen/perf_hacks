# Jaeger

> Jaeger: open source, end-to-end distributed tracing
>> Monitor and troubleshoot transactions in complex distributed systems

组件[^1]:

- jaeger-client: OpenTracing API的特定语言实现. Java语言客户端的实现可以参考`code-snippet/java-perfhacks/jaeger`.
- jaeger-agent: 监听client通过UDP发送的Span的网络守护进程, 批量发送给collector.
- jaeger-colloector: 接收agent发送的trace, 在处理管道中处理, 包括: 验证、索引、转换和存储(支持Cassandra、Elasticsearch和Kafka).
- jaeger-query: 从存储检索trace, 使用UI展示.
- jaeger-ingester: 从Kafka主题中读取并写入存储后端(Cassandra、Elasticsearch).

部署[^2]:

- all-in-one方式.
- 可扩展的分布式系统方式: collector直接写入存储或者写入作为缓冲区的Kafka.




[^1]: Architecture: https://www.jaegertracing.io/docs/1.21/architecture/
[^2]: Deployment: https://www.jaegertracing.io/docs/1.21/deployment/
