import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

    private static PrintWriter cout;

    /**
     * @param args 
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO Auto-generated method stub
        
        Scanner cin = new Scanner(new File("china.in"));
        cout = new PrintWriter(new File("china.out"));

        BigInteger n = cin.nextBigInteger();
        BigInteger k = n.divide(BigInteger.ONE.add(BigInteger.ONE));
        
        while(true) {
            if(n.gcd(k).compareTo(BigInteger.ONE) == 0) {
                break;
            }
            k = k.subtract(BigInteger.ONE);
        }
        cout.println(k);
        cout.close();
    }

}
