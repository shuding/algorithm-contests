/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : G.cpp
*   Creation Time : 2013/06/06 01:24:08
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
#define MAXN 100010
#define inf 1000000001
using namespace std;

struct data{
    int a, b, no;
    bool operator < (const data &d) const {
        if(a != d.a)
            return a < d.a;
        return b > d.b;
    }
} d[MAXN];

int n, m, st, f[MAXN], ans[MAXN], pre[MAXN];

int main(){
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        scanf("%d%d", &d[i].a, &d[i].b), d[i].no = i, f[i] = inf;
    sort(d + 1, d + 1 + n);
    st = 1;
    rep(i, n){
        m = lower_bound(f + 0, f + st, d[i].b) - f;
        pre[d[i].no] = ans[m - 1];
        if(f[m] > d[i].b)
            ans[m] = d[i].no;
        f[m] = min(f[m], d[i].b);
        st = max(st, m + 1);
    }
    printf("%d", st - 1);
    m = ans[st - 1];
    char c = '\n';
    while(m){
        printf("%c%d", c, m);
        c = ' ';
        m = pre[m];
    }
    puts("");
    return 0;
}
