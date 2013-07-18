/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : H.cpp
*   Creation Time : 2013/07/08 20:42:31
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
#define MAXN 10010
using namespace std;

vector<int> e[MAXN], p;
int n, b, x, y, block, bel[MAXN], cap[MAXN];

void dfs(int v, int f, vector<int> &q){
    vector<int> p;
    p.clear();
    for(int i = 0; i < e[v].size(); ++i){
        if(e[v][i] != f)
            dfs(e[v][i], v, p);
        if(p.size() >= b){
            cap[++block] = v;
            for(int j = 0; j < p.size(); ++j)
                bel[p[j]] = block;
            p.clear();
        }
    }
    p.pb(v);
    if(p.size() >= b){
        cap[++block] = v;
        for(int j = 0; j < p.size(); ++j)
            bel[p[j]] = block;
        p.clear();
    }
    for(int i = 0; i < p.size(); ++i)
        q.pb(p[i]);
}

int main(){
    freopen("royal.in", "r", stdin);
    freopen("royal.out", "w", stdout);
    scanf("%d%d", &n, &b);
    rep(i, n - 1){
        scanf("%d%d", &x, &y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1, 0, p);
    for(int i = 0; i < p.size(); ++i)
        bel[p[i]] = block;
    printf("%d\n", block);
    if(!block)
        return 0;
    rep(i, n)
        printf("%d%c", bel[i], i == n ? '\n' : ' ');
    rep(i, block)
        printf("%d%c", cap[i], i == block ? '\n' : ' ');
    return 0;
}

