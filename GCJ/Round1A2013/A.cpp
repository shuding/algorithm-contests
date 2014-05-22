/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/04/27 09:02:42
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

int main(){
    int T;
    long long rad, t;
    scanf("%d", &T);

    rep(testNum, T){
        scanf("%lld%lld", &rad, &t);

        long long l = 0, r = 1000000000ll, mid;

        while(l + 1 < r){
            mid = l + r >> 1;
            if(2ll * mid * rad - 3ll * mid + 2ll * mid * (mid + 1) > t)
                r = mid;
            else
                l = mid;
        }

        if(2ll * rad * r - 3ll * r + 2ll * r * (r + 1) > t)
            mid = l;
        else
            mid = r;

        printf("Case #%d: %lld\n", testNum, mid);
    }
    return 0;
}
