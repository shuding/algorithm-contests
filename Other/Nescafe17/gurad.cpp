#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 210
using namespace std;

int n, l, k, a[MAXN], b;
double p[2][200300];

int main(){
	scanf("%d%d%d", &n, &l, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	p[0][k + 200] = 1;
	for(int i = 1; i <= n; ++i){
		memset(p[i & 1], 0, sizeof p[i & 1]);
		scanf("%d", &b);
		for(int j = 0; j <= 1000 * n + 200; ++j){
			p[i & 1][j + b] += p[i & 1 ^ 1][j] * a[i] / 100;
			p[i & 1][j] += p[i & 1 ^ 1][j] * (100 - a[i]) / 100;
		}
	}
	double ans = 0;
	for(int i = 200; i <= 1000 * n + 200; ++i)
		ans += p[n & 1][i];
	printf("%.6lf\n", ans);
	return 0;
}

