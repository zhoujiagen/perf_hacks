/*
 * FibTest.java
 * JUnit based test
 *
 * Created on January 21, 2006, 5:47 PM
 */

package tamp.ch16.Steal.steal;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * @author mph
 */
public class FibThreadTest extends TestCase {

    public FibThreadTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(tamp.ch14.Steal.steal.FibThreadTest.class);

        return suite;
    }

    /**
     * Test of run method, of class steal.Fib.
     */
    public void testRun() {
        System.out.println("run");

        FibThread instance = new FibThread(16);
        instance.start();
        try {
            instance.join();
        } catch (InterruptedException ex) {
            ex.printStackTrace();
            fail();
        }

        // TODO add your test code below by replacing the default call to fail.
        assertEquals(987, instance.result);
    }

}
