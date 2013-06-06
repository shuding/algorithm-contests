/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.10
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
#define MAXK 50
#define MAXN 150000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k, d, m, l[MAXN + 10], r[MAXK + 10][MAXN + 10];
int x[MAXN * MAXK + 10], y[MAXN * MAXK + 10];

int main(){
	scanf("%d%d%d%d", &n, &k, &d, &m);
	rep(i, n)
		scanf("%d", &l[i]);
	rep(i, k)
		rep(j, n)
			scanf("%d", &r[j][i]);
	rep(i, m)
		scanf("%d%d", &x[i], &y[i]);
	return 0;
}

