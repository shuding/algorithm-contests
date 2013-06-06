#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
long long k[10], p[10], tot;
long long h[5000000], num[5000000];

long long hash(long long n){
	int m = n;
	if(m < 0) m = - m;
	m = m % 4999317;
	while(h[m] && num[m] != n) ++m;
	if(!h[m]) num[m] = n;
	return m;
}

long long power(long long n, long long m){
	if(!m) return 1;
	long long tmp = power(n, m / 2); tmp *= tmp;
	if(m & 1) tmp *= n;
	return tmp;
}

void dfs(int i, long long sum){
	if(i * 2 > n){
		h[hash(sum)]++;
		return;
	}
	for(int j = 1; j <= m; ++j)
		dfs(i + 1, sum + k[i] * power(j, p[i]));
}

void _dfs(int i, long long sum){
	if(i <= n / 2){
		tot += h[hash(-sum)];
		return;
	}
	for(int j = 1; j <= m; ++j)
		_dfs(i - 1, sum + k[i] * power(j, p[i]));
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld", &k[i], &p[i]);
	dfs(1, 0);
	_dfs(n, 0);
	printf("%lld\n", tot);
	return 0;
}
