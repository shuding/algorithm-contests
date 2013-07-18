/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : G.cpp
*   Creation Time : 2013/06/18 04:52:39
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
using namespace std;

int n, m, y, tot, x[MAXN], k[MAXN];
pair<double, int> diff[MAXN];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> y;
    rep(i, n){
        scanf("%d", &x[i]);
        k[i] = m * x[i] / y;
        tot += k[i];
        diff[i] = mp(double(k[i]) / m - double(x[i]) / y, i);
    }
    sort(diff + 1, diff + 1 + n);
    rep(i, m - tot)
        k[diff[i].second]++;
    rep(i, n)
        printf("%d ", k[i]);
    puts("");
    return 0;
}
