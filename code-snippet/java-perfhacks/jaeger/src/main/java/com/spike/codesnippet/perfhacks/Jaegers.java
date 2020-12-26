package com.spike.codesnippet.perfhacks;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import io.jaegertracing.Configuration;
import io.jaegertracing.internal.JaegerSpan;
import io.jaegertracing.internal.JaegerTracer;
import io.jaegertracing.internal.samplers.ConstSampler;
import io.jaegertracing.spi.Reporter;
import io.jaegertracing.spi.Sampler;
import io.opentracing.Tracer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public abstract class Jaegers {

    public static Tracer constructTracer(final String serviceName) {
        Reporter reporter = new MyLoggingReporter();
        Sampler sampler = new ConstSampler(true);
        return new JaegerTracer.Builder(serviceName)
                .withReporter(reporter)
                .withSampler(sampler)
                .build();
    }

    public static class MyLoggingReporter implements Reporter {
        private final Logger logger;

        public MyLoggingReporter() {
            this(null);
        }

        public MyLoggingReporter(Logger logger) {
            if (logger == null) {
                logger = LoggerFactory.getLogger(this.getClass());
            }
            this.logger = logger;
        }

        @Override
        public void report(JaegerSpan span) {
            ObjectMapper objectMapper = new ObjectMapper();
            objectMapper.configure(SerializationFeature.FAIL_ON_EMPTY_BEANS, false);
            try {
                logger.info("Span reported: {}, \n{}", span, objectMapper.writeValueAsString(span));
            } catch (JsonProcessingException e) {
                e.printStackTrace();
            }
        }

        @Override
        public void close() {
            // nothing to do
        }
    }

    // https://github.com/jaegertracing/jaeger-client-java/blob/master/jaeger-core/README.md#configuration-via-environment
    public static Tracer constructFromEnv(final String serviceName) {

        System.setProperty("JAEGER_SERVICE_NAME", serviceName);
        System.setProperty("JAEGER_AGENT_HOST", "127.0.0.1");
        System.setProperty("JAEGER_AGENT_PORT", "6831");
        System.setProperty("JAEGER_ENDPOINT", "");
        System.setProperty("JAEGER_AUTH_TOKEN", "");
        System.setProperty("JAEGER_USER", "");
        System.setProperty("JAEGER_PASSWORD", "");
        System.setProperty("JAEGER_PROPAGATION", "jaeger");
        System.setProperty("JAEGER_REPORTER_LOG_SPANS", "true");
        System.setProperty("JAEGER_REPORTER_MAX_QUEUE_SIZE", "100");
        System.setProperty("JAEGER_REPORTER_FLUSH_INTERVAL", "100");
        // https://www.jaegertracing.io/docs/1.21/sampling/#client-sampling-configuration
        System.setProperty("JAEGER_SAMPLER_TYPE", "const");
        System.setProperty("JAEGER_SAMPLER_PARAM", "1");
        System.setProperty("JAEGER_SAMPLER_MANAGER_HOST_PORT", "");
        System.setProperty("JAEGER_TAGS", "serviceName=${JAEGER_SERVICE_NAME:unknown}");

        return Configuration.fromEnv().getTracer();
    }
}
