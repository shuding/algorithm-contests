/*
* Copyright (C) 2012 All rights reserved.
* File name:  difference.cpp
* Author:     Ding Shu
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
#define MAXN 1000000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

char s[MAXN + 10];
int n, ans, nowItem[30], minItem[30][30], c[MAXN + 10], minSum[MAXN + 10], mPos[MAXN + 10], exist[30];
int next[MAXN + 10], cTop[30];

int calc(int a, int b){
	int tot = 0, sum = 0, ret = 0, top = 0, p, t1 = cTop[a], t2 = cTop[b];
	while(t1 || t2)
		if(!t1)
			c[++tot] = -1, t2 = next[t2];
		else
			if(!t2)
				c[++tot] = 1, t1 = next[t1];
			else{
				c[++tot] = t1 < t2 ? 1 : -1;
				if(t1 < t2) t1 = next[t1]; else t2 = next[t2];
			}
	rep(i, tot){
		sum += c[i];
		p = top;
		while(p >= 0 && sum - minSum[p] == i - mPos[p]) --p;
		if(p >= 0) ret = max(ret, sum - minSum[p]);
		if(sum < minSum[top]){
			minSum[++top] = sum;
			mPos[top] = i;
		}
	}
	return ret;
}

int main(){
	scanf("%d\n", &n);
	scanf("%s", s);
	for(int i = n; i; --i){
		next[i] = cTop[s[i - 1] - 'a'];
		cTop[s[i - 1] - 'a'] = i;
	}
	rep(i, n)
		exist[s[i - 1] - 'a']++;
	rep(i, 26) if(exist[i - 1])
		rep(j, 26) if(exist[j - 1] && i != j && exist[i - 1] - 1 > ans)
			ans = max(ans, calc(i - 1, j - 1));
	printf("%d\n", ans);
	return 0;
}

