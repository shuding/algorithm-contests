#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1002
#define MAXM 12
#define rep(i, s, t) for(int i = s; i <= t; ++i)
using namespace std;

int n, m;
double e[MAXN][MAXM], mul[MAXN][MAXM][MAXN];
double f[MAXN][MAXM][MAXN], g[MAXN][MAXM][MAXN], s[MAXM][MAXN], sl1[MAXN][MAXN], sl2[MAXN][MAXN];

int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		rep(j, 1, m){
			scanf("%lf", &e[i][j]);
			mul[i][j][1] = e[i][j];
		}
	rep(i, 1, n)
		rep(j, 1, m)
			rep(k, 2, i)
				mul[i][j][k] = mul[i - 1][j][k - 1] * e[i][j];
	rep(i, 1, m)
		rep(j, 1, n)
			s[i][j] = 1;
	rep(i, 0, n)
		sl1[0][i] = 1;
	rep(i, 1, n){
		rep(j, 1, m)
			rep(k, 1, n){
				s[j][k] *= e[i][j];
				f[i][j][k] = s[j][k];
				if(i >= k)
					s[j][k] -= mul[i][j][k] * (sl1[i - k][k] - f[i - k][j][k]);
				sl1[i][k] += f[i][j][k];
			}
		rep(j, 1, m)
			rep(k, 1, n)
				s[j][k] += sl1[i][k] - f[i][j][k];
	}
	rep(i, 1, m)
		rep(j, 1, n)
			s[i][j] = 1;
	rep(i, 0, n)
		sl2[n + 1][i] = 1;
	for(int i = n; i; --i){
		rep(j, 1, m)
			rep(k, 1, n){
				s[j][k] *= e[i][j];
				g[i][j][k] = s[j][k];
				if(i + k - 1 <= n)
					s[j][k] -= mul[i + k - 1][j][k] * (sl2[i + k][k] - g[i + k][j][k]);
				sl2[i][k] += g[i][j][k];
			}
		rep(j, 1, m)
			rep(k, 1, n)
				s[j][k] += sl2[i][k] - g[i][j][k];
	}
	double ans = 0;
	rep(i, 1, n)
		rep(j, 1, m)
			rep(k, 1, i)
				ans += mul[i][j][k] * (sl1[i - k][k - 1] - f[i - k][j][k - 1]) * (sl2[i + 1][k] - g[i + 1][j][k]) * k;
	printf("%.6lf\n", ans);
	return 0;
}