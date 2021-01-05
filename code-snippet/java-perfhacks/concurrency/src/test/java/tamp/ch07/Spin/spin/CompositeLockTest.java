/*
 * CompositeLockTest.java
 * JUnit based test
 *
 * Created on April 11, 2006, 10:54 PM
 */

package tamp.ch07.Spin.spin;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * @author mph
 */
public class CompositeLockTest extends TestCase {
    private final static int THREADS = 2;
    private final static int COUNT = 32 * 128;
    private final static int PER_THREAD = COUNT / THREADS;
    Thread[] thread = new Thread[THREADS];
    int counter = 0;

    CompositeLock instance = new CompositeLock();

    public CompositeLockTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(CompositeLockTest.class);

        return suite;
    }

    public void testParallel() throws Exception {
        for (int i = 0; i < THREADS; i++) {
            thread[i] = new MyThread();
        }
        for (int i = 0; i < THREADS; i++) {
            thread[i].start();
        }
        for (int i = 0; i < THREADS; i++) {
            thread[i].join();
        }

        assertEquals(COUNT, counter);
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
