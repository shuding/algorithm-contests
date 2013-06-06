/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
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
#define MAXN 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a[MAXN + 10], ans1, ans2;

void dfs(int deep, int tot){
	if(tot > ans1){
		ans2 = ans1;
		ans1 = tot;
	}
	else if(tot > ans2)
		ans2 = tot;
	if(!deep) return;
	dfs(deep - 1, tot ^ a[deep]);
	dfs(deep - 1, tot);
}

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	dfs(n, 0);
	printf("%d %d\n", ans1, ans2);
	return 0;
}

