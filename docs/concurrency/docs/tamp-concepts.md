# Concepts of The Art of Multiprocessor Programming

## 1. Introduction

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

## Principles

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
    | Peterson Lock\l
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
    | <Lineraizability> Lineraizability\l
    | Copositional Linearizability\l
    | <ProgressConditions>Progress Conditions\l
    | <JMM> Java Memory Model\l
    "]
    c3 -> c3_concepts;

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

## Practice

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

    p2 -> {c7 c8};
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

    c9 [label="Linked Lists"]
    c10 [label="Concurrent Queues"]
    c11 [label="Concurrent Stacks"]
    c12 [label="Counting, Sorting and Distributed Coordination"]
    c13 [label="Concurrent Hashing"]
    c14 [label="Skiplists"]
    c15 [label="Priority Queues"]

    p2 -> {c9 c10 c11 c12 c13 c14 c15};
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
