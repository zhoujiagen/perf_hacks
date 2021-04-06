#### 2. Mutual Exclusion

Reasoning about concurrent computation if mostly reasoning about **time**. Threads share a common time, though not necessarily a common clock.

A thread is a **state matchine**, and its state transitions are called **events**.

Events are **instantaneous**: they occur at a signle instant of time. Events are never simultaneous: distinct events occure at distinct times. We denote the j-th occurrence of an event ai by $a_{i}^{j}$.

One event a **precedes** another event b, written a -> b, if a occures at an earlier time. The precedence relation -> is a total order on events.

Let a0 and a1 be events such that a0 -> a1. An **interval** (a0, a1) is the duration between a0 and a1.

Interval $I_{A}$ = (a0, a1) **precedes** $I_{B}$ = (b0, b1), written $I_{A} \rightarrow I_{B}$ if a1 -> b0.<br/>
Intervals that are unrelated by -> are said to be **concurrent**. We denote the j-th execution of interval $I_{A}$ by $_{A}^{j}$.


**Critical section**: a block of code that can be executed by only one thread at a time.

--8<--
lock
--8<--

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

LockOne

--8<--
lock-one
--8<--

LockOne deadlocks if thread executions are interleaved.

LockTwo

--8<--
lock-two
--8<--

LockTwo deadlocks if one thread runs completely ahead of the other.

The Peterson Lock

--8<--
peterson-lock
--8<--

##### n-thread Solutions

--8<--
filter-lock
--8<--

Split the `lock()` method in to two sections of code:

- a **doorway** section, whose execution interval $D_{A}$ consits of a bounded number of steps; - **bounded wait-free progress property**
- a **waiting** section, whose execution interval $W_{A}$ may take an unbounded number of steps.

Fairness

!!! info "Definition 2.5.1"
    A lock is **first-come-first-serverd** if, whenever, thread A finishes its doorway before thread B starts its doorway, then A cannot be overtaken by B:<br/>
    If $D_{A}^{j} \rightarrow D_{B}^{k}$, then $CS_{A}^{j} \rightarrow CS_{B}^{k}$. for threads A and B and integers j and k.


--8<--
bakery-lock
--8<--

--8<--
timestamp
--8<--

