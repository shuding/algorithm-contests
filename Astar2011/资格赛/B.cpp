/*
* Copyright (C) 2012 All rights reserved.
* File name:  B.cpp
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

int n, k, m, tot;

int main(){
	scanf("%d", &n);
	while(n--){
		tot = 1;
		scanf("%d", &k);
		rep(i, k)
			scanf("%d", &m), tot += m;
		printf("%d\n", tot - k);
	}
	return 0;
}

