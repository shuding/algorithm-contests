/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/06/18 06:38:21
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
#define sign(x) (x < -eps ? -1 : (x > eps))
#define debug(x) cout << #x << " = " << x << endl
#define MAXN 100
using namespace std;

const double eps = 1e-8;
const double inf = 1e10;

struct point{
    double x, y;
    int a, b;
    point(){}
    point(double _x, double _y): x(_x), y(_y){}
    bool operator < (const point &p) const{
        if(fabs(x - p.x) > eps)
            return x < p.x;
        return y < p.y;
    }
};

struct line{
    point a, b;
    line(){}
    line(point _a, point _b): a(_a), b(_b){}
} l[MAXN], inte[MAXN * MAXN * 2];

int n, m;
vector<int> st[MAXN][MAXN];

double det(point a, point b, point c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

void addInte(int a, int b, vector<point> &p){
    double s1 = det(l[a].a, l[a].b, l[b].a);
    double s2 = det(l[a].a, l[a].b, l[b].b);
    if(fabs(s1 - s2) < eps)
        return;                                                                  /* parallels */
    double rate = fabs(s1) / (fabs(s1) + fabs(s2));
    point tmp = point(l[b].a.x + rate * (l[b].b.x - l[b].a.x),
                      l[b].a.y + rate * (l[b].b.y - l[b].a.y));
    tmp.a = min(a, b);
    tmp.b = max(a, b);
    p.pb(tmp);
}

double dis(point &a, point &b){
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

void getInte(int v){
    static vector<point> pt;
    pt.clear();
    rep(i, n)
        if(i != v)
            addInte(v, i, pt);
    sort(pt.begin(), pt.end());
    point l;
    for(int i = 0; i < pt.size(); ++i){
        if(!i)
            l = pt[i];
        if(dis(pt[i], l) > eps){
            inte[++m] = line(pt[i], l);
            inte[++m] = line(l, pt[i]);
        }
        l = pt[i];
    }
}

vector<double> ans;

void solve(){
    rep(i, m)
        st[inte[i].a.a][inte[i].a.b].pb(i);

    int a, b, l, t;
    double s;
    rep(i, m)
        if(!st[inte[i].a.a][inte[i].a.b].empty()){
            a = inte[i].a.a;
            b = inte[i].a.b;
            l = st[a][b][0];
            s = 0;
            t = 0;
            while(l){
                st[a][b].erase(st[a][b].begin() + t);
                s += (inte[l].b.x - inte[l].a.x) * (inte[l].b.y + inte[l].a.y);
                a = inte[l].b.a;
                b = inte[l].b.b;
                t = l;
                l = 0;
                for(int j = 0; j < st[a][b].size(); ++j)
                    if(det(inte[t].a, inte[t].b, inte[st[a][b][j]].b) > eps){
                        l = st[a][b][j];
                        t = j;
                        break;
                    }
            }
            if(a != inte[i].a.a || b != inte[i].a.b)
                s = 0;
            s = fabs(s) / 2;
            if(s > eps)
                ans.pb(s);
        }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        printf("%.4lf\n", ans[i]);
}

int main(){
    cin >> n;
    rep(i, n)
        scanf("%lf%lf%lf%lf", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);
    rep(i, n)
        getInte(i);
    solve();
    return 0;
}
