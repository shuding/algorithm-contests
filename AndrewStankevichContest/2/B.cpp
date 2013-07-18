/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/06/12 15:16:47
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

const int inf = 1000000;

int n, m;
int f[70][70], g[70][70], no[70];
vector<int> top[70];

int solve(int n, int m){
    if(n < 2)
        return n;
    if(m < 3)
        return inf;
    if(f[n][m])
        return f[n][m];
    f[n][m] = inf;
    rep(k, n - 1){
        int tmp = solve(k, m) * 2 + solve(n - k, m - 1);
        if(tmp < f[n][m])
            f[n][m] = tmp, g[n][m] = k;
    }
    return f[n][m];
}

void print(int st, int ed, int l, int r){
    if(st > ed)
        return;
    if(st == ed){
        printf("move %d from %d to %d", st, no[l], no[r]);
        if(!top[no[r]].empty())
            printf(" atop %d\n", top[no[r]].back());
        else
            puts("");
        top[no[l]].pop_back();
        top[no[r]].push_back(st);
        return;
    }
    swap(no[r - 1], no[r]);
    print(st, st + g[ed - st + 1][r - l + 1] - 1, l, r);
    print(st + g[ed - st + 1][r - l + 1], ed, l, r - 1);
    swap(no[r - 1], no[r]);
    swap(no[l], no[r - 1]);
    print(st, st + g[ed - st + 1][r - l + 1] - 1, l, r);
    swap(no[l], no[r - 1]);
}

int main(){
    freopen("hanoi.in", "r", stdin);
    freopen("hanoi.out", "w", stdout);
    scanf("%d%d", &n, &m);
    rep(i, m) no[i] = i;
    rep(i, n) top[1].push_back(n + 1 - i);
    cout << solve(n, m) << endl;
    print(1, n, 1, m);
    return 0;
}
