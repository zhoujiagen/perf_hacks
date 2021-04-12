# Notes of The Art of Multiprocessor Programming

|#|Title|Progress|Description|
|:---|:---|:---|:---|
|1|Introduction|100%|20210412|
|2|Mutual Exclusion|100%|20210403|
|3|Concurrent Objects|100%|20210404|
|4|Foundations of Shared Memory|100%|20210412|
|5|The Relative Power of Primitive Synchronization Operations|100%|20210412|
|6|Universality of Consensus|100%|20210413|
|7|Spin Locks and Contention|||
|8|Monitors and Blocking Synchronization|||
|9|Linked Lists|||
|10|Concurrent Queues and the ABA Problem|||
|11|Concurrent Stacks and Elimination|||
|12|Counting, Sorting, and Distributed Coordination|||
|13|Concurrent Hashing and Natural Parallelism|||
|14|Skiplists and Balanced Search|||
|15|Priority Queues|||
|16|Futures, Scheduling, and Work Distribution|||
|17|Barriers|||
|18|Transactional Memory|||

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->

## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->

### 1. Introduction

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
#### 2. Mutual Exclusion
<div>
{% dot principles.svg
digraph principles {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    #c2 [label="Mutual Exclusion"]
    c2_concepts [shape=record, label="
    Time\l
    | Critical Section\l
    | LockOne, LockTwo\l
    | Peterson Lock\l
    | Filter Lock\l
    | Bakery Algorithm\l
    | Bounded Timestamp\l
    | Lower Bounds on the Number of Locations\l
    "]
    #c2 -> c2_concepts;    
}
%}
</div>

#### 3. Concurrent Objects

<div>
{% dot principles.svg
digraph principles {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    #c3 [label="Concurrent Objects"]
    c3_concepts [shape=record, label="
    Sequential Objects\l
    | Quiescent Consistency\l
    | Sequential Consistency\l
    | <Lineraizability> Lineraizability\l
    | Copositional Linearizability\l
    | <ProgressConditions>Progress Conditions\l
    | <JMM> Java Memory Model\l
    "]
    #c3 -> c3_concepts;

    Lineraizability [shape=record, label="
    <History> history\l
    | sequential specification for an object\l
    | partial order, total order\l
    | method call precedes\l
    | history is linearizable\l
    | linearizability is compositional\l
    | linearizability is a nonblocking property\l
    "]
    c3_concepts:Lineraizability -> Lineraizability;

    History [shape=record, label="
    subhistory\l
    | extension of history\l
    | complete history\l
    | sequential history\l
    | thread subhistory\l
    | object subhistory\l
    | well formed history\l
    | legal sequential history\l
    "]
    Lineraizability:History -> History;

    ProgressConditions [shape=record, label="
    <WaitFreeMethod> wait-free method\l
    | lock-free method\l
    | <DependentProgressConditions> Dependent Progress Conditions\l
    "]
    c3_concepts:ProgressConditions -> ProgressConditions;

    WaitFreeMethod [shape=record, label="
    bounded wait-free method\l
    | population-oblivious method\l
    "]
    ProgressConditions:WaitFreeMethod -> WaitFreeMethod;

    DependentProgressConditions [shape=record, label="
    operating system guarantees\l
    | deadlock-free method\l
    | starvation-free method\l
    | obstruction-free method\l
    "]
    ProgressConditions:DependentProgressConditions -> DependentProgressConditions;


    JMM [shape=record, label="
    the Fundamental Property of relaxed memory model\l
    | shared memory, thread private working memory\l
    | synchronization events\l
    | Locks\l
    | Synchronizaed Blocks\l
    | Volatile Fields\l
    | Final Fields\l
    "]
    c3_concepts:JMM -> JMM;
}
%}
</div>

#### 4. Foundations of Shared Memory

<div>
{% dot principles.svg
digraph principles {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    #c4 [label="Shared Memory"]
    c4_concepts [shape=record, label="
    Register\l
    | Regular Boolean MRSW Register\l
    | Regular M-Values MRSW Register\l
    | Atomic SRSW Register\l
    | Atomic MRSW Register\l
    | Atomic MRMW Register\l
    | <as> Atomic Snapshot\l
    "]
    #c4 -> c4_concepts;
    AtomicSnapshot [shape=record, label="
    Obstruction-Free Snapshot\l
    | Wait-Free Snapshot\l
    "]
    c4_concepts:as -> AtomicSnapshot;

}
%}
</div>

#### 5. The Relative Power of Primitive Synchronization Operations

<div>
{% dot principles.svg
digraph principles {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    #c5 [label="Primitive Synchronization Operations"]
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
    #c5 -> c5_concepts;
}
%}
</div>

#### 6. Universality of Consensus


<div>
{% dot principles.svg
digraph principles {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    #c6 [label="Universality of Consensus"]
    c6_concepts [shape=record, label="
    Universality\l
    | Lock-Free Universal Construction\l
    | Wait-Free Universal Construction\l
    "]
    #c6 -> c6_concepts;
}
%}
</div>


### Practice

#### 7. Spin Locks and Contention

<div>
{% dot practice1.svg
digraph practice1 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c7 [label="Spin Locks and Contention"]
}
%}
</div>

#### 8. Monitors and Blocking Synchronization

<div>
{% dot practice1.svg
digraph practice1 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c8 [label="Monitors"]
}
%}
</div>

#### 9. Linked Lists

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c9 [label="Linked Lists"]
}
%}
</div>

#### 10. Concurrent Queues and the ABA Problem

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c10 [label="Concurrent Queues"]
}
%}
</div>

#### 11. Concurrent Stacks and Elimination

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c11 [label="Concurrent Stacks"]
}
%}
</div>

#### 12. Counting, Sorting, and Distributed Coordination

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c12 [label="Counting, Sorting and Distributed Coordination"]
}
%}
</div>

#### 13. Concurrent Hashing and Natural Parallelism

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c13 [label="Concurrent Hashing"]
}
%}
</div>

#### 14. Skiplists and Balanced Search

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c14 [label="Skiplists"]
}
%}
</div>

#### 15. Priority Queues

<div>
{% dot practice2.svg
digraph practice2 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c15 [label="Priority Queues"]
}
%}
</div>


#### 16. Futures, Scheduling, and Work Distribution

<div>
{% dot practice3.svg
digraph practice3 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c16 [label="Futures, Scheduling and Work Distribution"]
}
%}
</div>

#### 17. Barriers

<div>
{% dot practice3.svg
digraph practice3 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c17 [label="Barriers"]
}
%}
</div>

#### 18. Transactional Memory

<div>
{% dot practice3.svg
digraph practice3 {
    rankdir=LR;
    splines=spline

    node [shape=tab, width=1, height=0.1];
    edge [];

    c18 [label="Transaction Memory"]
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

如何进行基于属性/不变量的证明?