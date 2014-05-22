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

bool V[1001][1001];

struct event{
	pair<int, int> p1, p2;
	int t;
	event(){}
	event(pair<int, int> p1, pair<int, int> p2, int t): p1(p1), p2(p2), t(t){}
	bool operator < (const event &e) const{
		return t > e.t;
	}
};

struct segment{
	int l, r, u, d;
	segment(){}
	segment(int l, int r, int u, int d): l(l), r(r), u(u), d(d){}
} seg[MAXN];

struct line{
	int x, u, d;
	bool inout;
	line(){}
	line(int x, int u, int d, bool inout): x(x), u(u), d(d), inout(inout){}
	bool operator < (const line &l) const{
		return x < l.x;
	}
} l[MAXN * 2];

int w, h, n, x, y, d, tot, ln;
set<pair<int, int> > del, delNow;
multiset<pair<int, bool> > ms;
map<pair<int, int>, int> dir;
map<int, set<int> > L, R, U, D, LU, RU, LD, RD, UR, DR, UL, DL;
priority_queue<event> que;

int getR(int x, set<int> &L, set<int> &R){
	set<int>::iterator p, q;
	p = R.lower_bound(x);
	if(p == R.end()) return -1;
	q = L.lower_bound(*p);
	--q;
	if(*q != x) return -1;
	return *p;
}

int main(){
	scanf("%d%d%d", &w, &h, &n);

	rep(i, n){
		scanf("%d%d%d", &x, &y, &d);
		dir[mp(x, y)] = d;
		switch(d){
			case 0: R[y].insert(x); RU[x - y].insert(x); RD[x + y].insert(x); break;
			case 1: U[x].insert(y); UR[x - y].insert(x); UL[x + y].insert(x); break;
			case 2: L[y].insert(x); LD[x - y].insert(x); LU[x + y].insert(x); break;
			case 3: D[x].insert(y); DL[x - y].insert(x); DR[x + y].insert(x); break;
		}
	}

	map<int, set<int> >::iterator p;
	set<int>::iterator q;

	for(p = R.begin(); p != R.end(); ++p)
		for(q = p->second.begin(); q != p->second.end(); ++q){
			int l = *q, r = getR(*q, p->second, L[p->first]);
			if(r != -1)
				que.push(event(mp(l, p->first), mp(r, p->first), (r - l) / 2 + 1));
		}
	for(p = D.begin(); p != D.end(); ++p)
		for(q = p->second.begin(); q != p->second.end(); ++q){
			int l = *q, r = getR(*q, p->second, U[p->first]);
			if(r != -1)
				que.push(event(mp(p->first, l), mp(p->first, r), (r - l) / 2 + 1));
		}
	for(p = RD.begin(); p != RD.end(); ++p)
		for(q = p->second.begin(); q != p->second.end(); ++q){
			int l = *q, r = getR(*q, p->second, DR[p->first]);
			if(r != -1)
				que.push(event(mp(l, p->first - l), mp(r, p->first - r), r - l + 1));
		}
	for(p = RU.begin(); p != RU.end(); ++p)
		for(q = p->second.begin(); q != p->second.end(); ++q){
			int l = *q, r = getR(*q, p->second, UR[p->first]);
			if(r != -1)
				que.push(event(mp(l, l - p->first), mp(r, r - p->first), r - l + 1));
		}
	for(p = UL.begin(); p != UL.end(); ++p)
		for(q = p->second.begin(); q != p->second.end(); ++q){
			int l = *q, r = getR(*q, p->second, LU[p->first]);
			if(r != -1)
				que.push(event(mp(l, p->first - l), mp(r, p->first - r), r - l + 1));
		}
	for(p = DL.begin(); p != DL.end(); ++p)
		for(q = p->second.begin(); q != p->second.end(); ++q){
			int l = *q, r = getR(*q, p->second, LD[p->first]);
			if(r != -1)
				que.push(event(mp(l, l - p->first), mp(r, r - p->first), r - l + 1));
		}

	event it;
	while(!que.empty()){
		it = que.top();
		int value = it.t;
		delNow.clear();
		bool ok, del1, del2;
		while(!que.empty() && que.top().t == value){
			del1 = del.count(it.p1);
			del2 = del.count(it.p2);
			ok = (!del1 || delNow.count(it.p1)) && (!del2 || delNow.count(it.p2));
			if(ok){
				if(!del1){
					del.insert(it.p1);
					delNow.insert(it.p1);
					int d1 = dir[it.p1];
					switch(d1){
						case 0: seg[++tot] = segment(it.p1.first - 1, it.p1.first + it.t - 1, it.p1.second - 1, it.p1.second); break;
						case 1: seg[++tot] = segment(it.p1.first - 1, it.p1.first, it.p1.second - it.t, it.p1.second); break;
						case 2: seg[++tot] = segment(it.p1.first - it.t, it.p1.first, it.p1.second - 1, it.p1.second); break;
						case 3: seg[++tot] = segment(it.p1.first - 1, it.p1.first, it.p1.second - 1, it.p1.second + it.t - 1); break;
					}
				}
				if(!del2){
					del.insert(it.p2);
					delNow.insert(it.p2);
					int d2 = dir[it.p2];
					switch(d2){
						case 0: seg[++tot] = segment(it.p2.first - 1, it.p2.first + it.t - 1, it.p2.second - 1, it.p2.second); break;
						case 1: seg[++tot] = segment(it.p2.first - 1, it.p2.first, it.p2.second - it.t, it.p2.second); break;
						case 2: seg[++tot] = segment(it.p2.first - it.t, it.p2.first, it.p2.second - 1, it.p2.second); break;
						case 3: seg[++tot] = segment(it.p2.first - 1, it.p2.first, it.p2.second - 1, it.p2.second + it.t - 1); break;
					}
				}
			}
			que.pop();
			it = que.top();
		}
	}

	for(map<pair<int, int>, int>::iterator it = dir.begin(); it != dir.end(); ++it)
		if(!del.count((*it).first)){
			x = (*it).first.first;
			y = (*it).first.second;
			switch((*it).second){
				case 0: seg[++tot] = segment(x - 1, w, y - 1, y); break;
				case 1: seg[++tot] = segment(x - 1, x, 0, y); break;
				case 2: seg[++tot] = segment(0, x, y - 1, y); break;
				case 3: seg[++tot] = segment(x - 1, x, y - 1, h); break;
			}
		}
	rep(i, tot)
		l[++ln] = line(seg[i].l, seg[i].u, seg[i].d, 1),
		l[++ln] = line(seg[i].r, seg[i].u, seg[i].d, 0);
	sort(l + 1, l + 1 + ln);
	int lx = 0, ly, init;
	long long sum = 0, len = 0;

	rep(i, ln){
		sum += len * (long long)(l[i].x - lx);
		if(l[i].inout)
			ms.insert(mp(l[i].u, 1)),
			ms.insert(mp(l[i].d, 0));
		else
			ms.erase(ms.find(mp(l[i].u, 1))),
			ms.erase(ms.find(mp(l[i].d, 0)));
		init = 0;
		ly = 0;
		len = 0;
		for(multiset<pair<int, bool> >::iterator it = ms.begin(); it != ms.end(); ++it){
			if(init)
				len += (*it).first - ly;
			if((*it).second)
				init++;
			else
				init--;
			ly = (*it).first;
		}
		lx = l[i].x;
	}

	cout << sum << endl;

	event it;
	while(!que.empty()){
		it = que.top(); que.pop();
		cout << it.p1.first << "," << it.p1.second << " " << it.p2.first << "," << it.p2.second << " " << it.t << endl;
	}
	return 0;
}

