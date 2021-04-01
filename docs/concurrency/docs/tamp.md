# Notes of The Art of Multiprocessor Programming


|时间|内容|
|:---|:---|
|20210401|kick off.|

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->

## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->

### Introduction

<div>
{% dot introduction.svg
digraph introduction {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];
    
    root [style=invis]
    
    c1 [label="Introduction"]
    c1_concepts [shape=record, label="
    A Fable\l
    | Producer-Consumer\l
    | Reader-Writer\l
    "]
    c1 -> c1_concepts;
}
%}
</div>

### Principles

<div>
{% dot principles.svg
digraph principles {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];
    
    p1 [label="Principles"]
    c2 [label="Mutual Exclusion"]
    c2_concepts [shape=record, label="
    Time\l
    | Critical Section\l
    | LockOne, LockTwo\l
    | Filter Lock\l
    | Bakery Algorithm\l
    | Bounded Timestamp\l
    | Lower Bounds on the Number of Locations\l
    "]
    c2 -> c2_concepts;    

    c3 [label="Concurrent Objects"]
    c3_concepts [shape=record, label="
    Sequential Objects\l
    | Quiescent Consistency\l
    | Sequential Consistency\l
    | Lineraizability\l
    | Copositional Linearizability\l
    | Progress Conditions\l
    | <JMM> Java Memory Model\l
    "]
    c3 -> c3_concepts;
    JMM [shape=record, label="
    Locks\l
    | Synchronizaed Blocks\l
    | Volatile Fields\l
    | Final Fields\l
    "]
    c3_concepts:JMM -> JMM;

    c4 [label="Shared Memory"]
    c4_concepts [shape=record, label="
    Register\l
    | Regular Boolean MRSW Register\l
    | Regular M-Values MRSW Register\l
    | Atomic SRSW Register\l
    | Atomic MRSW Register\l
    | Atomic MRMW Register\l
    | <as> Atomic Snapshot\l
    "]
    c4 -> c4_concepts;
    AtomicSnapshot [shape=record, label="
    Obstruction-Free Snapshot\l
    | Wait-Free Snapshot\l
    "]
    c4_concepts:as -> AtomicSnapshot;

    c5 [label="Primitive Synchronization Operations"]
    c5_concepts [shape=record, label="
    Consensus Numbers\l
    | Atomic Registers\l
    | Consensus Protocols\l
    | FIFO Queues\l
    | Multiple Assignment Objects\l
    | Read-Modify-Write Operations\l
    | Common2 RMW Operations\l
    | compareAndSet()\l
    "]
    c5 -> c5_concepts;
    
    c6 [label="Universality of Consensus"]
    c6_concepts [shape=record, label="
    Universality\l
    | Lock-Free Universal Construction\l
    | Wait-Free Universal Construction\l
    "]
    c6 -> c6_concepts;
    
    p1 -> {c2 c3 c4 c5 c6};
}
%}
</div>

#### Concurrent Objects

**Method call** the interval that starts with an invocation event and ends with a response event.

Method call is **pending** if its call event has occurred, but not its response event.

An object is **quiescent** if it has no pending method calls.

!!! info "Principle 3.3.1"
    Method calls should appear to happen in a one-at-a-time sequential order.

!!! info "Principle 3.3.2"
    Method calls separated by a period of quiescence should appear to take effect in their real-time order.

!!! info "Principle 3.4.1"
    Method calls should appear to take effect in program order.

!!! info "Principle 3.5.1"
    Each method call should appear to take effect instantaneously at some moment between its invocation and response.

**Quiescent Consistency**: **Principle 3.3.1**, **Principle 3.3.2**.

**Sequntial Consistency**: **Principle 3.3.1**, **Principle 3.4.1**.

**Linearizability**: **Principle 3.5.1**.


### Practice

<div>
{% dot practice1.svg
digraph practice1 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];
    
    p2 [label="Practice"]

    c7 [label="Spin Locks and Contention"]
    c8 [label="Monitors"]
    c9 [label="Linked Lists"]
    
    p2 -> {c7 c8 c9};
}
%}
</div>

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];
    
    p2 [label="Practice"]
    
    c10 [label="Concurrent Queues"]
    c11 [label="Concurrent Stacks"]
    c12 [label="Counting, Sorting and Distributed Coordination"]
    c13 [label="Concurrent Hashing"]
    c14 [label="Skiplists"]
    c15 [label="Priority Queues"]

    p2 -> {c10 c11 c12 c13 c14 c15};
}
%}
</div>

<div>
{% dot practice3.svg
digraph practice3 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];
    
    p2 [label="Practice"]
    
    c16 [label="Futures, Scheduling and Work Distribution"]
    c17 [label="Barriers"]
    c18 [label="Transaction Memory"]

    p2 -> {c16 c17 c18};
}
%}
</div>

## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

Herlihy, M. & Shavit, N. The Art of Multiprocessor Programming. Elsevier, 2012.

## 其他备注
