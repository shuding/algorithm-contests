/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : I.cpp
*   Creation Time : 2013/06/25 03:03:17
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
using namespace std;

const double eps = 1e-8;
int r1, r2;

double value(double x){
    return sqrt((x * x - r1 * r1) * (x * x - r2 * r2));
}

double calc(double l, double r){
    return (value(l) + 4 * value((l + r) * .5) + value(r)) * (r - l) / 6.;
}

double sim(double l, double r){
    if(l + eps > r)
        return calc(l, r);
    double m  = (l + r) * .5;
    double v1 = calc(l, m);
    double v2 = calc(m, r);
    double v  = calc(l, r);
    if(!sign(v1 + v2 - v))
        return v;
    return sim(l, m) + sim(m, r);
}

int main(){
    freopen("twocyl.in", "r", stdin);
    freopen("twocyl.out", "w", stdout);
    cin >> r1 >> r2;
    if(r1 > r2)
        swap(r1, r2);
    printf("%.4lf\n", 8. * sim(0, r1));
    return 0;
}
