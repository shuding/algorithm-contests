/*
* Copyright (C) 2012 All rights reserved.
* File name:  GSS1.cpp
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
#define MAXN 50000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, l, r;

struct segmentTree{
	segmentTree *c[2];
	int l, r, value, maxn, maxl, maxr, sum;
	void update(){
		maxn = max(c[0]->maxn, c[1]->maxn);
		maxn = max(maxn, c[0]->maxr + c[1]->maxl);
		maxn = max(maxn, max(c[0]->maxr, c[1]->maxl));
		maxl = max(c[0]->maxl, c[0]->sum + c[1]->maxl);
		maxr = max(c[1]->maxr, c[1]->sum + c[0]->maxr);
		sum = c[0]->sum + c[1]->sum;
	}
	void build(int L, int R){
		l = L; r = R;
		if(l == r){
			scanf("%d", &value);
			maxl = maxr = maxn = sum = value;
			return;
		}
		int mid = (l + r) >> 1;
		c[0] = new segmentTree;
		c[1] = new segmentTree;
		c[0]->build(L, mid);
		c[1]->build(mid + 1, R);
		update();
	}
	int queryLeftMax(int R){
		if(r == R) return maxl;
		int m = (l + r) >> 1;
		int ret = c[0]->queryLeftMax(min(m, R));
		if(R > m)
			ret = max(ret, c[0]->sum + c[1]->queryLeftMax(R));
		return ret;
	}
	int queryRightMax(int L){
		if(l == L) return maxr;
		int m = (l + r) >> 1;
		int ret = c[1]->queryRightMax(max(m + 1, L));
		if(L <= m)
			ret = max(ret, c[1]->sum + c[0]->queryRightMax(L));
		return ret;
	}
	int queryMax(int L, int R){
		if(l == L && r == R)
			return maxn;
		int m = (l + r) >> 1;
		if(R <= m) return c[0]->queryMax(L, R);
		if(L >  m) return c[1]->queryMax(L, R);
		int ret = max(c[0]->queryMax(L, m), c[1]->queryMax(m + 1, R));
		ret = max(ret, c[0]->queryRightMax(L) + c[1]->queryLeftMax(R));
		return ret;
	}
} T;

int main(){
	scanf("%d", &n);
	T.build(1, n);
	scanf("%d", &m);
	while(m--){
		scanf("%d%d", &l, &r);
		printf("%d\n", T.queryMax(l, r));
	}
	return 0;
}
