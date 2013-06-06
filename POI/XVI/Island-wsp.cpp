/*
* Copyright (C) 2012 All rights reserved.
* File name:  Island.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.10
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cmath>
#define MAXN 100050
#define MAXM 1000050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const double inf = 1e20, eps = 1e-9;

struct point{
	double x, y;
} p[MAXN];

struct edge{
	int a, b;
	bool operator < (const edge e) const{
		return a < e.a || (a == e.a && b < e.b);
	}
} e[MAXM];

struct line{
	point a, b;
	line(){}
	line(point a, point b): a(a), b(b){}
};

stack<line> st;
double tot = 0;

double dis(point a, point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point cross(line a, line b){
	double t = (a.a.x - a.b.x) * (b.a.y - b.b.y) - (a.a.y - a.b.y) * (b.a.x - b.b.x);
	double s = (b.b.x - a.b.x) * (b.a.y - b.b.y) - (b.b.y - a.b.y) * (b.a.x - b.b.x);
	double e = s / t;
	point ret;
	ret.x = e * a.a.x + (1 - e) * a.b.x;
	ret.y = e * a.a.y + (1 - e) * a.b.y;
	return ret;
}

int det(point a, point b, point c){
	double ret = a.x * (b.y - c.y) + c.x * (a.y - b.y) + b.x * (c.y - a.y);
	return ret < -eps ? -1 : ret > eps;
}

int n, m, x, y, plink[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	rep(i, m){
		scanf("%d%d", &e[i].a, &e[i].b);
		if(e[i].a > e[i].b) swap(e[i].a, e[i].b);
	}
	sort(e + 1, e + 1 + m);
	int i = m, _p = n - 1;
	while(i && _p){
		int j = n;
		while(e[i].a > _p) --i;
		while(e[i].a == _p && e[i].b == j)
			--i, --j;
		plink[_p] = j > _p ? j : 0;
		--_p;
	}
	rep(i, n - 1)
		if(plink[i]){
			point c;
			if(!st.empty() && det(st.top().a, st.top().b, p[plink[i]]) != -1) continue;
			while(!st.empty()){
				c = cross(st.top(), line(p[i], p[plink[i]]));
				if(det(st.top().a, c, p[plink[i]]) == -1){
					st.top().b = c;
					st.push(line(c, p[plink[i]]));
					break;
				}
				else st.pop();
			}
			if(st.empty())
				st.push(line(p[i], p[plink[i]]));
		}
	while(!st.empty()){
		tot += dis(st.top().a, st.top().b);
		st.pop();
	}
	printf("%.10lf\n", tot);
	return 0;
}

