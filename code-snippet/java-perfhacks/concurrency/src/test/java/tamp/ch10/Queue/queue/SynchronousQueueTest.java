/*
 * SynchronousQueueTest.java
 * JUnit based test
 *
 * Created on March 8, 2006, 8:13 PM
 */

package tamp.ch10.Queue.queue;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * @author Maurice Herlihy
 */
public class SynchronousQueueTest extends TestCase {
    private final static int THREADS = 8;
    private final static int TEST_SIZE = 512;
    private final static int PER_THREAD = TEST_SIZE / THREADS;
    int index;
    SynchronousQueue<Integer> instance;
    boolean[] map = new boolean[TEST_SIZE];
    Thread[] thread = new Thread[THREADS];

    public SynchronousQueueTest(String testName) {
        super(testName);
        instance = new SynchronousQueue<Integer>();
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(SynchronousQueueTest.class);
        return suite;
    }

    /**
     * Parallel enqueues, parallel dequeues
     */
    public void testParallelBoth() throws Exception {
        System.out.println("parallel both");
        Thread[] myThreads = new Thread[2 * THREADS];
        for (int i = 0; i < THREADS; i++) {
            myThreads[i] = new EnqThread(i * PER_THREAD);
            myThreads[i + THREADS] = new DeqThread();
        }
        for (int i = 0; i < 2 * THREADS; i++) {
            myThreads[i].start();
        }
        for (int i = 0; i < 2 * THREADS; i++) {
            myThreads[i].join();
        }
    }

    class EnqThread extends Thread {
        int value;

        EnqThread(int i) {
            value = i;
        }

        public void run() {
            for (int i = 0; i < PER_THREAD; i++) {
                try {
                    instance.enq(value + i);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    class DeqThread extends Thread {
        public void run() {
            for (int i = 0; i < PER_THREAD; i++) {
                int value = Integer.MIN_VALUE;
                try {
                    value = (Integer) instance.deq();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (map[value]) {
                    fail("DeqThread: duplicate pop");
                }
                map[value] = true;
            }
        }
    }

}