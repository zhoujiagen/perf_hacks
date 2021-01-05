/*
 * MatrixTaskTest.java
 * JUnit based test
 *
 * Created on January 22, 2006, 2:47 PM
 */

package tamp.ch14.Steal.steal;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.util.concurrent.ExecutionException;

import static tamp.ch14.Steal.steal.MatrixTask.Matrix;

/**
 * @author mph
 */
public class MatrixTaskTest extends TestCase {

    public MatrixTaskTest(String testName) {
        super(testName);
    }

    public static Test suite() {
        TestSuite suite = new TestSuite(MatrixTaskTest.class);

        return suite;
    }

    /**
     * Test of run method, of class steal.MatrixTask.
     */
    public void testRun() throws InterruptedException, ExecutionException {
        System.out.println("run");

        double[][] a = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
        double[][] b = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
        Matrix aa = new Matrix(a, 0, 0, 2);
        Matrix bb = new Matrix(b, 0, 0, 2);
        Matrix cc = MatrixTask.multiply(aa, bb);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) {
                    assertEquals(1.0, aa.get(i, i));
                } else {
                    assertEquals(0.0, aa.get(i, j));
                }
            }
        }
    }
}
