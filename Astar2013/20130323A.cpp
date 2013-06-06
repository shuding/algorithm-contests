/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : 20130323A.cpp
*	Creation Time : 2013/03/23 20:23:25
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define MAXN 10010
using namespace std;

int n, k;
long long l, r, mid, t[MAXN];

bool check(long long len){
	int las = 0, tot = 1;
	for(int i = 1; i <= n; ++i){
		if(t[i] - t[las] > len){
			las = i - 1;
			tot++;
		}
	}
	return tot <= k;
}

void read(long long &n){
	char c = getchar(); n = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
}

int main(){
	while(scanf("%d%d", &n, &k), n + k > 0){
		for(int i = 1; i <= n; ++i)
			read(t[i]), t[i] += t[i - 1];
		l = 0; r = t[n];
		while(l + 1 < r){
			mid = (l + r) >> 1;
			if(check(mid))
				r = mid;
			else
				l = mid;
		}
		if(check(l))
			r = l;
		cout << r << endl;
	}
}
