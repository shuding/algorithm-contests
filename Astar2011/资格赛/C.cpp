/*
* Copyright (C) 2012 All rights reserved.
* File name:  C.cpp
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

double m, tot;

int main(){
	rep(i, 12){
		scanf("%lf", &m);
		tot += m;
	}
	printf("$%.2lf\n", tot / 12.0);
	return 0;
}
