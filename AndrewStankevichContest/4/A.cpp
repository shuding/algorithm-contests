/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/06/27 14:45:08
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
#define MAXN 810
#define MAXM 10010
using namespace std;

const int inf = 100000000;

struct edge{
    int t, f, next;
} e[MAXM * 4];

int n, m, a, b;
int h[MAXN], hn[MAXN];
int etop, st[MAXN];

int sap(int v, int lim){
   if(v == b || !lim) return lim;
   int left = lim, tmp = n - 1;
   for(int i = st[v]; i; i = e[i].next){
       if(e[i].f && h[v] == h[e[i].t] + 1){
           int f = sap(e[i].t, min(left, e[i].f));
           left -= f; e[i].f -= f;
           e[(i & 1) ? i + 1 : i - 1].f += f;
           if(h[a] == n) return lim - left;
        }
       if(e[i].f) tmp = min(tmp, h[e[i].t]);
   }
   if(lim == left){
       hn[h[v]]--;
       if(!hn[h[v]]) h[a] = n;
       else hn[h[v] = tmp + 1]++;
   }
   return lim - left;
}

void add(int s, int t, int f){
    etop++;
    e[etop].t = t;
    e[etop].f = f;
    e[etop].next = st[s];
    st[s] = etop;
}

void maxFlow(){
    hn[0] = n;
    while(h[a] != n)
        sap(a, inf);
}

int cnt;
bool vst[MAXN];

void dfs(int v, bool t){
    if(vst[v])
        return;
    vst[v] = 1;
    ++cnt;
    for(int i = st[v]; i; i = e[i].next)
        if((i & 1) && !t){
            if(e[i].f)
                dfs(e[i].t, t);
        }
        else if(!(i & 1) && t)
            if(e[i - 1].f)
                dfs(e[i].t, t);
}

int main(){
    freopen("attack.in", "r", stdin);
    freopen("attack.out", "w", stdout);
    cin >> n >> m >> a >> b;
    int s, t, f;
    rep(i, m){
        scanf("%d%d%d", &s, &t, &f);
        add(s, t, f);
        add(t, s, 0);
        add(t, s, f);
        add(s, t, 0);
    }
    maxFlow();
    dfs(a, 0);
    dfs(b, 1);
    cout << (cnt >= n ? "UNIQUE" : "AMBIGUOUS") << endl;
    return 0;
}
