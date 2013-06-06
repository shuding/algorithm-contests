/*
* Copyright (C) 2012 All rights reserved.
* File name:  CTGAME.cpp
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
#define MAXN 1000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
 
int n, m, testNum, h[MAXN + 10], l[MAXN + 10], r[MAXN + 10];
bool g[MAXN + 10][MAXN + 10];
 
int main(){
	scanf("%d", &testNum);
	while(testNum--){
		scanf("%d%d", &n, &m);
		int ans = 0;
		char c;
		rep(i, n){
			rep(j, m){
				c = getchar();
				while(c != 'F' && c != 'R')
					c = getchar();
				g[i][j] = c == 'F';
			}
		}
		memset(h, 0, sizeof(h));
		rep(i, n){
			rep(j, m)
				if(g[i][j])
					h[j]++;
				else
					h[j] = 0;
			l[1] = 1;
			r[m] = m;
			for(int j = 2; j <= m; ++j)
				if(h[j - 1] >= h[j])
					l[j] = l[j - 1];
				else
					l[j] = j;
			for(int j = m - 1; j; --j)
				if(h[j] <= h[j + 1])
					r[j] = r[j + 1];
				else
					r[j] = j;
			rep(j, m)
				ans = max(ans, (r[j] - l[j] + 1) * h[j]);
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}
