/*
 * MutexTest.java
 * JUnit based test
 *
 * Created on August 26, 2006, 7:50 PM
 */

package tamp.ch08.Monitor.monitor;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import tamp.appendix1.Software.software.ThreadID;

/**
 * Crude & inadequate test of lock class.
 *
 * @author Maurice Herlihy
 */
public class MutexTest extends TestCase {
    private final static int THREADS = 8;
    private final static int COUNT = 8 * 1024;
    private final static int PER_THREAD = COUNT / THREADS;
    Thread[] thread = new Thread[THREADS];
    int counter = 0;

    Mutex instance = new Mutex();

    public MutexTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(MutexTest.class);

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
