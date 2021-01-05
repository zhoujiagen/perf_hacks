/*
 * RegBooleanMRSWRegisterTest.java
 * JUnit based test
 *
 * Created on January 12, 2006, 8:27 PM
 */

package tamp.ch04.Register.register;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * @author mph
 */
public class RegBooleanMRSWRegisterTest extends TestCase {
    private final static int THREADS = 8;
    Thread[] thread = new Thread[THREADS];

    RegBooleanMRSWRegister instance = new RegBooleanMRSWRegister(THREADS);

    public RegBooleanMRSWRegisterTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(RegBooleanMRSWRegisterTest.class);

        return suite;
    }

    /**
     * Sequential calls.
     */
    public void testSequential() {
        System.out.println("sequential read and write");
        instance.write(true);
        boolean result = instance.read();
        assertEquals(result, true);
    }

    /**
     * Parallel reads
     */
    public void testParallel() throws Exception {
        instance.write(false);
        instance.write(true);
        System.out.println("parallel read");
        for (int i = 0; i < THREADS; i++) {
            thread[i] = new ReadThread();
        }
        for (int i = 0; i < THREADS; i++) {
            thread[i].start();
        }
        for (int i = 0; i < THREADS; i++) {
            thread[i].join();
        }
    }

    class ReadThread extends Thread {
        public void run() {
            if (!instance.read()) {
                fail("register returns false");
            }
        }
    }

}
