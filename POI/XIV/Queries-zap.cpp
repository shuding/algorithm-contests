/*
* Copyright (C) 2012 All rights reserved.
* File name:  zap.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.29
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define MAXN 50000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int pn;
int mu[MAXN + 10];
long long prime[MAXN];
bool isNotPrime[MAXN + 10];

void init(){
	mu[1] = 1;
	for(long long i = 2; i <= MAXN; ++i){
		if(!isNotPrime[i]){
			prime[++pn] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= pn && prime[j] * i <= MAXN; ++j){
			isNotPrime[prime[j] * i] = 1;
			if(i % prime[j] != 0)
				mu[prime[j] * i] = -mu[i];
			else{
				mu[prime[j] * i] = 0;
				break;
			}
		}
	}
	rep(i, MAXN)
		mu[i] += mu[i - 1];
}

long long solve(int n, int m){
	long long sum = 0;
	for(int i = 1; i <= n; ++i){
		int next = min(n / (n / i), m / (m / i)) - i;
		sum += (mu[i + next] - mu[i - 1]) * (n / i) * (m / i);
		i += next;
	}
	return sum;
}

int main(){
	init();
	int testNum, n, m, k;
	scanf("%d", &testNum);
	while(testNum--){
		scanf("%d%d%d", &n, &m, &k);
		n /= k; m /= k;
		printf("%lld\n", solve(min(n, m), max(n, m)));
	}
	return 0;
}

