#include <algorithm>
#include <iostream>
#include <cstdio>
#define MAXX 1000001
using namespace std;

int n, m, x, t[MAXX], st[MAXX];
long long tot, top, ans[MAXX];

int main(){
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &x), t[x] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		for(int j = 1; j <= x && st[x] + x < MAXX; ++j){
			st[x] += x;
			if(t[st[x]] >= 0){
				if(t[st[x]])
					ans[++tot] = top + j;
				t[st[x]] = -1;
			}
			else
				j--;
		}
		top += x;
	}
	printf("%lld\n", tot);
	for(int i = 1; i <= tot; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}
