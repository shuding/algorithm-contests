/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : E.cpp
*   Creation Time : 2013/06/18 06:14:27
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

int n, m, s, t, dis[MAXN];
vector<pair<int, int> > e[MAXN];
vector<int> ans[MAXN];
bool vst[MAXN];
int que[MAXN * 10], p;

void spfa(){
    rep(i, n)
        dis[i] = m + 1;
    vst[que[p = 1] = s] = 1;
    dis[s] = 0;
    rep(i, p){
        for(int j = 0; j < e[que[i]].size(); ++j)
            if(dis[e[que[i]][j].first] > dis[que[i]] + 1){
                dis[e[que[i]][j].first] = dis[que[i]] + 1;
                if(!vst[e[que[i]][j].first])
                    que[++p] = e[que[i]][j].first;
                vst[e[que[i]][j].first] = 1;
            }
        vst[que[i]] = 0;
    }
}

int main(){
    freopen("defence.in", "r", stdin);
    freopen("defence.out", "w", stdout);
    cin >> n >> m >> s >> t;
    int a, b;
    rep(i, m){
        scanf("%d%d", &a, &b);
        e[a].pb(mp(b, i));
        e[b].pb(mp(a, i));
    }
    spfa();
    rep(i, n)
        for(int j = 0; j < e[i].size(); ++j)
            if(dis[e[i][j].first] > dis[i])
                ans[min(dis[t], dis[i] + 1)].pb(e[i][j].second);
            else if(dis[e[i][j].first] == dis[i] && i < e[i][j].first)
                ans[min(dis[t], dis[i])].pb(e[i][j].second);
    cout << dis[t] << endl;
    rep(i, dis[t]){
        printf("%d", (int)ans[i].size());
        for(int j = 0; j < ans[i].size(); ++j)
            printf(" %d", ans[i][j]);
        puts("");
    }
    return 0;
}
