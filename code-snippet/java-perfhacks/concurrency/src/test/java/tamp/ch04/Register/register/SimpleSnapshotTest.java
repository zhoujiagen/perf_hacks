/*
 * SimpleSnapshotTest.java
 * JUnit based test
 *
 * Created on January 12, 2006, 8:27 PM
 */

package tamp.ch04.Register.register;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Crude & inadequate test of snapshot class.
 *
 * @author Maurice Herlihy
 */
public class SimpleSnapshotTest extends TestCase {
    private final static int THREADS = 2;
    private final static int FIRST = 11;
    private final static int SECOND = 22;
    Thread[] thread = new Thread[THREADS];
    int[][] results = new int[THREADS][THREADS];

    SimpleSnapshot instance = new SimpleSnapshot(THREADS, 0);

    public SimpleSnapshotTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(SimpleSnapshotTest.class);

        return suite;
    }

    /**
     * Sequential calls.
     */
    public void testSequential() {
        System.out.println("sequential");
        instance.update(FIRST);
        Object[] result = instance.scan();
        assertEquals(result[ThreadID.get()], FIRST);
    }

    /**
     * Parallel reads
     */
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
        for (int i = 0; i < THREADS; i++) {
            for (int j = 0; j < i; j++) {
                assert (comparable(results[i], results[j]));
            }
        }
    }

    private boolean comparable(int[] a, int[] b) {
        boolean leq = false;
        boolean geq = false;
        for (int i = 0; i < a.length; i++) {
            if (a[i] < b[i]) {
                leq = true;
            } else if (a[i] > b[i]) {
                geq = true;
            }
        }
        return !(leq && geq);
    }

    class MyThread extends Thread {
        public void run() {
            instance.update(FIRST);
            instance.update(SECOND);
            Object[] a = instance.scan();
            for (Object x : a) {
                Integer i = (Integer) x;
                int me = ThreadID.get();
                for (int j = 0; j < THREADS; j++) {
                    results[me][j] = (Integer) a[j];
                }
            }
        }
    }
}
