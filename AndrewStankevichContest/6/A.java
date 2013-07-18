import java.io.*;
import java.util.*;
import java.math.*;

public class A {

    private static PrintWriter cout;
    private static BigInteger f[][] = new BigInteger[55][55];
    
    public static void solve(int n, int k) {
        if(k > n)
            return;
        if(k == 1)
            f[n][k] = BigInteger.ONE;
        if(k == 0)
            if(n != 0)
                return;
            else 
                f[n][k] = BigInteger.ONE; 
        if(f[n][k].compareTo(BigInteger.ZERO) != 0)
            return;
        for(int t = 1; t <= n; ++t) {
            for(int p = 0; p <= k; ++p) {
                solve(t - 1, k - 1);
                solve(n - t, p);
                f[n][k] = f[n][k].add(f[t - 1][k - 1].multiply(f[n - t][p]));
            }
            for(int p = 0; p < k - 1; ++p) {
                solve(t - 1, p);
                solve(n - t, k);
                f[n][k] = f[n][k].add(f[t - 1][p].multiply(f[n - t][k]));
            }
    }
    }
    
    /**
     * @param args 
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO Auto-generated method stub
        
        Scanner cin = new Scanner(new File("brackets.in"));
        cout = new PrintWriter(new File("brackets.out"));
        
        int n, k, cn = 0;
        for(int i = 0; i <= 50; ++i)
            for(int j = 0; j <= 50; ++j)
                f[i][j] = BigInteger.ZERO;
        
        while(true) {
            n = cin.nextInt();
            k = cin.nextInt();
            if(n + k == 0)
                break;
            solve(n, k);
            cn++;
            cout.print("Case ");
            cout.print(cn);
            cout.print(": ");
            cout.println(f[n][k]);
            cout.println();
        }
    
    	cout.close();
}

}

