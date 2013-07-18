/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/06/27 15:09:06
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
#define MAXM 100010
using namespace std;

int n, m, ind;
int dfn[MAXN], low[MAXN];
bool instack[MAXN];
vector<int> ans;
vector<pair<int, int> > e[MAXN];

void dfs(int v, int f){
    instack[v] = 1;
    low[v] = dfn[v] = ++ind;
    for(int i = 0; i < e[v].size(); ++i)
        if(!dfn[e[v][i].first]){
            dfs(e[v][i].first, e[v][i].second);
            if(low[e[v][i].first] == dfn[e[v][i].first])
                ans.pb(e[v][i].second);
            low[v] = min(low[v], low[e[v][i].first]);
        }
        else if(instack[e[v][i].first] && e[v][i].second != f)
            low[v] = min(low[v], dfn[e[v][i].first]);
    instack[v] = 0;
}

int main(){
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int a, b;
    rep(i, m){
        scanf("%d%d", &a, &b);
        e[a].pb(mp(b, i));
        e[b].pb(mp(a, i));
    }
    dfs(1, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}
