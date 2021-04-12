# 5. The Relative Power of Primitive Synchronization Operations

> If one thinks of primitive synchronization instructions as objects whose exported methods are the instruction themselves (these objects are referred to as **synchronizaiton primitives**), one can show that there is an infinite hierarchy of synchronization primitives, such that no primitive at one level can be used for a wait-free or lock-free implementation of any primitives at higher level.
> 
> Each class in the hierarchy has an associated **consensus number**, which is the maximum number of threads for which objects of the class can solve an elementary synchronization problem called **consensus**.


## 5.1 Consensus Numbers

A **consensus object** provides a single method `decide()`:

- Each thread calls the `decide()` method with its input at most once;
- The object's `decide()` method will return a value meeting these conditions:<br/>
  **consistent**: all threads decide the same value;<br>
  **valid**: the common decision value is some thread's input.

``` java
public interface Consensus<T> {
    T decide(T value)
}
```

> We focus here on binary consensus.

!!! info "Definition 5.1.1"
    A class $C$ **solves** $n$-thread consensus if there exist a consensus protocol using any number of objects of class $C$ and any number of atomic registers.

!!! info "Definition 5.1.2"
    The **consensus number** of a class $C$ is the largest $n$ for which that class solves $n$-thread consensus. If no largest $n$ exists, we say the consensus number of the class is infinite.

!!! info "Corollary 5.1.1"
    Suppose one can implement an object of class $C$ from one or more objects of class $D$, together with some number of atomic registers. If class $C$ solves $n$-consensus, then so does class $D$.

Each thread makes moves until it decides on a value. Here, a **move** is a method call to a shared object.

A **protocol state** consists of the states of the threads and the shared objects. <br/>
An initial state is a protocol state before any threads has moved.<br/>
A final state is a protocol state after all threads have finished.<br/>
The decision value of any final state is the value decided by all threads in that state.

A wait-free protocol's set of possible states forms a tree, where<br/>
each node represents a possible protocol state, and<br/>
each edge represents a possible move by some tread, and<br/>
leaf nodes represent final protocl state, and are labeled with their decision value.


A protocol state is **bivalent** if the decision value is not ye fixed: there is some execution starting from that state in which the threads decide 0, and one in which they decide 1.

A protocol state is **univalent** if the outcome is fixed: every execution starting from that state decides the same value.

!!! info "Lemma 5.1.1"
    Every $2$-thread consensus protocol has a bivalent initial state.

!!! info "Lemma 5.1.2"
    Every $n$-thread consensus protocol has a bivalent initial state.

A protocol state is **critical** if:

- it is bivalent, and 
- if any thread moves, the protocol state becomes univalent.

!!! info "Lemma 5.1.3"
    Every wait-free consensus protocol has a critical state.

## 5.2 Atomic Registers

!!! info "Theorem 5.2.1"
    Atomic registers have consensus number $1$.

!!! info "Corollary 5.2.1"
    It is impossible to construct a wait-free implementation of any object with consensus number greater than $1$ using atomic register.

> Corollary 5.2.1 explains why, if we want to implement lock-free concurrent data structures on modern multiprocessors, our hardware must provide primitive synchronization operations other than loads and stores(reads-writes).

## 5.3 Consensus Protocols

The generic consensus protocl:

``` java
public abstract class ConsensusProtocol<T> implements Consensus<T> {
    protected T[] proposed = (T[]) new Object[N];

    void propose(T value) {
        proposed[ThreadID.get()] = value;
    }

    // propose its input value,
    // go on to execute a sequence of steps, in order to
    // decide on one of the proposed values.
    public abstract T decide(T value);
}
```

## 5.4 FIFO Queues

``` java
public class QueueConsensus<T> extends ConsensusProtocol<T> {
    private static final int WIN = 0;
    private static final int LOSE = 1;
    private Queue queue;

    public QueueConsensus() {
        queue = new Queue();
        queue.enq(WIN);
        queue.enq(LOSE);
    }

    public T decide(T v) {
        propose(v);

        int status = queue.deq();
        int me = ThreadID.get();    // 2 threads
        int other = 1 - me;
        if (status == WIN) {        // first
            return poposed[me];
        } else {
            return poposed[other];
        }
    }
}
```

!!! info "Theorem 5.4.1'"
    The two-dequeuer FIFO queue class has consensus number at least $2$.

!!! info "Corollary 5.4.1"
    It is impossible to construct a wait-free implementation of a queue, stack, priority queue, set or list from a set of atomic registers.

!!! info "Theorem 5.4.1"
    FIFO queues have consensus number $2$.

