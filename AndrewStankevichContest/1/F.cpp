/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : F.cpp
*   Creation Time : 2013/06/06 04:58:04
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
using namespace std;

const double pi = acos(-1);
const double eps = 1e-6;

struct point{
    double x, y;
};

struct circle{
    point o;
    double r;
} c[310];

double dis(const point &a, const point &b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double det(const point &a, const point &b){
    return a.x * b.y - a.y * b.x;
}

double dot(const point &a, const point &b){
    return a.x * b.x + a.y * b.y;
}

int n;
double x, y, r, L, R, d[310];
bool vst[310];
vector<pair<int, double> > e[310];
int que[100000], t[310], p;

bool spfa(){
    rep(i, n)
        vst[que[++p] = i] = 1;
    rep(i, p){
        if(t[que[i]] > n)
            return 0;
        for(int j = 0; j < e[que[i]].size(); ++j)
            if(d[e[que[i]][j].first] > d[que[i]] + e[que[i]][j].second + eps){
                d[e[que[i]][j].first] = d[que[i]] + e[que[i]][j].second;
                if(!vst[e[que[i]][j].first]){
                    que[++p] = e[que[i]][j].first;
                    vst[e[que[i]][j].first] = 1;
                    if(n < ++t[e[que[i]][j].first])
                        return 0;
                }
            }
        vst[que[i]] = 0;
    }
    return 1;
}

int main(){
    freopen("out.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        scanf("%lf%lf%lf", &c[i].o.x, &c[i].o.y, &c[i].r);
    cin >> x >> y >> r;
    rep(i, n)
        c[i].o.x -= x, c[i].o.y -= y, c[i].r += r;
    rep(i, n)
        rep(j, n)
            if(i != j)
                if(dis(c[i].o, c[j].o) < c[i].r + c[j].r - eps)
                    e[i].pb(mp(j,
                        atan2(det(c[i].o, c[j].o), dot(c[i].o, c[j].o))));
    puts(spfa() ? "YES" : "NO");
    return 0;
}
