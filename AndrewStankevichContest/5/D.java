import java.io.*;
import java.util.*;
import java.math.*;

public class D {

	private static PrintWriter cout;
	
	/**
	 * @param args 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		Scanner cin = new Scanner(new File("digit.in"));
		cout = new PrintWriter(new File("digit.out"));
		
		int z = 0;
		BigInteger n = cin.nextBigInteger(), a = BigInteger.ONE, b = BigInteger.ZERO;
		
		for(int i = 0; i < n.bitLength(); ++i) {
			if(n.testBit(i)) {
				BigInteger c = a;
				a = a.add(b);
				b = c.multiply(BigInteger.valueOf(z)).add(b.multiply(BigInteger.valueOf(z + 1)));
				z = 0;
			}
			else {
				++z;
			}
			
		}

		cout.println(a.add(b));
		cout.close();
	}

}

