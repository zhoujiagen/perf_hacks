# Java Concurrency

- https://docs.oracle.com/javase/1.5.0/docs/api/
- https://docs.oracle.com/javase/6/docs/api/
- https://docs.oracle.com/javase/7/docs/api/
- https://docs.oracle.com/javase/8/docs/api/

## `sun.misc`

- `Unsafe`: [Java Magic. Part 4: sun.misc.Unsafe](http://mishadoff.com/blog/java-magic-part-4-sun-dot-misc-dot-unsafe/).

## `java.lang`

### 接口

|<p style="width: 260px;">接口</p>|Since|说明|
|:---|:---|:---|
| `Runnable`                          | 1.0 |	The Runnable interface should be implemented by any class whose instances are intended to be executed by a thread.|
| `Thread.UncaughtExceptionHandler`   | 1.5 | Interface for handlers invoked when a Thread abruptly terminates due to an uncaught exception.|

### 类

|<p style="width: 260px;">类</p>|Since|说明|
|:---|:---|:---|
| `InheritableThreadLocal<T>`     | 1.2 | This class extends ThreadLocal to provide inheritance of values from parent thread to child thread: when a child thread is created, the child receives initial values for all inheritable thread-local variables for which the parent has values.|
| `Process`                       | 1.0 | The `ProcessBuilder.start()`` and `Runtime.exec` methods create a native process and return an instance of a subclass of Process that can be used to control the process and obtain information about it.|
| `ProcessBuilder`                | 1.5 | This class is used to create operating system processes.|
| `ProcessBuilder.Redirect`       | 1.7 | Represents a source of subprocess input or a destination of subprocess output.|
| `Runtime`                       | 1.0 | Every Java application has a single instance of class Runtime that allows the application to interface with the environment in which the application is running.|
| `RuntimePermission`             || This class is for runtime permissions.|
| `Thread`                        | 1.0 |	A thread is a thread of execution in a program.|
| `ThreadGroup`                   | 1.0 |	A thread group represents a set of threads.|
| `ThreadLocal<T>`                | 1.2 | This class provides thread-local variables.|

### 枚举

|<p style="width: 260px;">枚举</p>|Since|说明|
|:---|:---|:---|
| `ProcessBuilder.Redirect.Type`  | 1.7 |The type of a `ProcessBuilder.Redirect`.|
| `Thread.State`                  | 1.5 | A thread state.|

### 异常

|<p style="width: 260px;">异常</p>|Since|说明|
|:---|:---|:---|
| `IllegalMonitorStateException`  | 1.0 | Thrown to indicate that a thread has attempted to wait on an object's monitor or to notify other threads waiting on an object's monitor without owning the specified monitor.|
| `IllegalThreadStateException`   | 1.0 | Thrown to indicate that a thread is not in an appropriate state for the requested operation.|
| `InterruptedException`          | 1.0 | Thrown when a thread is waiting, sleeping, or otherwise occupied, and the thread is interrupted, either before or during the activity.|
| `RuntimeException`              | 1.0 | `RuntimeException` is the superclass of those exceptions that can be thrown during the normal operation of the Java Virtual Machine.
|
| `ThreadDeath`                   | 1.0 | An instance of `ThreadDeath` is thrown in the victim thread when the (deprecated) `Thread.stop()` method is invoked.|

## `java.util.concurrent`

### 接口

|<p style="width: 260px;">接口</p>|Since|说明|
|:---|:---|:---|
| `BlockingDeque<E>`                                | 1.6 | A Deque that additionally supports blocking operations that wait for the deque to become non-empty when retrieving an element, and wait for space to become available in the deque when storing an element. <br>阻塞的双端队列.|
| `BlockingQueue<E>`                                | 1.5 | A Queue that additionally supports operations that wait for the queue to become non-empty when retrieving an element, and wait for space to become available in the queue when storing an element. <br>阻塞的队列.|
| `Callable<V>`	                                    | 1.5 | A task that returns a result and may throw an exception. <br>返回结果或抛出异常的任务. |
| `CompletionService<V>`                            | 1.5  | A service that decouples the production of new asynchronous tasks from the consumption of the results of completed tasks. <br> 将生成新的异步任务与消费已完成任务的结果解耦的服务. |
| `ConcurrentMap<K,V>`                              | 1.5 | A Map providing additional atomic putIfAbsent, remove, and replace methods. 提供了原子的`putIfAbsent`、`remove`和`replace`方法的映射. |
| `ConcurrentNavigableMap<K,V>`	                    | 1.6  | A ConcurrentMap supporting NavigableMap operations, and recursively so for its navigable sub-maps. <br>支持`NavigableMap`操作的`ConcurrentMap`: <br> `public interface ConcurrentNavigableMap<K,V> extends ConcurrentMap<K,V>, NavigableMap<K,V>`<br> `public interface NavigableMap<K,V> extends SortedMap<K,V>`<br> |
| `Delayed`	                                        | 1.5 | A mix-in style interface for marking objects that should be acted upon after a given delay. <br>一个混入风格的接口, 用于标记在指定延迟后应该被操作的对象.|
| `Executor`	                                      | 1.5 | An object that executes submitted Runnable tasks. <br>执行已提交的`Runnable`任务的对象.|
| `ExecutorService`	                                | 1.5 | An Executor that provides methods to manage termination and methods that can produce a Future for tracking progress of one or more asynchronous tasks. <br> 一个`Executor`, 提供了管理终止和为跟踪一个或多个异步任务的进展而生成`Future`的方法.|
| `ForkJoinPool.`<br>`ForkJoinWorkerThreadFactory`	| 1.7 | Factory for creating new ForkJoinWorkerThreads. <br>创建`ForkJoinWorkerThread`的工厂.|
| `ForkJoinPool.`<br>`ManagedBlocker`	              | 1.7 | Interface for extending managed parallelism for tasks running in ForkJoinPools. <br>用于扩展在`ForkJoinPool`中运行的任务的受管的并行度的接口.|
| `Future<V>`	                                      | 1.5 | A Future represents the result of an asynchronous computation. <br>表示异步计算的结果.|
| `RejectedExecutionHandler`                        | 1.5 | A handler for tasks that cannot be executed by a ThreadPoolExecutor. <br>任务不能被`ThreadPoolExecutor`的处理器.|
| `RunnableFuture<V>`	                              | 1.6 | A Future that is Runnable. <br>是`Runnable`的`Future`.|
| `RunnableScheduledFuture<V>`                      | 1.6 | A ScheduledFuture that is Runnable. <br>是`Runnable`的`ScheduledFuture`.|
| `ScheduledExecutorService`                        | 1.5 | An ExecutorService that can schedule commands to run after a given delay, or to execute periodically. <br>可以调度命令在给定延迟后或周期性执行的`ExecutorService`.|
| `ScheduledFuture<V>`                              | 1.5 | A delayed result-bearing action that can be cancelled. <br>可以被取消的, 被延迟的携带结果的动作.|
| `ThreadFactory`	                                  | 1.5 | An object that creates new threads on demand. <br>按需创建新线程的对象.|
| `TransferQueue<E>`                                | 1.7 | A BlockingQueue in which producers may wait for consumers to receive elements. <br>一个`BlockingQueue`, 生产者可以等待消费者接收元素.|

### 类

|<p style="width: 260px;">类</p>|Since|说明|
|:---|:---|:---|
| `AbstractExecutorService`                       | 1.5 | Provides default implementations of ExecutorService execution methods. <br>. 提供`ExecutorService`执行方法的默认实现.|
| `ArrayBlockingQueue<E>`                         | 1.5 | A bounded blocking queue backed by an array. <br>一个数组后端的有界阻塞队列.|
| `CompletableFuture<T>`                          | 1.8 | A `Future` that may be explicitly completed (setting its value and status), and may be used as a `CompletionStage`, supporting dependent functions and actions that trigger upon its completion.|
|`CompletionStage<T>`                             | 1.8 | A stage of a possibly asynchronous computation, that performs an action or computes a value when another CompletionStage completes.|
| `ConcurrentHashMap<K,V>`                        | 1.5 | A hash table supporting full concurrency of retrievals and adjustable expected concurrency for updates. <br>支持完整的并发更新时检索和调整哈希表.|
| `ConcurrentLinkedDeque<E>`                      | 1.7 | An unbounded concurrent deque based on linked nodes. <br>基于链接节点的无界并发双端队列.|
| `ConcurrentLinkedQueue<E>`                      | 1.5 | An unbounded thread-safe queue based on linked nodes. <br>基于链接节点的无界线程安全的队列.|
| `ConcurrentSkipListMap<K,V>`                    | 1.6 | A scalable concurrent ConcurrentNavigableMap implementation. <br>一个可扩展的并发`ConcurrentNavigableMap`的实现.|
| `ConcurrentSkipListSet<E>`                      | 1.6 | A scalable concurrent NavigableSet implementation based on a ConcurrentSkipListMap. <br>一个基于`ConcurrentSkipListMap`的可扩展的并发`NavigableSet`的实现.|
| `CopyOnWriteArrayList<E>`                       | 1.5 | A thread-safe variant of ArrayList in which all mutative operations (add, set, and so on) are implemented by making a fresh copy of the underlying array. <br>一个线程安全的`ArrayList`变体, 所有修改操作(`add`、`set`等)是通过执行底层数组的新拷贝实现的.|
| `CopyOnWriteArraySet<E>`                        | 1.5 | A Set that uses an internal CopyOnWriteArrayList for all of its operations. <br>一个`Set`, 内部使用`CopyOnWriteArrayList`实现所有操作.|
| `CountDownLatch`                                | 1.5 | A synchronization aid that allows one or more threads to wait until a set of operations being performed in other threads completes. <br>一个同步工具, 允许一个或多个线程等待直到一组在其它线程中执行的操作完成.|
|`CountedCompleter<T>`                            | 1.8 | A `ForkJoinTask` with a completion action performed when triggered and there are no remaining pending actions.|
| `CyclicBarrier`                                 | 1.5 | A synchronization aid that allows a set of threads to all wait for each other to reach a common barrier point. <br>一个同步工具, 允许一组线程均互相等待以到达一个通用的栅栏点.|
| `DelayQueue<E extends Delayed>`                 | 1.5 | An unbounded blocking queue of Delayed elements, in which an element can only be taken when its delay has expired. <br>一个元素为`Delayed`的无界阻塞队列, 只有当元素的延迟已过时, 该元素才可被取出.|
| `Exchanger<V>`                                  | 1.5  | A synchronization point at which threads can pair and swap elements within pairs. <br>一个同步点, 线程可以组对, 且在对中交换元素.|
| `ExecutorCompletionService<V>`                  | 1.5 | A CompletionService that uses a supplied Executor to execute tasks. <br>一个`CompletionService`, 使用提供的`Executor`执行任务.|
| `Executors`                                     | 1.5 | Factory and utility methods for Executor, ExecutorService, ScheduledExecutorService, ThreadFactory, and Callable classes defined in this package. <br>这个包中`Executor`、`ExecutorService`、`ScheduledExecutorService`、`ThreadFactory`、`Callable`类的工厂和工具方法.|
| `ForkJoinPool`                                  | 1.7 | An ExecutorService for running ForkJoinTasks. <br>运行`ForkJoinTask`的`ExecutorService`.|
| `ForkJoinTask<V>`                               | 1.7 | Abstract base class for tasks that run within a ForkJoinPool. <br>在`ForkJoinPool`中运行的任务的抽象基类.|
| `ForkJoinWorkerThread`                          | 1.7 | A thread managed by a ForkJoinPool, which executes ForkJoinTasks. <br>由`ForkJoinPool`管理的线程, 在其中执行`ForkJoinTask`.|
| `FutureTask<V>`                                 | 1.5  | A cancellable asynchronous computation. <br>一个可被取消的异步计算.|
| `LinkedBlockingDeque<E>`                        | 1.6 | An optionally-bounded blocking deque based on linked nodes. <br>一个基于链接节点的可选有界的阻塞双端队列.|
| `LinkedBlockingQueue<E>`                        | 1.5 | An optionally-bounded blocking queue based on linked nodes. <br>一个基于链接节点的可选有界的阻塞队列.|
| `LinkedTransferQueue<E>`                        | 1.7 | An unbounded TransferQueue based on linked nodes. <br>一个基于链接节点的无界`TransferQueue`.|
| `Phaser`                                        | 1.7  | A reusable synchronization barrier, similar in functionality to CyclicBarrier and CountDownLatch but supporting more flexible usage. <br>一个可重用的同步栅栏, 与`CyclicBarrier`和`CountDownLatch`功能类似, 但更灵活.|
| `PriorityBlockingQueue<E>`                      | 1.5 | An unbounded blocking queue that uses the same ordering rules as class PriorityQueue and supplies blocking retrieval operations. <br>一个无界阻塞队列, 使用与`PriorityQueue`相同的排序规则, 支持阻塞的检索操作.|
| `RecursiveAction`                               | 1.7 | A recursive resultless ForkJoinTask. <br>一个递归的无结果的`ForkJoinTask`.|
| `RecursiveTask<V>`                              | 1.7 | A recursive result-bearing ForkJoinTask. <br>一个递归的携带结果的`ForkJoinTask`.|
| `ScheduledThreadPoolExecutor`                   | 1.5 | A ThreadPoolExecutor that can additionally schedule commands to run after a given delay, or to execute periodically. <br>一个`ThreadPoolExecutor`, 额外提供了在执行延迟后调度命令或周期性执行命令.|
| `Semaphore`                                     | 1.5 | A counting semaphore. <br>一个计数信号量.|
| `SynchronousQueue<E>`                           | 1.5 | A blocking queue in which each insert operation must wait for a corresponding remove operation by another thread, and vice versa. <br>一个阻塞队列, 每个插入操作必须等待对应的另一个线程中的删除操作, 反之亦然.|
| `ThreadLocalRandom`                             | 1.7 | A random number generator isolated to the current thread. <br>当前线程中隔离的随机数生成器.|
| `ThreadPoolExecutor`                            | 1.5 | An ExecutorService that executes each submitted task using one of possibly several pooled threads, normally configured using Executors factory methods. <br>一个`ExecutorService`, 使用池化线程(通常使用`Executors`工厂方法配置)中的一个执行已提交的任务.|
| `ThreadPoolExecutor.`<br>`AbortPolicy`          | 1.5 | A handler for rejected tasks that throws a RejectedExecutionException. <br>抛出`RejectedExecutionException`的被拒绝任务的处理器.|
| `ThreadPoolExecutor.`<br>`CallerRunsPolicy`     | 1.5 | A handler for rejected tasks that runs the rejected task directly in the calling thread of the execute method, unless the executor has been shut down, in which case the task is discarded. <br>被拒绝任务的处理器, 直接在执行方法的调用线程中运行被拒绝的任务, 除非执行者已关闭, 这时该任务被丢弃.|
| `ThreadPoolExecutor.`<br>`DiscardOldestPolicy`  | 1.5 | A handler for rejected tasks that discards the oldest unhandled request and then retries execute, unless the executor is shut down, in which case the task is discarded. <br>被拒绝任务的处理器, 丢弃最旧的未处理请求, 然后重试执行, 除非执行者已关闭, 这时该任务被丢弃.|
| `ThreadPoolExecutor.`<br>`DiscardPolicy`        | 1.5 | A handler for rejected tasks that silently discards the rejected task. <br>被拒绝任务的处理器, 直接丢弃被拒绝的任务.|

### 枚举

|<p style="width: 260px;">枚举</p>|Since|说明|
|:---|:---|:---|
| `TimeUnit`	                   | 1.5 | A TimeUnit represents time durations at a given unit of granularity and provides utility methods to convert across units, and to perform timing and delay operations in these units. <br>不同粒度的时间长度的枚举工具类.|

### 异常

|<p style="width: 260px;">异常</p>|Since|说明|
|:---|:---|:---|
| `BrokenBarrierException`      | 1.5 | Exception thrown when a thread tries to wait upon a barrier that is in a broken state, or which enters the broken state while the thread is waiting. <br>当线程尝试在已处于破坏状态的栅栏上等待, 或者线程等待时变为了破坏状态时, 抛出.|
| `CancellationException`       | 1.5 | Exception indicating that the result of a value-producing task, such as a FutureTask, cannot be retrieved because the task was cancelled. <br>指示产生值的任务的结果, 例如`FutureTask`, 因为任务被取消而无法获取.|
| `CompletionException`         | 1.8 | Exception thrown when an error or other exception is encountered in the course of completing a result or task.|
| `ExecutionException`          | 1.5 | Exception thrown when attempting to retrieve the result of a task that aborted by throwing an exception. <br>当尝试获取因抛出异常而终止的任务的结果时, 抛出.|
| `RejectedExecutionException`  | 1.5 | Exception thrown by an Executor when a task cannot be accepted for execution. <br>当`Executor`无法接收任务执行时, 抛出.|
| `TimeoutException`            | 1.5 | Exception thrown when a blocking operation times out. <br>当阻塞操作超时时, 抛出.|


## java.util.concurrent.atomic

|<p style="width: 260px;">类</p>|Since|说明|
|:---|:---|:---|
| `AtomicBoolean`                     | 1.5 | A boolean value that may be updated atomically. <br>可被原子更新的布尔值.|
| `AtomicInteger`                     | 1.5 | An int value that may be updated atomically. <br>可被原子更新的整数值.|
| `AtomicIntegerArray`                | 1.5 | An int array in which elements may be updated atomically. <br>元素可被原子更新的整数数组.|
| `AtomicIntegerFieldUpdater<T>`      | 1.5 | A reflection-based utility that enables atomic updates to designated volatile int fields of designated classes. <br>一个基于反射的工具, 允许原子的更新指定类中指定的`volatile`整数字段.|
| `AtomicLong`                        | 1.5 | A long value that may be updated atomically. <br>可被原子更新的长整数值.|
| `AtomicLongArray`                   | 1.5 | A long array in which elements may be updated atomically. <br>元素可被原子更新的长整数数组.|
| `AtomicLongFieldUpdater<T>`         | 1.5 | A reflection-based utility that enables atomic updates to designated volatile long fields of designated classes. <br>一个基于反射的工具, 允许原子的更新指定类中指定的`volatile`长整数字段.|
| `AtomicMarkableReference<V>`        | 1.5 | An AtomicMarkableReference maintains an object reference along with a mark bit, that can be updated atomically. <br>用一个标记位维护一个对象引用, 这个引用可被原子的更新.|
| `AtomicReference<V>`                | 1.5 | An object reference that may be updated atomically. <br>可被原子更新的对象引用.|
| `AtomicReferenceArray<E>`           | 1.5 | An array of object references in which elements may be updated atomically. <br>元素可被原子更新的对象引用数组.|
| `AtomicReferenceFieldUpdater<T,V>`  | 1.5 | A reflection-based utility that enables atomic updates to designated volatile reference fields of designated classes. <br>一个基于反射的工具, 允许原子的更新指定类中指定的`volatile`引用字段.|
| `AtomicStampedReference<V>`         | 1.5 | An AtomicStampedReference maintains an object reference along with an integer "stamp", that can be updated atomically. <br>用一个整数标志维护一个对象引用, 这个引用可被原子的更新.|
|`DoubleAccumulator`                  | 1.8 | One or more variables that together maintain a running double value updated using a supplied function.|
|`DoubleAdder`                        | 1.8 | One or more variables that together maintain an initially zero double sum.|
|`LongAccumulator`                    | 1.8 | One or more variables that together maintain a running long value updated using a supplied function.|
|`LongAdder`                          | 1.8 | One or more variables that together maintain an initially zero long sum.|

## java.util.concurrent.locks

### 接口

|<p style="width: 260px;">接口</p>|Since|说明|
|:---|:---|:---|
| `Condition`                         | 1.5  | Condition factors out the Object monitor methods (wait, notify and notifyAll) into distinct objects to give the effect of having multiple wait-sets per object, by combining them with the use of arbitrary Lock implementations. <br>将`Object`的监视器方法(`wait`、`notify`、`notifyAll`)泛化到不同对象上, 通过与任意`Lock`实现的使用结合在一起, 提供了每个对象上有多个等待集的效果.|
| `Lock`                              | 1.5  | Lock implementations provide more extensive locking operations than can be obtained using synchronized methods and statements. <br>提供了使用同步方法和语句外更为基础的锁操作.|
| `ReadWriteLock`                     | 1.5  | A ReadWriteLock maintains a pair of associated locks, one for read-only operations and one for writing. <br>维护了一个相关的锁对, 一个用于只读操作, 一个用于写操作.|

### 类

|<p style="width: 260px;">类</p>|Since|说明|
|:---|:---|:---|
| `AbstractOwnableSynchronizer`       | 1.6  | A synchronizer that may be exclusively owned by a thread. <br>一个可被一个线程互斥拥有的同步器.|
| `AbstractQueuedLongSynchronizer`    | 1.6  | A version of AbstractQueuedSynchronizer in which synchronization state is maintained as a long. <br>一个`AbstractQueuedSynchronizer`, 其中同步状态用`long`维护.|
| `AbstractQueuedSynchronizer`        | 1.5  | Provides a framework for implementing blocking locks and related synchronizers (semaphores, events, etc) that rely on first-in-first-out (FIFO) wait queues. <br>提供了一个框架, 以实现依赖于FIFO等待队列的、阻塞的锁和相关的同步器(信号量、事件等).|
| `LockSupport`                       | 1.5  | Basic thread blocking primitives for creating locks and other synchronization classes. <br>创建锁和其它同步类的基本线程阻塞原语.|
| `ReentrantLock`                     | 1.5  | A reentrant mutual exclusion Lock with the same basic behavior and semantics as the implicit monitor lock accessed using synchronized methods and statements, but with extended capabilities. <br>一个可重入的互斥`Lock`, 有与使用同步方法和语句访问的隐式监视器锁相同的行为和语义, 但有扩展的能力.|
| `ReentrantReadWriteLock`            | 1.5  | An implementation of ReadWriteLock supporting similar semantics to ReentrantLock. <br>支持与`ReentrantLock`类似的语义的`ReadWriteLock`的实现.|
| `ReentrantReadWriteLock.ReadLock`   | 1.5  | The lock returned by method ReentrantReadWriteLock.readLock(). <br>`ReentrantReadWriteLock.readLock()`方法返回的锁.|
| `ReentrantReadWriteLock.WriteLock`  | 1.5  | The lock returned by method ReentrantReadWriteLock.writeLock(). <br>`ReentrantReadWriteLock.writeLock()`方法返回的锁.|
| `StampedLock`                       | 1.8 | A capability-based lock with three modes for controlling read/write access.|
