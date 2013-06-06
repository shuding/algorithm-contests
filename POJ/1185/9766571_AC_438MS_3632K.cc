#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
int n, m, tn, num[61];
bool g[101][11], c[61][11];
long long f[101][61][61];
 
void init(int _dit, long long _state, int N)
{
        if(_dit == m)
        {
                tn++;
                for(int i = m; i >= 1; i--)
                {
                        c[tn][i] = _state & 1;
                        _state /= 2;
                }
                num[tn] = N;
                return;
        }
        init(_dit + 1, _state * 2, N);
        if(!(_state & 1) && !((_state / 2) & 1))
                init(_dit + 1, _state * 2 + 1, N + 1);
}
 
bool _match[61][61];
 
int main()
{
        scanf("%d%d\n", &n, &m);
        init(0, 0, 0);
        rep(i, n)
        {
                rep(j, m)
                        g[i][j] = getchar() == 'P';
                getchar();
        }
        rep(i, tn)
                rep(j, tn)
                {
                        bool match = 1;
                        rep(k, m)
                                if(c[i][k] && c[j][k])
                                {
                                        match = 0;
                                        break;
                                }
                        _match[i][j] = match;
                }
        rep(i, n)
                rep(j, tn)
                {
                        bool match = 1;
                        rep(k, m)
                                if(!g[i][k] && c[j][k])
                                {
                                        match = 0;
                                        break;
                                }
                        if(!match)
                                continue;
                        rep(k, tn)
                        {
                                f[i][k][j] = 0;
                                if(i == 1)
                                        f[i][k][j] = num[j];
                                if(_match[k][j])
                                        rep(p, tn)
                                                if(_match[p][j])
                                                        f[i][k][j] = max(f[i][k][j], f[i - 1][p][k] + num[j]);
                        }
                }
        long long sum = 0;
        rep(i, tn)
                rep(j, tn)
                        sum = max(sum, f[n][i][j]);
        printf("%lld\n", sum);
}
 