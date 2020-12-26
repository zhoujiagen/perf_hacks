package com.spike.codesnippet.perfhacks;

import io.jaegertracing.internal.JaegerTracer;
import io.jaegertracing.internal.reporters.InMemoryReporter;
import io.jaegertracing.internal.samplers.ConstSampler;
import io.jaegertracing.spi.Reporter;
import io.jaegertracing.spi.Sampler;
import io.opentracing.Tracer;

// REF: https://github.com/jaegertracing/jaeger-client-java/blob/master/jaeger-core/README.md
public class ExampleJaegerTracer {
    public static void main(String[] args) {
        // from env
        // Tracer tracer = Configuration.fromEnv().getTracer();

        final String serviceName = "service1";
//        Configuration configuration = new Configuration(serviceName)
//                .withTraceId128Bit(true);
//        Tracer tracer = configuration.getTracer();

        // unit test
        Reporter reporter = new InMemoryReporter();
        Sampler sampler = new ConstSampler(true);
        Tracer tracer = new JaegerTracer.Builder(serviceName)
                .withReporter(reporter)
                .withSampler(sampler)
                .build();

        System.out.println(tracer);

        // GlobalTracer.registerIfAbsent(tracer);
    }
}
