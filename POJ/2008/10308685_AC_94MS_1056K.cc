/*
* Copyright (C) 2012 All rights reserved.
* File name:  1071.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.08
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
#define MAXN 5000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct data{
	int first, second;
	inline bool operator < (const data &d) const{
		return first < d.first;
	}
} hr[MAXN + 10], hsr[MAXN + 10];

int n, st, tot, ans, sum[100010];
int a, b, c, h[MAXN + 10], s[MAXN + 10];

inline void read(int &n){
	char c = getchar(); n = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
}

int main(){
	read(n); read(a); read(b); read(c);
	rep(i, n){
		read(h[i]); read(s[i]);
		hr[i].first = h[i];
		hr[i].second = i;
		hsr[i].first = h[i] * a + s[i] * b;
		hsr[i].second = i;
	}
	sort(hr + 1, hr + 1 + n);
	sort(hsr + 1, hsr + 1 + n);
	rep(i, n){
		if(s[i] == s[i - 1]) continue;
		st = 1;
		tot = 0;
		rep(j, n){
			if(hr[j].first == hr[j - 1].first) continue;
			tot -= sum[hr[j - 1].first];
			sum[hr[j - 1].first] = 0;
			int value = a * hr[j].first + b * s[i] + c;
			while(st <= n && hsr[st].first <= value){
				if(s[hsr[st].second] >= s[i] && h[hsr[st].second] >= hr[j].first){
						tot++;
						sum[h[hsr[st].second]]++;
					}
				st++;
			}
			ans = max(ans, tot);
		}
	}
	printf("%d\n", ans);
	return 0;
}
