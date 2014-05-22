/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/04/27 10:08:05
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

long long r, n, m, k, inco;
long long p[100];

int main(){
    cout << "Case #1:" << endl;
    scanf("%*d%lld%lld%lld%lld", &r, &n, &m, &k);
    rep(i, r){
        rep(j, k)
            scanf("%lld", &p[j]);

        rep(j, n){
            long long pos = 2, maxNum = 0;
            for(long long x = 2; x <= m; ++x){
                int num = 0;
                rep(y, k)
                    if(p[y] % x == 0)
                        ++num;
                if(num >= maxNum)
                    pos = x, maxNum = num;
            }
            rep(x, k)
                if(p[x] % pos == 0)
                    p[x] /= pos;
            printf("%lld", pos);
        }

        rep(j, k) if (p[j] != 1){
            ++inco;
            break;
        }
        printf("\n");
    }
    
    cout << r - inco << endl;
    return 0;
}

