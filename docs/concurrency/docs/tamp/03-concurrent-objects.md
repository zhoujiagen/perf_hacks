# 3. Concurrent Objects

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

## Formal Definitions

An execution of a concurrent system id modeled by a **history**, a finite sequence of method invocation and response events:

- method invocation $\langle x.m(a*) A \rangle$: object $x$, method name $m$, a sequence of arguments $a*$, thread $A$;
- method response $\langle x:t(r*) A \rangle$: $t$ is $Ok$ or an exception name, a sequence of result values $r*$.

A **subhistory** of a history $H$ is a subsequnce of the events of $H$.

A response **matches** an invocation if they have the same object and thread.

A **method call** in a history $H$ is a pair consisting of an invocation and the next matching response in $H$.

A invocation is **pending** in $H$ if no matching response follows the invocation.

A **extension** of $H$ is a history constructed by appending responses to zero or more pending invocations of $H$.

**complete(H)** is the subsequence of $H$ consisting of all matching invocation and responses.

A history $H$ is **sequential** if the first event of $H$ is an invocation, and each invocation, except possibly the last, is immediately followed by a matching response.

**Thread subhistory $H|A$** of a history $H$ is the subsequence of all events in $H$ whose thread names are $A$.

**Object subhistory $H|x$** of a history $H$ is the subsequence of all events in $H$ whose object names are $x$.

Two history $H$ and $H'$ are **equivalent** if for every thread, $H|A$ = $H'|A$.

A history $H$ is **well formed** if each thread subhistory is sequential.

A **sequential specification for an object** is a set of sequential histories for the object.

A sequential history $H$ is **legal** if each object subhistory is legal for that object.

A **partitial order $\rightarrow$**  on a set $X$ is a relation that is irreflexive and transitive.
A **total order $<$** on $X$ is a patial order such that for all distinct $x$ and $y$ in $X$, either $x < y$ or $y < x$.

Any partial order can be extended to a total order:

!!! info "Fact 3.6.1"
    if $\rightarrow$ is a partial order on $X$, then there exists a total order $<$ on $X$, such that if $x \rightarrow y$ then $x < y$.

A method call $m_{0}$ **precedes** a method call $m_{1}$ in history $H$ if $m_{0}$ finished before $m_{1}$ started: $m_{0}$'s response event occures before $m_{1}$'s invocation event.

- $m_{0} \rightarrow_{H} m_{1}$ if $m_{0}$ precedes $m_{1}$ in $H$;
- $m_{0} \rightarrow_{x} m_{1}$ if $m_{0}$ precedes $m_{1}$ in $H|x$.

!!! info "Definition 3.6.1"
    A history $H$ is **linearizable** if it has an extenstion $H'$ and there is a legal sequential history $S$ such that<br/>
    **L1** $complete(H')$ is equivalent to $S$, and<br/>
    **L2** if method call $m_{0}$ precedes method call $m_{1}$ in $H$, then the same is true in $S$.<br/>

    We refer $S$ as a linearization of $H$.

Linearizability is **compositional**:

!!! info "Theorem 3.6.1"
    $H$ is linearizable if, and only if, for each object $x$, $H|x$ is linearizable.

Linearizablility is a **nonblocking** property:

!!! info "Theorem 3.6.2"
    Let $inv(m)$ be an invocation of a total method. If $\langle x \; inv \;  P \rangle$ is a pending invocation in a linearizable history $H$, then there exists a response $\langle x \; res \; P \rangle$ such that $H . \langle x \; res \; P \rangle$ is linearizable.


## Progress Conditions

!!! info "wait-free"
    A method is **wait-free** if it guarantees that every call finishes its execution in a finite number of steps. <br/>
    It is **bounded wait-free** if there is a bound on the number of steps a method call can take. <br/>
    A wait-free method whose perfomance does not depend on the number of active threads is call **population-oblivious**.

!!! info "lock-free"
    A method is **lock-free** if it guarantees that infinitely often some method call finishes in a finite number of steps.

### Dependent Progress Conditions

**Dependent progress conditions**: progress occurs only if the underlying platform(the operating system) provides certain guarantees.

> deadlock-free
> 
> starvation-free

A method call executes **in isolation** if no other threads take steps.

!!! info "Definition 3.7.1"
    A method is **obstruction-free** if, from any point after which it executes in isolation, it finishes in a finite number of steps.
