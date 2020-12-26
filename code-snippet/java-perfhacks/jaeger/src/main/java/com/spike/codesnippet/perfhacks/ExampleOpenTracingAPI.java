package com.spike.codesnippet.perfhacks;

import com.google.common.collect.Maps;
import io.opentracing.References;
import io.opentracing.Scope;
import io.opentracing.Span;
import io.opentracing.Tracer;
import io.opentracing.log.Fields;
import io.opentracing.tag.Tags;

import java.io.IOException;
import java.util.Map;
import java.util.Random;

// REF: https://github.com/opentracing/opentracing-java
public class ExampleOpenTracingAPI {
    public static void main(String[] args) {
        Tracer tracer = Jaegers.constructFromEnv(ExampleOpenTracingAPI.class.getName());


        ExampleOpenTracingAPI instance = new ExampleOpenTracingAPI();
        //instance.service(tracer);

        instance.exampleInSpecification(tracer);

        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // https://github.com/opentracing/specification/blob/master/specification.md
    public void exampleInSpecification(Tracer tracer) {

        Span spanA = tracer.buildSpan("A").start();
        Span spanB = tracer.buildSpan("B").asChildOf(spanA).start();
        Span spanD = tracer.buildSpan("D").asChildOf(spanB).start();
        Span spanC = tracer.buildSpan("C").asChildOf(spanA).start();
        Span spanE = tracer.buildSpan("E").asChildOf(spanC).start();
        Span spanF = tracer.buildSpan("F").asChildOf(spanC).start();

        Span spanG = tracer.buildSpan("G").addReference(References.FOLLOWS_FROM, spanF.context()).start();
        Span spanH = tracer.buildSpan("H").addReference(References.FOLLOWS_FROM, spanG.context()).start();

        spanH.finish();
        spanG.finish();
        spanF.finish();
        spanE.finish();
        spanC.finish();
        spanD.finish();
        spanB.finish();
        spanA.finish();
    }


    public void service(Tracer tracer) {
        operation1(tracer);
    }

    private void operation1(Tracer tracer) {
        Span span = tracer.buildSpan("operation1").start();
        try (Scope scope = tracer.scopeManager().activate(span)) {
            span.log("operation1 start");
            this.operation2(tracer);
            if (new Random().nextBoolean()) {
                throw new RuntimeException("operation1 failed");
            }
            span.log("operation1 done");
        } catch (Exception e) {
            Tags.ERROR.set(span, true);
            Map<String, Object> error = Maps.newLinkedHashMap();
            error.put(Fields.EVENT, "error");
            error.put(Fields.ERROR_OBJECT, e);
            error.put(Fields.MESSAGE, e.getMessage());
            span.log(error);
        } finally {
            span.finish();
        }
    }

    private void operation2(Tracer tracer) {
        Span span = tracer.buildSpan("operation2").start(); // construct span
        try (Scope scope = tracer.scopeManager().activate(span)) {
            span.log("operation2 start");
            this.operation3(tracer);
            span.log("operation2 done");
        } finally {
            span.finish();
        }
    }

    private void operation3(Tracer tracer) {
        Span span = tracer.scopeManager().activeSpan(); // in span?
        if (span != null) {
            span.log("operation3");
        }
    }
}
