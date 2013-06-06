/*
* Copyright (C) 2012 All rights reserved.
* File name:  GSS2.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.22
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
#define LIMIT 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct query{
	int l, r, id;
	bool operator < (const query q) const{
		return r < q.r;
	}
} q[LIMIT + 10];

int n, m, tot, a[LIMIT + 10];
int top[LIMIT * 2 + 10], pre[LIMIT + 10];
long long ans[LIMIT + 10];

struct node{
	int l, r, c[2];
	long long mmax, _max, add, madd;
	void init(int L, int R){
		l = L, r = R;
		mmax = _max = add = madd = c[0] = c[1] = 0;
	}
} t[LIMIT * 2 + 10];

void Tinit(int n, int l, int r){
	t[n].init(l, r);
	if(l == r) return;
	int m = (l + r) >> 1;
	Tinit(t[n].c[0] = ++tot, l, m);
	Tinit(t[n].c[1] = ++tot, m + 1, r);
}

void Tdown(int n){
	int l = t[n].c[0], r = t[n].c[1];
	t[l].madd = max(t[l].madd, t[l].add + t[n].madd);
	t[r].madd = max(t[r].madd, t[r].add + t[n].madd);
	t[l].add += t[n].add;
	t[r].add += t[n].add;
	t[n].add = t[n].madd = 0;
}

void Tupdate(int n){
	int l = t[n].c[0], r = t[n].c[1];
	t[n].mmax = max(t[l].mmax + t[l].add, t[r].mmax + t[r].add);
	t[n]._max = max(max(t[l]._max, t[l].mmax + t[l].madd), max(t[r]._max, t[r].mmax + t[r].madd));
}

void Tadd(int n, int l, int r, long long a){
	if(l == t[n].l && r == t[n].r){
		t[n].add += a;
		t[n].madd = max(t[n].madd, t[n].add);
		return;
	}
	Tdown(n);
	int m = (t[n].l + t[n].r) >> 1;
	if(r <= m)
		Tadd(t[n].c[0], l, r, a);
	else
		if(l > m)
			Tadd(t[n].c[1], l, r, a);
		else{
			Tadd(t[n].c[0], l, m, a);
			Tadd(t[n].c[1], m + 1, r, a);
		}
	Tupdate(n);
}

long long Tquery(int n, int l, int r){
	if(l == t[n].l && r == t[n].r)
		return max(t[n]._max, t[n].mmax + t[n].madd);
	Tdown(n);
	Tupdate(n);
	int m = (t[n].l + t[n].r) >> 1;
	if(r <= m)
		return Tquery(t[n].c[0], l, r);
	else
		if(l > m)
			return Tquery(t[n].c[1], l, r);
		else
			return max(Tquery(t[n].c[0], l, m), Tquery(t[n].c[1], m + 1, r));
}

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d", &a[i]);
		pre[i] = top[a[i] + LIMIT];
		top[a[i] + LIMIT] = i;
	}
	scanf("%d", &m);
	rep(i, m)
		scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	sort(q + 1, q + 1 + m);
	int top = 1;
	Tinit(tot = 1, 1, n);
	rep(i, n){
		Tadd(1, pre[i] + 1, i, a[i]);
		while(top <= m && q[top].r == i){
			ans[q[top].id] = Tquery(1, q[top].l, q[top].r);
			top++;
		}
	}
	rep(i, m)
		printf("%lld\n", ans[i]);
	return 0;
}
