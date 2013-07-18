/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : F.cpp
*   Creation Time : 2013/06/13 07:20:01
*   Environment   : OS X 10.8 & Vim 7.3
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int n, x, cntP, cntN;

int main(){
    freopen("positive.in", "r", stdin);
    freopen("positive.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        scanf("%d", &x), cntP += (x > 0), cntN += (x < 0);
    printf("%d\n", max(0, cntP - cntN));
    return 0;
}
