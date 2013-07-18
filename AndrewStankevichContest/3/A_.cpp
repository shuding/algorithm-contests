/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/06/07 09:45:21
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

const double inf = 1e10;
const double eps = 1e-6;

struct point{
    double x, y;
    point(){}
    point(double _x, double _y): x(_x), y(_y){}
};

struct line{
    point a, b;
    line(){}
    line(point _a, point _b): a(_a), b(_b){}
} l[MAXN];

struct poly{
    vector<point> ver;
    poly(){
        ver.clear();
    }
    double s(){
        int sz = ver.size();
        double ret = 0;
        for(int i = 0; i < sz; ++i){
            ret += (ver[i].x - ver[(i + 1) % sz].x) * (ver[i].y + ver[(i + 1) % sz].y);
            if(fabs(ver[i].x) >= inf - eps || fabs(ver[i].y) >= inf - eps)
                return inf * 10;
        }
        return fabs(ret) * .5;
    }
} rect;

int n;
vector<double> ans;

double det(point &a, point &b, point &c){
    return a.x * (b.y - c.y) + (a.y - b.y) * c.x + b.x * (c.y - a.y);
}

bool cross(line &l, poly &p){
    bool s[2] = {0, 0};
    int sz = p.ver.size(), si;
    for(int i = 0; i < sz; ++i){
        si = sign(det(l.a, l.b, p.ver[i]));
        if(si)
            s[si == 1] = 1;
        if(s[0] && s[1])
            return 1;
    }
    return 0;
}

bool cross(line l, line &r){
    int sl = sign(det(r.a, r.b, l.a)), sr = sign(det(r.a, r.b, l.b));
    return sr && sl != sr;
}

point crossPoint(line l, line &r){
    double sl = fabs(det(r.a, r.b, l.a)), sr = fabs(det(r.a, r.b, l.b));
    return point(l.a.x + (l.b.x - l.a.x) * fabs(sl / (sl + sr)),
                 l.a.y + (l.b.y - l.a.y) * fabs(sl / (sl + sr)));
}

void cut(poly &p){
    bool flag = 1;
    while(flag && p.s() > eps){
        flag = 0;
        rep(i, n)
            if(cross(l[i], p)){
                poly *L = new poly();
                int st = 0, sz = p.ver.size();
                for(; !cross(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]); st = (st + 1) % sz);
                L->ver.pb(crossPoint(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]));
                for(st = (st + 1) % sz; !cross(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]); st = (st + 1) % sz)
                    L->ver.pb(p.ver[st]);
                L->ver.pb(p.ver[st]);
                L->ver.pb(crossPoint(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]));
                cut(*L);

                L->ver.clear();
                L->ver.pb(crossPoint(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]));
                for(st = (st + 1) % sz; !cross(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]); st = (st + 1) % sz)
                    L->ver.pb(p.ver[st]);
                L->ver.pb(p.ver[st]);
                L->ver.pb(crossPoint(line(p.ver[st], p.ver[(st + 1) % sz]), l[i]));
                p.ver = L->ver;

                delete(L);
                flag = 1;
            }
    }
    double s = p.s();
    if(s > eps && s < inf)
        ans.pb(s);
}

int main(){
    scanf("%d", &n);
    rep(i, n)
        scanf("%lf%lf%lf%lf", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);
    rect.ver.pb(point(-inf, -inf));
    rect.ver.pb(point(-inf,  inf));
    rect.ver.pb(point( inf,  inf));
    rect.ver.pb(point( inf, -inf));
    cut(rect);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, ans.size())
        printf("%.4lf\n", ans[i - 1]);
    return 0;
}
