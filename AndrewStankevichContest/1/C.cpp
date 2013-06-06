/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/06/06 03:32:02
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
#define MAXN 500010
using namespace std;

int n, g[2][MAXN], ch[MAXN];
vector<int> e[MAXN], ans;

void dfs(int v, int f = 0){
    for(int i = 0; i < e[v].size(); ++i)
        if(e[v][i] != f){
            dfs(e[v][i], v);
            g[0][v] += g[1][e[v][i]];
        }
    g[1][v] = g[0][v];
    for(int i = 0; i < e[v].size(); ++i)
        if(e[v][i] != f){
            if(g[1][v] < g[0][v] - g[1][e[v][i]] + g[0][e[v][i]] + 1){
                g[1][v] = g[0][v] - g[1][e[v][i]] + g[0][e[v][i]] + 1;
                ch[v] = e[v][i];
            }
        }
}

void print(int v, int c, int f = 0){
    for(int i = 0; i < e[v].size(); ++i)
        if(e[v][i] != f){
            if(!c)
                print(e[v][i], 1, v);
            else
                if(ch[v] == e[v][i]){
                    ans.push_back(e[v][i]);
                    print(e[v][i], 0, v);
                }
                else
                    print(e[v][i], 1, v);
        }
}

int main(){
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);
    scanf("%d", &n);
    int f;
    rep(i, n - 1){
        scanf("%d", &f);
        e[f].push_back(i + 1);
    }
    dfs(1);
    printf("%d\n", 1000 * g[1][1]);
    print(1, 1);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    return 0;
}
