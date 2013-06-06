/*
* Copyright (C) 2012 All rights reserved.
* File name:  B.cpp
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
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k, fa[MAXN + 10];
double x[MAXN + 10], y[MAXN + 10], z[MAXN + 10];

int father(int i){
	return fa[i] == i ? i : fa[i] = father(fa[i]);
}

double dis(int i, int j){
	return (x[i] - x[j]) * (x[i] - x[j])
		 + (y[i] - y[j]) * (y[i] - y[j])
		 + (z[i] - z[j]) * (z[i] - z[j]);
}

bool check(double m){
	int tot = n;
	rep(i, n) fa[i] = i;
	rep(i, n)
		rep(j, i - 1)
			if(dis(i, j) < m){
				int f1 = father(i), f2 = father(j);
				if(f1 != f2)
					fa[father(i)] = father(j), tot--;
			}
	return tot >= k;
}

int main(){
	scanf("%d%d", &n, &k);
	rep(i, n)
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	double l = 0.0, r = 3.0, m;
	while(l + 1e-6 < r){
		m = (l + r) / 2.0;
		if(check(m))
			l = m;
		else
			r = m;
	}
	printf("%.6lf\n", m);
	return 0;
}

