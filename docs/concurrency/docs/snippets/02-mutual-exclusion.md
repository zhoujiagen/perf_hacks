#### 2. Mutual Exclusion

Reasoning about concurrent computation if mostly reasoning about **time**. Threads share a common time, though not necessarily a common clock.

A thread is a **state matchine**, and its state transitions are called **events**.

Events are **instantaneous**: they occur at a single instant of time. Events are never simultaneous: distinct events occure at distinct times. We denote the $j$-th occurrence of an event ai by $a_{i}^{j}$.

One event $a$ **precedes** another event $b$, written $a \rightarrow b$, if $a$ occures at an earlier time. The precedence relation $\rightarrow$ is a total order on events.

Let $a_{0}$ and $a_{1}$ be events such that $a_{0} \rightarrow a_{1}$. An **interval** $(a_{0}, a_{1})$ is the duration between $a_{0}$ and $a_{1}$.

Interval $I_{A} = (a_{0}, a_{1})$ **precedes** $I_{B} = (b_{0}, b_{1})$, written $I_{A} \rightarrow I_{B}$ if $a_{1} \rightarrow b_{0}$.<br/>
Intervals that are unrelated by $\rightarrow$ are said to be **concurrent**. We denote the $j$-th execution of interval $I_{A}$ by $_{A}^{j}$.


**Critical section**: a block of code that can be executed by only one thread at a time.

--8<--
lock
--8<--

A thread is **well formed** if:

- each critical section is associated with an unique `Lock` object;
- the thread calls that object's `lock()` method when it is trying to enter the critical section, and
- the thread calls the `unlock()` method when it leaves the critical section.

**Mutal Exclusion** Critical section of different threads do not overlap. <br/>
For thread $A$ and $B$, and integer $j$ and $k$, either $CS_{A}^{k} \rightarrow CS_{B}^{j}$ or $CS_{B}^{j} \rightarrow CS_{A}^{k}$.

**Freedom from Deadlock** If some thread attempts to acquire the lock, them some thread will succeed in acquiring the lock. <br/>
If thread $A$ calls `lock()` but never acquires the lock, then other threads must be completing an infinite number of critial sections.<br/>
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
    A lock is **first-come-first-served** if, whenever, thread $A$ finishes its doorway before thread $B$ starts its doorway, then $A$ cannot be overtaken by $B$:<br/>
    If $D_{A}^{j} \rightarrow D_{B}^{k}$, then $CS_{A}^{j} \rightarrow CS_{B}^{k}$. for threads $A$ and $B$ and integers $j$ and $k$.


--8<--
bakery-lock
--8<--

--8<--
timestamp
--8<--

##### Lower Bounds on the Number of Locations

An **object's state** is the state of its fields. <br/>
A **thread's local state** is the state of its program counters and local variables.<br/>
A **global state** or **system state** is the state of all objects, plus the local states of the threads.

!!! info "Definition 2.8.1"
    A `Lock` object state s is **inconsistent** in any global state where some thread is in the critical section, but the lock state is compatible with a global state in which no thread is in the critical section or is trying to enter the critical section.

!!! info "Lemma 2.8.1"
    No deadlock-free Lock algorithm can enter an inconsistent state.

!!! info "Definition 2.8.2"
    A **covering state** for a `Lock` object is one in which there is at least one thread about to write to each shared location, but the `Lock` object's locations "look" like the critical section is empty.<br/>
    In this state, we say that each threads covers the location it is about to write.

!!! info "Theorem 2.8.1"
    Any `Lock` algorithm that, by reading and writing memory, solves deadlock-free mutual exclusion for **three** threads, must use at least **three** distinct memory locations.

