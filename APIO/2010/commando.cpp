/*
*
*   Copyright (C) 2012 All rights reserved.
*   File name:  commando.cpp
*   Author:     Parabola_ds
*   Creat time: 2012.04.29
*
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 1000050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

typedef long long int64;

int n;
int64 a, b, c, s[MAXN], f[MAXN];
pair<int64, int64> st[MAXN];

int64 calc(int64 x){
	return a * x * x + b * x + c;
}

int64 _calc(int64 x){
	return a * x * x - b * x;
}

int main(){
	cin >> n >> a >> b >> c;
	rep(i, n){
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}
	f[1] = calc(s[1]);
	int p, q;
	st[p = q = 1] = make_pair(a * s[1], f[1] + _calc(s[1]));
	rep(i, n){
		int64 k = 2 * s[i];
		while(p < q && st[p].first - st[p + 1].first <= k * (st[p].second - st[p + 1].second)) ++p;
		f[i] = f[st[p]] + cal(s[i] - s[st[p]]);
		int64 dx = a * s[i], dy = f[i] + _calc(s[i]);
		while(p < q && )
	}
	return 0;
}

