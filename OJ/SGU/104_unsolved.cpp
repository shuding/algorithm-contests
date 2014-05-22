/*
* Copyright (C) 2012 All rights reserved.
* File name:  104.cpp
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
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = 100000;

int f, v, a[101][101], dp[101][101];
bool pre[101][101];

void print(int i, int j){
	if(!i || !j) return;
	if(pre[i][j])
		print(i, j - 1);
	else{
		print(i - 1, j - 1);
		printf("%d", j);
		if(i < f) printf(" ");
	}
}

int main(){
	scanf("%d%d", &f, &v);
	rep(i, f)
		rep(j, v){
			scanf("%d", &a[i][j]);
			dp[i][j] = -inf;
		}
	rep(i, f)
		rep(j, v){
			if(dp[i][j - 1] > dp[i - 1][j - 1] + a[i][j])
				pre[i][j] = 1;
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + a[i][j]);
		}
	printf("%d\n", dp[f][v]);
	print(f, v);
	return 0;
}

