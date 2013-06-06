/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : mod.cpp
*	Creation Time : 2013/01/14 21:59:07
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

long long a, b, x, y;

void solve(long long a, long long b){
	if(!b){
		x = 1;
		y = 0;
		return;
	}
	solve(b, a % b);
	long long tmp = y;
	y = x - (a / b) * y;
	x = tmp;
}

int main(){
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	cin >> a >> b;
	solve(a, b);
	while(x <= 0) x += b;
	cout << x << endl;
	return 0;
}
