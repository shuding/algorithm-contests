/*
* Copyright (C) 2012 All rights reserved.
* File name:  D.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.29
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
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int t, h, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d:%d", &h, &m);
		if(m){
			puts("0");
			continue;
		}
		if(h <= 12)
			h += 12;
		else
			h -= 12;
		printf("%d\n", h);
	}
	return 0;
}
