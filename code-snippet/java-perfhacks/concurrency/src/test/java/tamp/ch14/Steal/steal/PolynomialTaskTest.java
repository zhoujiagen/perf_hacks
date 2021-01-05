/*
 * PolynomialTaskTest.java
 * JUnit based test
 *
 * Created on December 10, 2006, 10:47 PM
 */

package tamp.ch14.Steal.steal;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.util.concurrent.ExecutionException;

import static tamp.ch14.Steal.steal.PolynomialTask.Polynomial;

/**
 * @author mph
 */
public class PolynomialTaskTest extends TestCase {

    public PolynomialTaskTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(PolynomialTaskTest.class);

        return suite;
    }

    /**
     * Test of run method, of class steal.PolynomialTask.
     */
    public void testRun() throws InterruptedException, ExecutionException {
        System.out.println("run");

        int[] a = {1, 1, 1, 1, 1, 1, 1, 1};
        int[] b = {1, 1, 1, 1, 1, 1, 1, 1};
        Polynomial aa = new Polynomial(a, 0, a.length);
        Polynomial bb = new Polynomial(b, 0, a.length);
        Polynomial cc = PolynomialTask.add(aa, bb);
        for (int i = 0; i < cc.getDegree(); i++) {
            assertEquals(2, cc.get(i));
        }
        Polynomial dd = PolynomialTask.multiply(aa, bb);

    }
}