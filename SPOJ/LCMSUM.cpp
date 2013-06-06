#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int LIM, n[300010];
int pn, prime[1000010];
long long g[1000010];
bool inp[1000010];

void init(){
	g[1] = 1;
	for(int i = 2; i < LIM; ++i){
		if(!inp[i]){
			prime[++pn] = i, g[i] = i - 1;
			g[i] *= i; g[i] += 1;
		}
		for(int j = 1; j <= pn && i * prime[j] < LIM; ++j){
			inp[i * prime[j]] = 1;
			if(i % prime[j] == 0){
				g[i * prime[j]] = g[i] + (g[i] - g[i / prime[j]]) * prime[j] * prime[j];
				break;
			}
			else
				g[i * prime[j]] = g[i] * g[prime[j]];
		}
	}
}

inline void read(int &n){
	char c = getchar(); n = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		read(n[i]);
		LIM = max(LIM, n[i]);
	}
	LIM++;
	init();
	for(int i = 1; i <= t; ++i)
		printf("%lld\n", (g[n[i]] + 1) * n[i] / 2);
	return 0;
}