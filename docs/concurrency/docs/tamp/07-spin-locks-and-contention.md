# 7. Spin Locks and Contention

Any mutial exclusion protocol poses the question: **What do you do if you cannot acquire the lock?**

1. **spining** Keep trying and repeatedly testing the lock.
2. **blocking** Suspend and ask OS's scheduler to schedule another thread on your processor.

## 7.1 Welcome to the Real World
## 7.2 Test-And-Set Locks
## 7.3 TAS-Based Spin Locks Revisited
## 7.4 Exponential Backoff
## 7.5 Queue Locks
## 7.6 A Queue Lock with Timeouts
## 7.7 A Composite Lock
## 7.8 Hierarchical Locks
## 7.9 One Lock To Rule Them All
