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

### 1. Introduction

### Principles

#### 2. Mutual Exclusion

Reasoning about concurrent computation if mostly reasoning about **time**. Threads share a common time, though not necessarily a common clock.

A thread is a **state matchine**, and its state transitions are called **events**.

Events are **instantaneous**: they occur at a signle instant of time. Events are never simultaneous: distinct events occure at distinct times. We denote the j-th occurrence of an event ai by $a_{i}^{j}$.

One event a **precedes** another event b, written a -> b, if a occures at an earlier time. The precedence relation -> is a total order on events.

Let a0 and a1 be events such that a0 -> a1. An **interval** (a0, a1) is the duration between a0 and a1.

Interval $I_{A}$ = (a0, a1) **precedes** $I_{B}$ = (b0, b1), written $I_{A} \rightarrow I_{B}$ if a1 -> b0.<br/>
Intervals that are unrelated by -> are said to be **concurrent**. We denote the j-th execution of interval $I_{A}$ by $_{A}^{j}$.


**Critical section**: a block of code that can be executed by only one thread at a time.

``` java
public interface Lock {
    public void lock();     // before entering critical section
    public void unlock();   // before leaving critical section
}
```

A thread is **well formed** if:

- each critical section is associated with an unique `Lock` object;
- the thread calls that object's `lock()` method when it is trying to enter the critical section, and
- the thread calls the `unlock()` method when it leaves the critical section.

**Mutal Exclusion** Critical section of different threads do not overlap. <br/>
For thread A and B, and integer j and k, either $CS_{A}^{k} \rightarrow CS_{B}^{j}$ or $CS_{B}^{j} \rightarrow CS_{A}^{k}$.

**Freedom from Deadlock** If some thread attempts to acquire the lock, them some thread will succeed in acquiring the lock. <br/>
If thread A calls `lock()` but never acquires the lock, then other threads must be completing an infinite number of critial sections.<br/>
It implies that the system never freezes.

**Freedom from Starvation/Lockout Freedom** Every thread that attempts to acquire the lock eventually succeeds.<br/>
Every call to `lock()` eventually returns.

Starvation freedom implies deadlock freedom.

##### 2-Thread Solutions

Conventions:

- the threads has ids 0 and 1;
- each thread acquires its index by calling `ThreadID.get()`.

The Peterson Lock

!!! info "Lemma 2.3.3"
    The Peterson lock algorithm satisfies mutual exclusion.

!!! info "Lemma 2.3.4"
    The Peterson lock algorithm is starvation-free.

!!! info "Corollary 2.3.1"
    The Peterson lock algorithm is deadlock-free.

``` java
class Peterson implements Lock {
    private boolean[] flag = new boolean[2];    // thread interestness
    private int victim;

    public void lock() {
        int me = ThreadID.get();
        int other = 1 - me;
        flag[me] = true;                        // I am interested
        victim = me;                            // you go first
        while (flag[other] && victim == me) {}  // wait
    }

    public void unlock() {
        int me = ThreadID.get();
        flag[me] = false;                       // I am not interested
    }
}
```

The Filter Lock

Lamport's Bakery Algorithm

#### 3. Concurrent Objects

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

##### Formal Definitions

An execution of a concurrent system id modeled by a **history**, a finite sequence of method invocation and response events:

- method invocation <x.m(a*) A>: object x, method name m, a sequence of arguments a\*, thread A;
- method response <x:t(r*) A>: t is Ok or an exception name, a sequence of result values r\*.

A **subhistory** of a history H is a subsequnce of the events of H.

A response **matches** an invocation if they have the same object and thread.

A **method call** in a history H is a pair consisting of an invocation and the next matching response in H.

A invocation is **pending** in H if no matching response follows the invocation.

A **extension** of H is a history constructed by appending responses to zero or more pending invocations of H.

**complete(H)** is the subsequence of H consisting of all matching invocation and responses.

A history H is **sequential** if the first event of H is an invocation, and each invocation, except possibly the last, is immediately followed by a matching response.

**Thread subhistory H|A** of a history H is the subsequence of all events in H whose thread names are A.

**Object subhistory H|x** of a history H is the subsequence of all events in H whose object names are x.

Two history H and H' are **equivalent** if for every thread, H|A = H'|A.

A history H is **well formed** if each thread subhistory is sequential.

A **sequential specification for an object** is a set of sequential histories for the object.

A sequential history H is **legal** if each object subhistory is legal for that object.

A **partitial order ->**  on a set X is a relation that is irreflexive and transitive.
A **total order <** on X is a patial order such that for all distinct x and y in X, either x < y or y < x.

Any partial order can be extended to a total order:

!!! info "Fact 3.6.1"
    if -> is a partial order on X, then there exists a total order < on X, such that if x -> y then x < y.

A method call m0 **precedes** a method call m1 in history H if m0 finished before m1 started: m0's response event occures before m1's invocation event.

- m0 ->H m1 if m0 precedes m1 in H;
- m0 ->x m1 if m0 precedes m1 in H|x.

!!! info "Definition 3.6.1"
    A history H is **linearizable** if it has an extenstion H' and there is a legal sequential history S such that<br/>
    **L1** complete(H') is equivalent to s, and<br/>
    **L2** if method call m0 precedes method call m1 in H, then the same is true is S.<br/>

    We refer S as a linearization of H.

Linearizability is **compositional**:

!!! info "Theorem 3.6.1"
    H is linearizable if, and only if, for each object x, H|x is linearizable.

Linearizablility is a **nonblocking** property:

!!! info "Theorem 3.6.2"
    Let inv(m) be an invocation of a total method. If < x inv P > is a pending invocation in a linearizable history H, then there exists a response < x res P > such that H . < x res P > is linearizable.


##### Progress Conditions

A method is **wait-free** if it guarantees that every call finishes its execution in a finite number of steps. <br/>
It is **bounded wait-free** if there is a bound on the number of steps a method call can take. <br/>
A wait-free method whose perfomance does not depend on the number of active threads is call **population-oblivious**.

A method is **lock-free** if it guarantees that infinitely often some method call finishes in a finite number of steps.

###### Dependent Progress Conditions

**Dependent progress conditions**: progress occurs only if the underlying platform(the operating system) provides certain guarantees.

> deadlock-free
> starvation-free

A method call executes **in isolation** if no other threads take steps.

!!! info "Definition 3.7.1"
    A method is **obstruction-free** if, from any point after which it executes in isolation, it finishes in a finite number of steps.

#### 4. Foundations of Shared Memory
#### 5. The Relative Power of Primitive Synchronization Operations
#### 6. Universality of Consensus

### Practice

#### 7. Spin Locks and Contention
#### 8. Monitors and Blocking Synchronization

#### 9. Linked Lists
#### 10. Concurrent Queues and the ABA Problem
#### 11. Concurrent Stacks and Elimination
#### 12. Counting, Sorting, and Distributed Coordination
#### 13. Concurrent Hashing and Natural Parallelism
#### 14. Skiplists and Balanced Search
#### 15. Priority Queues

#### 16. Futures, Scheduling, and Work Distribution
#### 17. Barriers
#### 18. Transactional Memory

## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

Herlihy, M. & Shavit, N. The Art of Multiprocessor Programming. Elsevier, 2012.

## 其他备注
