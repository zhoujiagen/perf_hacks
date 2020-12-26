package com.spike.codesnippet.perfhacks;

import com.google.common.base.Joiner;
import com.google.common.collect.Maps;
import io.opentracing.Scope;
import io.opentracing.Span;
import io.opentracing.SpanContext;
import io.opentracing.Tracer;
import io.opentracing.propagation.Format;
import io.opentracing.propagation.TextMap;

import java.io.IOException;
import java.util.Date;
import java.util.Iterator;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * REF: https://opentracing.io/guides/java/inject-extract/
 *
 * @see io.opentracing.Tracer#inject(SpanContext, Format, Object)
 * @see io.opentracing.Tracer#extract(Format, Object)
 */
public class ExampleOpenTracingAPIInjectExtract {

    // format: TEXT_MAP, BINARY, HTTP_HEADERS
    public static void main(String[] args) {
        ExampleOpenTracingAPIInjectExtract instance = new ExampleOpenTracingAPIInjectExtract();
        instance.service();

        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void service() {
        Tracer clientTracer = Jaegers.constructTracer(Client.class.getName());
        Tracer serverTracer = Jaegers.constructTracer(Server.class.getName());

        Server server = new Server(serverTracer);
        Client client = new Client(clientTracer, server);

        client.work();
    }

    public static class Client {
        private final Tracer tracer;
        private final Server server;
        private final AtomicInteger seq = new AtomicInteger(1);

        public Client(Tracer tracer, Server server) {
            this.tracer = tracer;
            this.server = server;
        }

        public void work() {
            Span span = tracer.buildSpan("work").start();
            try (Scope scope = tracer.scopeManager().activate(span)) {
                span.log("work start");
                this.doWork(span);
                span.log("work done");
            } finally {
                span.finish();
            }
        }

        private void doWork(Span span) {
            final Invocation invocation = new Invocation();
            invocation.addContext("startTime", String.valueOf(new Date().getTime()));
            invocation.addContext("seq", String.valueOf(seq.getAndIncrement()));

            // inject
            tracer.inject(span.context(), Format.Builtin.TEXT_MAP, new TextMap() {
                @Override
                public Iterator<Map.Entry<String, String>> iterator() {
                    throw new UnsupportedOperationException("write-only");
                }

                @Override
                public void put(String key, String value) {
                    invocation.addContext(key, value);
                }
            });

            // call server
            server.work(invocation);
            try {
                Thread.sleep(200L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    // mock data from client to service
    // for http, rpc: it's the link data
    public static class Invocation {
        private static final Map<String, String> context = Maps.newHashMap();

        public void addContext(String key, String value) {
            context.put(key, value);
        }

        public Map<String, String> getContext() {
            return context;
        }
    }


    public static class Server {
        private final Tracer tracer;

        public Server(Tracer tracer) {
            this.tracer = tracer;
        }

        public void work(final Invocation invocation) {
            Tracer.SpanBuilder spanBuilder = tracer.buildSpan("work");

            // extract
            SpanContext spanContext = tracer.extract(Format.Builtin.TEXT_MAP, new TextMap() {
                @Override
                public Iterator<Map.Entry<String, String>> iterator() {
                    return invocation.getContext().entrySet().iterator();
                }

                @Override
                public void put(String key, String value) {
                    throw new UnsupportedOperationException("read-only");
                }
            });

            if (spanContext != null) {
                System.out.printf("SpanContext: trace id=%s, span id=%s, items=%s\n",
                        spanContext.toTraceId(), spanContext.toSpanId(), Joiner.on(" ").join(spanContext.baggageItems()));
                spanBuilder.asChildOf(spanContext);
            }


            Span span = spanBuilder.start();
            try (Scope scope = tracer.scopeManager().activate(span)) {
                span.log("work start");
                this.doWork();
                span.log("work done");
            } finally {
                span.finish();
            }
        }

        private void doWork() {
            try {
                Thread.sleep(100L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}
