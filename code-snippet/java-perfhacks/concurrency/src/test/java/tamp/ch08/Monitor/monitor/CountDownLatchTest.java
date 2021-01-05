/*
 * CountDownLatchTest.java
 * JUnit based test
 *
 * Created on December 29, 2005, 9:56 PM
 */

package tamp.ch08.Monitor.monitor;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import tamp.appendix1.Software.software.ThreadID;

/**
 * @author mph
 */
public class CountDownLatchTest extends TestCase {
    static final int THREADS = 8; // number threads to test
    static final int START = 1492;
    static final int STOP = 1776;
    CountDownLatch startSignal = new CountDownLatch(1);
    CountDownLatch doneSignal = new CountDownLatch(THREADS);

    public CountDownLatchTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(CountDownLatchTest.class);
        return suite;
    }

    public void testCountDownLatch() {
        System.out.format("Testing %d threads\n", THREADS);
        CountDownLatch startSignal = new CountDownLatch(1);
        CountDownLatch doneSignal = new CountDownLatch(THREADS);
        Thread[] thread = new Thread[THREADS];
        int[] log = new int[THREADS];
        // create threads
        for (int j = 0; j < THREADS; j++)
            thread[j] = new TestThread(j, THREADS, startSignal, doneSignal, log);
        // start threads
        for (int j = 0; j < THREADS; j++)
            thread[j].start();
        // do something
        for (int i = 0; i < THREADS; i++)
            log[i] = START;
        // give threads permission to start
        startSignal.countDown();
        // wait for threads to complete
        try {
            doneSignal.await();
        } catch (InterruptedException e) {
            fail("interrupted exception");
        }
        for (int i = 0; i < THREADS; i++)
            if (log[i] != STOP)
                fail("found bad value: " + log[i]);
    }

    public class TestThread extends Thread {
        int threads;
        CountDownLatch startSignal;
        CountDownLatch doneSignal;
        int[] log;
        int index;

        public TestThread(int index, int threads,
                          CountDownLatch startSignal, CountDownLatch doneSignal, int[] log) {
            this.threads = threads;
            this.log = log;
            this.index = index;
            this.startSignal = startSignal;
            this.doneSignal = doneSignal;
        }

        public void run() {
            ThreadID.set(index);
            try {
                startSignal.await(); // wait for permission to start
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
            if (log[index] != START) {
                System.out.format("%d\tError expected %d found %d at %d\n", START, log[index], index);
            }
            log[index] = STOP;
            doneSignal.countDown();  // notify driver we are done
        }
    }
}
