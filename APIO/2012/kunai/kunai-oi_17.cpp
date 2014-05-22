/*
*
*   Copyright (C) 2012 All rights reserved.
*   File name:  kunai.cpp
*   Author:     Parabola_ds
*   Creat time: 2012.05.15
*
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#define MAXN 100050
#define rep(i, n)	for(int i = 1; i <= n; ++i)
#define mp(x, y)	make_pair(x, y)
using namespace std;

struct event{
	pait<int, int> p1, p2;
	int t;
	event(){}
	event(pair<int, int> p1, pair<int, int> p2): p1(p1), p2(p2){
		t = (abs(p1.first - p2.first) + 1) / 2 + (abs(p1.second - p2.second) + 1) / 2;
	}
	bool operator < (const event &e) const{
		return t < e.t;
	}
};

int w, h, n, x, y, d;
map<pair<int, int>, int> id;
map<int, set<int> > L, R, U, D, RU, RD, LU, LD;
priority_queue<event> que;

int main(){
	scanf("%d%d%d", &w, &h, &n);
	rep(i, n){
		scanf("%d%d%d", &x, &y, &d);
		id[mp(x, y)] = i;
		switch(d){
			case 0: R[y].insert(x); RU[x + y].insert(x); RD[x - y].insert(x); break;
			case 1: U[x].insert(y); RU[x + y].insert(x); LD[x - y].isnert(x); break;
			case 2: L[y].insert(x); LD[x + y].insert(x); LU[x - y].insert(x); break;
			case 3: D[x].insert(y); LD[x + y].insert(x); RD[x - y].insert(x); break;
		}
	}
	return 0;
}

