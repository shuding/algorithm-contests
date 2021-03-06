/*
* Copyright (C) 2012 All rights reserved.
* File name:  signaling.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.14
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
#define MAXN 2000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct point{
	double x, y;
} p[MAXN * 2];

int n, tot, x[MAXN], y[MAXN];
double ans;

inline double C(double n, int m){
	if(n < m) return 0;
	if(m == 2)
		return n * (n - 1) / 2;
	if(m == 3)
		return n * (n - 1) / 2 * (n - 2) / 3;
	return n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
}

inline void qSort(int l, int r){
	int i = l, j = r;
	point m = p[(l + r) >> 1];
	do{
		while(p[i].x * m.y - p[i].y * m.x > 0)
			i++;
		while(p[j].x * m.y - p[j].y * m.x < 0)
			j--;
		if(i <= j)
			swap(p[i], p[j]), i++, j--;
	}while(i <= j);
	if(i < r) qSort(i, r);
	if(j > l) qSort(l, j);
}

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%d%d", &x[i], &y[i]);
	rep(i, n){
		tot = 0;
		rep(j, n) if(i != j){
			tot++;
			p[tot].x = x[j] - x[i];
			p[tot].y = y[j] - y[i];
		}
		qSort(1, tot);
		rep(j, tot)
			p[j + tot] = p[j];
		double sum = 0;
		int range = 2;
		rep(j, tot){
			while(p[range].x * p[j].y - p[j].x * p[range].y < 0) range++;
			sum += C(range - j - 1, 2);
		}
		ans += sum;
	}
	ans = 2 * C(n, 4) - C(n - 1, 3) * n + ans;
	printf("%.6lf\n", ans / C(n, 3) + 3);
	return 0;
}

