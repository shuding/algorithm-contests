/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/06/27 15:28:58
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
#define MAXN 100
using namespace std;

const double eps = 1e-8;

struct circle{
    double x, y, r;
} c[MAXN];

struct Point{
    double x, y;
    bool operator < (const Point &p) const{
        if(fabs(x - p.x) > eps)
            return x < p.x;
        if(fabs(y - p.y) > eps)
            return y < p.y;
        return 0;
    }
} P;

vector<pair<double, double> > point;
set<Point> s;
bool vst[MAXN];
int n;

void solve(int i, int j){
    double dis = sqr(c[i].x - c[j].x) + sqr(c[i].y - c[j].y);
    if(dis > sqr(c[i].r + c[j].r) || dis < sqr(c[i].r - c[j].r))
        return;
    double a = atan2(c[j].y - c[i].y, c[j].x - c[i].x);
    double da = acos((sqr(c[i].r) - sqr(c[j].r) + dis) / (2 * c[i].r * sqrt(dis)));
    pair<double, double> pt;
    pt.first  = c[i].x + cos(a - da) * c[i].r;
    pt.second = c[i].y + sin(a - da) * c[i].r;
    point.pb(pt);
    pt.first  = c[i].x + cos(a + da) * c[i].r;
    pt.second = c[i].y + sin(a + da) * c[i].r;
    point.pb(pt);
}

void dfs(int v){
    rep(i, n)
        if(!vst[i]){
            int tmp = point.size();
            solve(v, i);
            if(tmp != point.size()){
                vst[i] = 1;
                dfs(i);
            }
        }
}

int main(){
    freopen("circles.in", "r", stdin);
    freopen("circles.out", "w", stdout);
    cin >> n;
    rep(i, n)
        cin >> c[i].x >> c[i].y >> c[i].r;
    int e = 0, v = 0;
    rep(i, n) if(!vst[i]){
        vst[i] = 1;
        dfs(i);
        ++e;
    }
    rep(i, n)
        rep(j, i - 1)
            solve(i, j);
    for(int i = 0; i < point.size(); ++i)
        P.x = point[i].first, P.y = point[i].second, s.insert(P);
    rep(i, n)
        for(set<Point>::iterator it = s.begin(); it != s.end(); ++it)
            if(fabs(sqr(it->x - c[i].x) + sqr(it->y - c[i].y) - sqr(c[i].r)) < eps)
                ++e;
    cout << e - (int)s.size() + 1 << endl;
    return 0;
}
