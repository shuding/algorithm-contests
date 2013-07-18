/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/07/12 13:30:12
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

int n, a, b, t, tot, cnt, c[12][5000];

void next(){
    if(a)
        b = 1 - b;
    a = 1 - a;
}

void init(){
    for(int i = 0; i < 12; i += 2){
        a = b = t = 0;
        t = 4;
        if(i)
            cnt = (1 << (i - 2));
        else
            cnt = 4096;
        tot = cnt;
        rep(j, 4096){
            c[i][j] = a;
            c[i + 1][j] = b;
            next();
            --tot;
            if(!tot){
                --t;
                if(!t){
                    next();
                    t = 4;
                }
                tot = cnt;
            }
        }
    }
}

int main(){
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    init();
    cin >> n;
    rep(i, (1 << n)){
        rep(j, n)
            printf("%d", c[j - 1][i]);
        puts("");
    }
    return 0;
}
