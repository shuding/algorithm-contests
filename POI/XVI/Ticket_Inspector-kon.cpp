/*
* Copyright (C) 2012 All rights reserved.
* File name:  kon.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.20
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
#define MAXK 50
#define MAXN 600
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = ~0U >> 1;

int n, k;
long long s[MAXN + 10][MAXN + 10], f[MAXK + 10][MAXN + 10], pre[MAXK + 10][MAXN + 10];

void print(int v, int k){
	if(!k) return;
	print(pre[k][v], k - 1);
	printf("%d ", v);
}

int main(){
	scanf("%d%d", &n, &k); n--;
	rep(i, n){
		rep(j, n - i + 1)
			scanf("%lld", &s[i][i + j - 1]);
		for(int j = n; j >= i; --j)
			s[i][j] += s[i - 1][j] + s[i][j + 1] - s[i - 1][j + 1];
	}

	rep(i, k)
		rep(j, n + 1)
			f[k][j - 1] = -inf;
	f[0][0] = 0;

	rep(i, k)
		rep(j, n)
			rep(t, j)
				if(f[i][j] <= f[i - 1][t - 1] + s[j][j] - s[t - 1][j])
					f[i][j] = f[i - 1][t - 1] + s[j][j] - s[t - 1][j], pre[i][j] = t - 1;

	int ans = 0;
	rep(i, n)
		if(f[k][i] >= f[k][ans])
			ans = i;

	print(ans, k); puts("");

	return 0;
}

