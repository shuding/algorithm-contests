import java.io.*;
import java.util.*;
import java.math.*;

public class D {

    private static PrintWriter cout;
    /**
     * @param args
     * @throws FileNotFoundException 
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO Auto-generated method stub
        Scanner cin = new Scanner(new File("matrix.in"));
        cout = new PrintWriter(new File("matrix.out"));
        
        int n = cin.nextInt(), m = cin.nextInt();
        int col[] = new int[10010];
        int a, b;
        for(int i = 0; i < m; ++i) {
            a = cin.nextInt();
            b = cin.nextInt();
            col[b]++;
            col[a]++;
        }
        long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += col[i + 1] * col[i + 1];
        }
        cout.println(ans);
        cout.close();
    }

}
