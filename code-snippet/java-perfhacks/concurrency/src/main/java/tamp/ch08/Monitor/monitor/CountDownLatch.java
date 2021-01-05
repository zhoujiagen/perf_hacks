/*
 * CountDownLatch.java
 *
 * Created on August 27, 2006, 9:03 PM
 *
 * From "The Art of Multiprocessor Programming",
 * by Maurice Herlihy and Nir Shavit.
 * Copyright 2006 Elsevier Inc. All rights reserved.
 */

package tamp.ch08.Monitor.monitor;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Faux implementation of CountDownLatch from java.util.concurrent.
 *
 * @author Maurice Herlihy
 */

public class CountDownLatch {
    int counter;
    Lock lock;
    Condition condition;

    public CountDownLatch(int count) {
        if (count < 0)
            throw new IllegalArgumentException("count < 0");
        counter = count;
        lock = new ReentrantLock();
        condition = lock.newCondition();
    }

    public void await() throws InterruptedException {
        lock.lock();
        try {
            while (counter > 0)
                condition.await();
        } finally {
            lock.unlock();
        }
    }

    public void countDown() {
        lock.lock();
        try {
            counter--;
            if (counter == 0) {
                condition.signalAll();
            }
        } finally {
            lock.unlock();
        }
    }
}


