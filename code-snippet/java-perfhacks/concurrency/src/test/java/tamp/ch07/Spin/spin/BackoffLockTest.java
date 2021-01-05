/*
 * BackoffTest.java
 * JUnit based test
 *
 * Created on January 12, 2006, 8:27 PM
 */

package tamp.ch07.Spin.spin;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Crude & inadequate test of lock class.
 *
 * @author Maurice Herlihy
 */
public class BackoffLockTest extends TestCase {
    private final static int THREADS = 8;
    private final static int COUNT = 8 * 1024;
    private final static int PER_THREAD = COUNT / THREADS;
    Thread[] thread = new Thread[THREADS];
    int counter = 0;

    BackoffLock instance = new BackoffLock();

    public BackoffLockTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(BackoffLockTest.class);

        return suite;
    }

    public void testParallel() throws Exception {
        System.out.println("parallel");
        ThreadID.reset();
        for (int i = 0; i < THREADS; i++) {
            thread[i] = new MyThread();
        }
        for (int i = 0; i < THREADS; i++) {
            thread[i].start();
        }
        for (int i = 0; i < THREADS; i++) {
            thread[i].join();
        }

        assertEquals(counter, COUNT);
    }

    class MyThread extends Thread {
        public void run() {
            for (int i = 0; i < PER_THREAD; i++) {
                instance.lock();
                try {
                    counter = counter + 1;
                } finally {
                    instance.unlock();
                }
            }
        }
    }
}
