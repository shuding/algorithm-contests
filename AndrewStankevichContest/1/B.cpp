/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/06/06 02:32:40
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
#define MAXN 310
#define MAXM 100010
using namespace std;

struct edge{
    int t, f, next;
} e[MAXM];

const int inf = ~0u>>2;
int n, m, S, T, in[MAXN], out[MAXN], lower[MAXM];
int etop, st[MAXN], h[MAXN], hn[MAXN];

void add(int s, int t, int f){
    etop++;
    e[etop].t = t;
    e[etop].f = f;
    e[etop].next = st[s];
    st[s] = etop;
}

int sap(int v, int lim){
    if(v == T || !lim)
        return lim;
    int left = lim, tmp = T - 1, p = st[v];
    for(int p = st[v]; p; p = e[p].next){
        if(e[p].f && h[v] == h[e[p].t] + 1){
            int f = sap(e[p].t, min(left, e[p].f));
            left -= f;
            e[p].f -= f;
            e[p + (p & 1 ? 1 : -1)].f += f;
            if(h[S] == T)
                return lim - left;
        }
        if(e[p].f)
            tmp = min(tmp, h[e[p].t]);
    }
    if(lim == left){
        hn[h[v]]--;
        if(!hn[h[v]])
            h[S] = T;
        else{
            h[v] = tmp + 1;
            hn[h[v]]++;
        }
    }
    return lim - left;
}
 
int maxFlow(){
    hn[0] = T;
    int f = 0;
    while(h[S] != T)
        f += sap(S, inf);
    return f;
}

int main(){
    freopen("cooling.in", "r", stdin);
    freopen("cooling.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int s, t, l, r, totInFlow = 0;
    S = n + 1;
    T = S + 1;
    rep(i, m){
        scanf("%d%d%d%d", &s, &t, &l, &r);
        add(s, t, r - l);
        add(t, s, 0);
        in[t] += l;
        out[s] += l;
        lower[i] = l;
    }
    rep(i, n)
        if(in[i] < out[i])
            add(i, T, out[i] - in[i]), add(T, i, 0), totInFlow += out[i] - in[i];
        else if(in[i] > out[i])
            add(S, i, in[i] - out[i]), add(i, S, 0);
    int f = maxFlow();
    if(f != totInFlow)
        puts("NO");
    else{
        puts("YES");
        rep(i, m)
            printf("%d\n", e[i * 2].f + lower[i]);
    }
    return 0;
}

