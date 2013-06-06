/*
* Copyright (C) 2012 All rights reserved.
* File name:  odl.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.13
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
#define MAXN 1000000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int prime[MAXN], a[MAXN], fn[MAXN + 10], n, pn, lim;
pair<pair<int, int>, pair<int, int> > g[MAXN + 10];
pair<int, int> ans;
bool isNotPrime[MAXN + 10];

void init(){
	for(int i = 2; i <= lim; ++i){
		if(!isNotPrime[i])
			prime[++pn] = i, fn[i] = 1;
		for(int j = 1; j <= pn && prime[j] * i <= lim; ++j){
			isNotPrime[prime[j] * i] = 1;
			fn[prime[j] * i] = fn[i] + 1;
			if(i % prime[j] == 0) break;
		}
	}
}

void add(int n, int p, int i){
	if(!g[p].first.second || g[p].first.first > fn[n / p])
		g[p].second = g[p].first,
		g[p].first = make_pair(fn[n / p], i);
	else if(!g[p].second.second || g[p].second.first > fn[n / p])
		g[p].second = make_pair(fn[n / p], i);
}

void get(int n, int p, int i){
	if(g[p].first.second != i && make_pair(g[p].first.first + fn[n / p], g[p].first.second) < ans)
		ans = make_pair(g[p].first.first + fn[n / p], g[p].first.second);
	else if(g[p].second.second && make_pair(g[p].second.first + fn[n / p], g[p].second.second) < ans)
		ans = make_pair(g[p].second.first + fn[n / p], g[p].second.second);
}

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]), lim = max(lim, a[i]);
	init();
	rep(i, n)
		for(int j = 1; j * j <= a[i]; ++j)
			if(a[i] % j == 0){
				add(a[i], j, i);
				if(j * j < a[i])
					add(a[i], a[i] / j, i);
			}
	rep(i, n){
		ans = make_pair(MAXN, MAXN);
		for(int j = 1; j * j <= a[i]; ++j)
			if(a[i] % j == 0){
				get(a[i], j, i);
				if(j * j < a[i])
					get(a[i], a[i] / j, i);
			}
		printf("%d\n", ans.second);
	}
	return 0;
}

