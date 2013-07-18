/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/06/25 02:20:10
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
#define MAXN 410
using namespace std;

vector<int> e[MAXN];
int n, k, tmp, a[MAXN], b[MAXN], p[MAXN], q[MAXN];
bool vst[MAXN];

bool cmp(const int &i, const int &j){
    return a[i] < a[j];
}

bool find(int v){
    if(!vst[v]){
        vst[v] = 1;
        for(int i = 0; i < e[v].size(); ++i)
            if(!q[e[v][i]] || find(q[e[v][i]])){
                p[v] = e[v][i];
                q[e[v][i]] = v;
                return 1;
            }
    }
    return 0;
}

int main(){
    freopen("beloved.in", "r", stdin);
    freopen("beloved.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        scanf("%d", &a[i]), b[i] = i;
    rep(i, n){
        scanf("%d", &k);
        rep(j, k){
            scanf("%d", &tmp);
            e[i].pb(tmp);
        }
    }
    sort(b + 1, b + 1 + n, cmp);
    for(int i = n; i; --i)
        if(!p[b[i]]){
            memset(vst, 0, sizeof vst);
            find(b[i]);
        }
    rep(i, n)
        printf("%d%c", p[i], (i == n ? '\n' : ' '));
    return 0;
}
