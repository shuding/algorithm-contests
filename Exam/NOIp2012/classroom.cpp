/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : NOIp_2012_Day2_Classroom.cpp
*	Creation Time : 2013/01/17 21:18:55
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 1000000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct query{
	int d, s, t;
} q[MAXN + 10];

int n, m;
int r[MAXN + 10], s[MAXN + 10], d[MAXN + 10];

bool check(int m){
	memset(d, 0, sizeof(d));
	rep(i, m)
		d[q[i].s] += q[i].d, d[q[i].t + 1] -= q[i].d;
	rep(i, n){
		s[i] = s[i - 1] + d[i];
		if(s[i] > r[i])
			return 0;
	}
	return 1;
}

int L, R, M;

int main(){
	freopen("classroom.in", "r", stdin);
	freopen("classroom.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, n)
		scanf("%d", &r[i]);
	rep(i, m)
		scanf("%d%d%d", &q[i].d, &q[i].s, &q[i].t);
	L = 0;
	R = m;
	while(L + 1 < R){
		M = (L + R) >> 1;
		if(check(M))
			L = M;
		else
			R = M;
	}
	if(check(R))
		M = R;
	else
		M = L;
	if (M == m)
		printf("0\n");
	else
		printf("%d\n%d\n", -1, M + 1);
	return 0;
}
