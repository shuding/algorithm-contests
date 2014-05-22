/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/04/27 09:33:45
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

int e, r, n, v[10000010];
int f[100][100];

int main(){
    int T;
    scanf("%d", &T);
    rep(testNum, T){
        scanf("%d%d%d", &e, &r, &n);
        rep(i, n) scanf("%d", &v[i]);
        memset(f, 0, sizeof f);

        rep(j, e)
            f[1][j - 1] = -100000000;

        int ans = 0;
        rep(i, n)
            for(int j = 0; j <= e; ++j)
                for(int t = 0; t <= j; ++t){
                    f[i + 1][min(e, j - t + r)] = max(f[i + 1][min(e, j - t + r)], t * v[i] + f[i][j]);
                    ans = max(ans, f[i + 1][min(e, j - t + r)]);
                }

        printf("Case #%d: %d\n", testNum, ans);
    }
    return 0;
}

