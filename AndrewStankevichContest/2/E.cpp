/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : E.cpp
*   Creation Time : 2013/06/18 04:34:39
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
#define MAXN 1010
#define MAXM 150
using namespace std;

const int inf = ~0u >> 2;
int n, m, s, ans, a[MAXN], b[MAXM][MAXM], f[MAXN][MAXM], g[MAXN][MAXM];

void print(int v, int ans){
    if(!v)
        return;
    print(v - 1, g[v][ans]);
    printf("%d ", ans - 1);
}

int main(){
    freopen("quant.in", "r", stdin);
    freopen("quant.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        scanf("%d", &a[i]);
    scanf("%d%d", &m, &s);
    rep(i, m)
        rep(j, s)
            scanf("%d", &b[i][j]);
    rep(i, n)
        rep(j, s){
            f[i][j] = inf;
            rep(k, (i == 1 ? 1 : s))
                if(f[i][j] > f[i - 1][k] + abs(a[i] - b[(k - 1) % m + 1][j])){
                    f[i][j] = f[i - 1][k] + abs(a[i] - b[(k - 1) % m + 1][j]);
                    g[i][j] = k;
                }
        }
    ans = 1;
    rep(i, s)
        if(f[n][i] < f[n][ans])
            ans = i;
    printf("%d\n", f[n][ans]);
    print(n, ans);
    puts("");
    return 0;
}
