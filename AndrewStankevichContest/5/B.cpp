/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/06/18 07:57:37
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
#define MAXN 110
using namespace std;

const long double pi = M_PI;

struct point{
    long double x, y;
    void rotate(long double arc){
        long double z = x;
        x = cos(arc) * x - sin(arc) * y;
        y = cos(arc) * y + sin(arc) * z;
    }
} p[MAXN];

int n;
bool ln = 0;

int main(){
    freopen("angle.in", "r", stdin);
    freopen("angle.out", "w", stdout);
    while(scanf("%d", &n), n > 0){
        if(ln)
            puts("");
        rep(i, n)
            cin >> p[i].x >> p[i].y;
        long double arc = 0;
        rep(i, n - 1)
            arc = fmod(arc + atan2(p[i + 1].y - p[i].y, p[i + 1].x - p[i].x), 2 * pi);
        while(arc < 0)
            arc += 2 * pi;
        arc = (arc < 1e-8 ? 0 : (2 * pi - arc) / (n - 1));
        printf("%.20lf\n%.20lf\n", 0., double(arc));
        rep(i, n){
            p[i].rotate(arc);
            printf("%.20lf %.16lf\n", (double)p[i].x, (double)p[i].y);
        }
        ln = 1;
    }
    return 0;
}
