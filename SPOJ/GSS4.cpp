/*
* Copyright (C) 2012 All rights reserved.
* File name:  GSS4.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.21
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#define MAXN 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, cmd, l, r, next[MAXN + 10];
long long num[MAXN + 10];
long long e[MAXN + 10];

void init(){
	memset(e, 0, sizeof(e));
}

void modify(int p, long long x){
	for(; p <= n; p += p & -p)
		e[p] += x;
}

long long sum(int p){
	long long s = 0;
	for(; p; p -= p & -p)
		s += e[p];
	return s;
}

void rangeSqrt(int l, int r){
	long long tmp;
	while(l <= r){
		tmp = num[l];
		num[l] = (long long)sqrt(num[l]);
		modify(l, num[l] - tmp);
		if(num[next[l]] == 1)
			next[l] = next[next[l]];
		l = next[l];
	}
}

int main(){
	int testNum = 0;
	while(scanf("%d", &n) != EOF){
		init();
		rep(i, n){
			scanf("%lld", &num[i]);
			modify(i, num[i]);
			next[i] = i + 1;
		}
		
		scanf("%d", &m);
		printf("Case #%d:\n", ++testNum);
		while(m--){
			scanf("%d%d%d", &cmd, &l, &r);
			if(l > r) swap(l, r);
			if(cmd)
				printf("%lld\n", sum(r) - sum(l - 1));
			else
				rangeSqrt(l, r);
		}
		puts("");
	}
	return 0;
}
