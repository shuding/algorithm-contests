/*
* Copyright (C) 2012 All rights reserved.
* File name:  C.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.03
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
#define MAXN 1000
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n;
long long x[MAXN + 10], y[MAXN + 10], a[2], b[2], k[2];
long long f[MAXN + 10][MAXN + 10], ans;

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%lld%lld", &x[i], &y[i]);
	rep(i, 2)
		scanf("%lld%lld%lld", &k[i - 1], &a[i - 1], &b[i - 1]);
	rep(i, n)
		for(int j = 0; j <= min(i, k[0]); ++j){
			if(j) f[i][j] = f[i - 1][j - 1] + x[i] * a[0] + y[i] * b[0];
			f[i][j] = max(f[i][j], f[i - 1][j] + x[i] * a[1] + y[i] * b[1]);
			ans = max(ans, f[i][j]);
		}
	printf("%lld\n", ans);
	return 0;
}

