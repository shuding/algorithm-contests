/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : classroom.cpp
*	Creation Time : 2013/01/17 21:18:11
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl
#define MAXN 1000050
using namespace std;

struct node{
	int l, r, p, d, c[2];
} t[MAXN * 2];

int n, m, R[MAXN], D, S, T, tn = 1;

void pushdown(int v){
	t[t[v].c[0]].d += t[v].d;
	t[t[v].c[0]].p -= t[v].d;
	t[t[v].c[1]].d += t[v].d;
	t[t[v].c[1]].p -= t[v].d;
	t[v].d = 0;
}

void updata(int v){
	t[v].p = min(t[t[v].c[0]].p, t[t[v].c[1]].p);
}

void build(int v, int l, int r){
	t[v].l = l; t[v].r = r;
	if(l == r){
		t[v].p = R[l];
		t[v].c[0] = t[v].c[1] = 0;
		t[v].d = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(t[v].c[0] = ++tn, l, m);
	build(t[v].c[1] = ++tn, m + 1, r);
	updata(v);
}

bool add(int v, int l, int r, int d){
	if(l == t[v].l && r == t[v].r){
		t[v].d += d;
		t[v].p -= d;
		return t[v].p >= 0;
	}
	pushdown(v);
	int m = (t[v].l + t[v].r) >> 1;
	bool ret;
	if(r <= m)
		ret = add(t[v].c[0], l, r, d);
	else if(l > m)
		ret = add(t[v].c[1], l, r, d);
	else
		ret = add(t[v].c[0], l, m, d) & add(t[v].c[1], m + 1, r, d);
	updata(v);
	return ret;
}

int main(){
	freopen("classroom.in", "r", stdin);
	freopen("classroom.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, n)
		scanf("%d", &R[i]);
	build(1, 1, n);
	rep(i, m){
		scanf("%d%d%d", &D, &S, &T);
		if(!add(1, S, T, D)){
			printf("-1\n%d\n", i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