## 5.5 Multiple Assignment Objects

$(m, n)$-assignment problem: $1 \lt m \le n$

- given an object with $n$ fields;
- `assign()` method takes argument $m$ values $v_{i}$, $0 \le i \le m-1$, and $m$ index values $i_{j}$, $0 \le j \le m-1$, $0 \le i_{j} \le n-1$.

$(2, 3)$-assignment object:

``` java
public class Assign23 {
    int[] r = new int[3];                                           // n = 3

    public Assign23(int init) {
        for (int i = 0; i < r.length; i++) {
            r[i] = init;
        }
    }

    public synchronized void assign(T v0, T v1, int i0, int i1) {   // m = 2
        r[i0] = v0;
        r[i1] = v1;
    }

    public synchronized int read(int i) {
        return r[i];
    }
}
```

``` java
public class MultipleAssignmentConsensus<T> extends ConsensusProtocol<T> {
    private final int NULL = -1;
    Assign23 assign23 = new Assign23(NULL);

    public T decide(T v) {
        propose(v);
                                                // 2 threads
        int me = ThreadID.get();                // 0 or 1
        int other = 1 - me;                     // 1 or 0
        assign23.assign(me, me, me, me+1);      // me=0: r[0]=0, r[1]=0
                                                // me=1: r[1]=1, r[2]=1
        
        int r = assign23.read((me+2) % 3);      // me=0: r=r[2]
                                                //  NULL: r[0]=0, r[1]=0, r[2]=NULL
                                                //  1: r[0]=0, r[1]=1, r[2]=1
                                                // me=1: r=r[0]
                                                //  NULL: r[0]=NULL, r[1]=0, r[2]=1
                                                //  0: r[0]=0, r[1]=0, r[2]=1
        if (r == NULL || r == assign23.read(1)) {   // NULL, r[1]=r
            return proposed[me];                // win
        } else {
            return proposed[other];
        }
    }
}
```

!!! info "Theorem 5.5.1"
    There is no wait-free implementation of an $(m, n)$-assignment object by an atmoic registers for any $1 \lt m \lt n$.

!!! info "Theorem 5.5.2"
    Atomic $(n, \frac{n(n+1)}{2}$-assignment registers for $n \lt 1$ has consensus number at least $n$.

## 5.6 Read–Modify–Write Operations

Consider a **RMW(read-modity-write)** register that encapsulates integer values, let $F$ be a set of functions from integers to integers.

**A method is an RMW for the function set $F$** if it atomically replaces the current register value $v$ with $f(v)$, form some $f \in F$, and returns the original value $v$.

> Example: `java.util.concurrent.AtomicInteger` `getAndSet(v)`, `getAndIncrement()`, `getAndAdd(k)`, `compareAndSet()`, `get()`.

An RMW method is **nontrivial** if its set of functions includes at least one function that is not the identity function.

!!! info "Theorem 5.6.1"
    Any nontrivial RMW register has consensus number at least $2$.

!!! info "Corollary 5.6.1"
    It is impossible to construct a wait-free implementation of any nontrivial RMW method from atomic register for two or more threads.


## 5.7 Common2 RMW Operations


!!! info "Definition 5.7.1"
    A set of functions $F$ belongs to Common2 if for all values $v$ and all $f_{i}, f_{j} \in F$, either:<br/>
    $f_{i}$ and $f_{j}$ **commute**: $f_{i}(f_{j}(v)) = f_{j}(f_{i}(v))$, or<br/>
    one function **overwrites** the other: $f_{i}(f_{j}(v)) = f_{i}(v)$ or $f_{j}(f_{i}(v)) = f_{j}(v)$.

!!! info "Definition 5.7.2"
    A RMW register belongs to Common2 if its set of functions $F$ belongs to Common2.

!!! info "Theorem 5.7.1"
    Any RMW register in Common2 has consensus number $2$.

## 5.8 The compareAndSet() Operation

!!! info "Theorem 5.8.1"
    A register providing `compareAndSet()` and `get()` methods has an infinite consensus number.

!!! info "Corollary 5.8.1"
    A register providing only `compareAndSet()` has an infinite consensus number.


``` java
public class CASConsensus extends ConsensusProtocol {
    private final int FIRST = -1;
    private AtomicInteger r = new AtomicInteger(FIRST);

    public Object decide(Object v) {
        propose(v);

        int me = ThreadID.get();
        if (r.compareAndSet(FIRST, me)) {   // win
            return proposed[me];
        } else {                            // lose
            return proposed[r.get()];
        }
    }
}
```