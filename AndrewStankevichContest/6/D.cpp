/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/07/13 03:24:31
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

double a, b, c, d, p1, p2, q1, q2, ans = 1e30;

void renew1(double a, double b, double c, double d, double &p1, double &p2, double &q1, double &q2){
    if(b * c < a * d)
        return;
    double tmp = (b / d + 1) * (d + c);
    if(tmp < ans){
        ans = tmp;
        p2 = 1;
        p1 = b / d;
        q2 = d;
        q1 = c;
    }
}

void renew2(double a, double b, double c, double d, double &p1, double &p2, double &q1, double &q2){
    if(b * c > a * d)
        return;
    double l = b / d, r = a / c, m = sqrt(a / d), p, tmp;
    if((l + 1) * (a / l + d) < (r + 1) * (a / r + d))
        p = l;
    else
        p = r;
    tmp = (p + 1) * (a / p + d);
    if(m > l && m < r)
        if(tmp > (m + 1) * (a / m + d))
            p = m;
    tmp = (p + 1) * (a / p + d);
    if(tmp < ans){
        ans = tmp;
        p1 = p;
        q1 = a / p;
        p2 = 1;
        q2 = d;
    }
}

int main(){
    freopen("lab.in", "r", stdin);
    freopen("lab.out", "w", stdout);
    cin >> a >> b >> c >> d;
    renew1(a, b, c, d, p1, p2, q1, q2);
    renew1(b, d, a, c, q2, q1, p1, p2);
    renew1(d, c, b, a, p2, p1, q2, q1);
    renew1(c, a, d, b, q1, q2, p2, p1);
    renew2(a, b, c, d, p1, p2, q1, q2);
    renew2(b, d, a, c, q2, q1, p1, p2);
    printf("%.7lf\n%.7lf %.7lf %.7lf %.7lf\n", ans, p1, p2, q1, q2);
    return 0;
}
