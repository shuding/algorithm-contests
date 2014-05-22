/*
*   Copyright (C) Ds ds303077135@gmail.com
*   File Name     : B.cpp
*   Creation Time : 2014/04/13 03:00:00
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

double c, f, x;

int main(){
    int T;
    cin >> T;
    rep(_, T){
        cout << "Case #" << _ << ": ";
        cin >> c >> f >> x;
        int cnt = 0;
        double ans = x / 2.0, tmp = 0;
        for(; ; ){
            ans = min(ans, x / (cnt * f + 2.0) + tmp);
            tmp += c / (cnt * f + 2.0);
            ++cnt;
            if(tmp > ans)
                break;
        }
        printf("%.7lf\n", ans);
    }
    return 0;
}
