/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : G.cpp
*   Creation Time : 2013/07/15 02:26:40
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
#define MAXM 40010
using namespace std;

struct edge{
    int t, f, c, next;
} e[MAXM * 2];

const int inf = 100000000;
int m, n, k, t, S, T, etop, st[MAXN];
int dis[MAXN], inq[MAXN], pre[MAXN], que[MAXN * 100];

bool spfa(){
    int q = 0;
    rep(i, T) dis[i] = inf, inq[i] = 0, pre[i] = 0;
    dis[S] = 0; inq[S] = 1; que[0] = S;
    for(int i = 0; i <= q; ++i){
        for(int j = st[que[i]]; j; j = e[j].next)
            if(e[j].f && dis[e[j].t] > dis[que[i]] + e[j].c){
                dis[e[j].t] = dis[que[i]] + e[j].c;
                pre[e[j].t] = j;
                if(!inq[e[j].t]) que[++q] = e[j].t;
                inq[e[j].t] = 1;
            }
       inq[que[i]] = 0;
    }
    return dis[T] != inf;
}

int minCostMaxFlow(){
    int f, v, sum = 0;
    while(spfa()){
        f = inf;
        for(v=T; v!=S; v=e[pre[v]+(pre[v]&1?1:-1)].t)
            f = min(f, e[pre[v]].f);
        for(v=T; v!=S; v=e[pre[v]+(pre[v]&1?1:-1)].t){
            e[pre[v]].f -= f;
            e[pre[v] + (pre[v] & 1 ? 1 : -1)].f += f;
        }
        sum += dis[T] * f;
    }
    return sum;
}

void add(int s, int t, int c, int f){
    etop++;
    e[etop].t = t;
    e[etop].c = c;
    e[etop].f = f;
    e[etop].next = st[s];
    st[s] = etop;
}

int main(){
    cin >> m >> n;
    rep(i, m){
        scanf("%d", &k);
        rep(i, k){
            scanf("%d", &t);
            add(t, n + i, 0, 1);
            add(n + i, t, 0, 0);
        }
    }
    S = n + m + 1;
    T = S + 1;
    rep(i, n)
        add(S, i, 0, 1), add(i, S, 0, 0);
    rep(i, m)
        add(n + i, T, 0, 1), add(T, n + i, 0, 0);
    cout << minCostMaxFlow() << endl;
    return 0;
}
