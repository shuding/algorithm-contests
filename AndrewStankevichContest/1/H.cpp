/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : H.cpp
*   Creation Time : 2013/06/06 17:16:55
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

int m, t, pn, x, d[110];
int a[110][110], prime[110];
bool inp[10000];

void init(){
    for(int i = 2; i <= 10000; ++i){
        if(!inp[i])
            prime[++pn] = i;
        if(pn >= t)
            return;
        for(int j = 1; j <= pn && i * prime[j] < 10000; ++j){
            inp[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main(){
    freopen("rsa.in", "r", stdin);
    freopen("rsa.out", "w", stdout);
    cin >> t >> m;
    init();
    rep(i, m){
        scanf("%d", &x);
        rep(j, t){
            int cnt = 0, mul = prime[j];
            while(x % mul == 0)
                cnt++, mul *= prime[j];
            a[j][i] = cnt & 1;
        }
    }
    bool flag = 1;
    while(flag){
        flag = 0;
        rep(i, t)
            rep(j, t)
                if(i != j)
                    rep(k, m) if(a[i][k] || a[j][k]){
                        if(a[i][k] && a[j][k]){
                            for(int p = k; p <= m; ++p)
                                a[j][p] = (a[i][p] + a[j][p]) & 1;
                            flag = 1;
                        }
                        break;
                    }
    }
    int cnt = m - t;
    rep(i, t){
        bool check = 1;
        rep(j, m)
            check &= !a[i][j];
        cnt += check;
    }
    d[0] = d[1] = 1;
    rep(i, cnt){
        rep(j, d[0])
            d[j] <<= 1;
        rep(j, d[0])
            d[j + 1] += d[j] / 10,
            d[j] %= 10;
        while(d[d[0] + 1])
            ++d[0];
    }
    int t = 1;
    while(!d[t])
        d[t++] = 9;
    d[t]--;
    rep(i, d[0])
        printf("%d", d[d[0] - i + 1]);
    puts("");
    return 0;
}

