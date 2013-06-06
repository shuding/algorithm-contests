/***************************************************
*
*   Copyright (C) 2012 All rights reserved.
*   File name:  slo.cpp
*   Author:     Parabola_ds
*   Creat time: 2012.04.18
*
***************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1000050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const long long inf = ~0U >> 1;

inline void read(long long &n){
	char c = getchar(); n = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
}

long long n, __min(1), ans(0), tmp;
long long score[MAXN], a[MAXN], b[MAXN], v[MAXN];

int main(){
	read(n);
	rep(i, n){
		read(score[i]);
		if(score[__min] > score[i])
			__min = i;
	}
	rep(i, n) read(tmp), a[tmp] = i;
	rep(i, n) read(b[i]);
	rep(i, n)
		if(!v[i]){
			long long j(i), m(b[i]), _ans(0), __ans(0);
			while(!v[j]){
				v[j]++;
				if(score[m] > score[b[j]])
					m = b[j];
				j = a[b[j]];
			}
			while(v[j] == 1){
				v[j]++;
				if(b[j] != m)
					_ans += score[m] + score[b[j]];
				if(b[j] != __min)
					__ans += score[b[j]] + score[__min];
				j = a[b[j]];
			}
			if(__min != m)
				__ans += score[m] + score[__min];
			ans += min(_ans, __ans);
		}
	cout << ans << endl;
	return 0;
}

