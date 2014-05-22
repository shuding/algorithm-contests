 
/*
* Copyright (C) 2012 All rights reserved.
* File name:  cho.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.04
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAXN 50010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
  
const int inf = 1000000000;
  
struct node{
        int c[2], t, x, y, h;
        int pos, L, R, U, D;
        long long H;
        node(){
                c[0] = c[1] = h = 0;
                L = D = inf;
                R = U = -inf;
        }
} nodes[MAXN * 2];
 
struct data{
        int x, y, h, id;
} d[MAXN];
 
bool cmpx(const data &a, const data &b){
        return a.x < b.x;
}
 
bool cmpy(const data &a, const data &b){
        return a.y < b.y;
}
 
int tot = 1, n, m;
long long t1, t2, t3, t4;
 
void build(int n, int l, int r, bool q){
        if(l == r){
                nodes[n].R = nodes[n].L = d[l].x;
                nodes[n].U = nodes[n].D = d[l].y;
                nodes[n].h = nodes[n].H = d[l].h;
                nodes[n].x = d[l].x;
                nodes[n].y = d[l].y;
                return;
        }
        if(q)
            sort(d + l, d + r + 1, cmpx);
        else
            sort(d + l, d + r + 1, cmpy);
 
        int m = (l + r) >> 1;
        if(l <= m - 1) build(nodes[n].c[0] = ++tot, l, m - 1, !q);
        if(m + 1 <= r) build(nodes[n].c[1] = ++tot, m + 1, r, !q);
 
        nodes[n].x = d[m].x; nodes[n].y = d[m].y; nodes[n].h = d[m].h;
        nodes[n].H = nodes[nodes[n].c[0]].H + nodes[nodes[n].c[1]].H + d[m].h;
        nodes[n].L = min(nodes[nodes[n].c[0]].L, nodes[nodes[n].c[1]].L);
        nodes[n].R = max(nodes[nodes[n].c[0]].R, nodes[nodes[n].c[1]].R);
        nodes[n].U = max(nodes[nodes[n].c[0]].U, nodes[nodes[n].c[1]].U);
        nodes[n].D = min(nodes[nodes[n].c[0]].D, nodes[nodes[n].c[1]].D);
        nodes[n].L = min(nodes[n].L, nodes[n].x);
        nodes[n].R = max(nodes[n].R, nodes[n].x);
        nodes[n].U = max(nodes[n].U, nodes[n].y);
        nodes[n].D = min(nodes[n].D, nodes[n].y);
}
 
long long query(const long long &a, const long long &b, const long long &c, const long long &n){
        if(!n) return 0;
        t1 = nodes[n].L * a + nodes[n].D * b;
        t2 = nodes[n].L * a + nodes[n].U * b;
        t3 = nodes[n].R * a + nodes[n].D * b;
        t4 = nodes[n].R * a + nodes[n].U * b;
        if(t1 >= c && t2 >= c && t3 >= c && t4 >= c) return 0;
        if(t1 < c  && t2 < c  && t3 < c  && t4 < c) return nodes[n].H;
        long long ret = 0;
        if(nodes[n].x * a + nodes[n].y * b < c) ret += nodes[n].h;
        return query(a, b, c, nodes[n].c[0]) + query(a, b, c, nodes[n].c[1]) + ret;
}
 
inline void read(int &n){
        char c = getchar(); n = 0;
        bool sign = 0;
        while((c < '0' || c > '9') && c != '-') c = getchar();
        if(c == '-') c = getchar(), sign = 1;
        while(c >= '0' && c <= '9'){
                n = n * 10 + c - '0';
                c = getchar();
        }
        if(sign) n = -n;
}
 
int main(){
        scanf("%d%d", &n, &m);
        rep(i, n)
                read(d[i].x), read(d[i].y), read(d[i].h), d[i].id = i;
        build(1, 1, n, 0);
        int a, b, c;
        rep(i, m){
                read(a); read(b); read(c);
                printf("%lld\n", query(a, b, c, 1));
        }
        return 0;
}