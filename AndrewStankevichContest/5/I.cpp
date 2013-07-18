/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : I.cpp
*   Creation Time : 2013/07/15 01:48:50
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

int n, m, p, a[10000], b[10000];

void handle(int v, int t){
    if(t > m)
        return;
    if((a[t] >> v) % 4 == 1 || (a[t] >> v) % 4 == 2){
        printf("%d ", a[t] + 1);
        handle(v, t + 1);
        printf("%d ", a[t] + 1);
        b[++p] = a[t];
    }
    else{
        printf("%d %d ", a[t] + 1, a[t] + 1);
        b[++p] = a[t];
        handle(v, t + 1);
    }
}

int main(){
    freopen("railsort.in", "r", stdin);
    freopen("railsort.out", "w", stdout);
    cin >> n;
    m = (1 << n);
    rep(i, m){
        scanf("%d", &a[i]);
        a[i]--;
    }
    rep(i, n){
        p = 0;
        handle(i - 1, 1);
        memcpy(a, b, sizeof b);
    }
    return 0;
}
