/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/06/25 03:29:08
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

double a, b, c, d, q1, q2, p1, p2, q[2], p[2];

void renew(){
    if((q[0] + q[1]) * (p[0] + p[1]) < (q1 + q2) * (p1 + p2))
        q1 = q[0], q2 = q[1], p1 = p[0], p2 = p[1];
}

int main(){
    cin >> a >> b >> c >> d;
    q[0] = q[1] = 1;
    p1 = max(a, b);
    p2 = max(c, d);
    double r = 1e6;
    while(r > 0.00001)
    return 0;
}
