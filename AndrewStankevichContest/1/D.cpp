/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/06/06 04:06:39
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
#define rep(i, n) for(int i = 0; i < n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int m, p, sz, ans;

struct matrix{
    int d[40][40];
    matrix(){
        memset(d, 0, sizeof d);
    }
    matrix operator * (const matrix &m) const{
        matrix ret;
        memset(ret.d, 0, sizeof ret.d);
        rep(i, sz)
            rep(j, sz)
                rep(k, sz)
                    ret.d[i][j] = (ret.d[i][j] + d[i][k] * m.d[k][j]) % p;
        return ret;
    }
} mul, base, ret;

struct number{
    int d[200];
} n;

void power(){
    bool tmp = n.d[1] & 1;
    if(n.d[0] == 1 && n.d[1] == 0)
        return;
    int mod = 0;
    for(int i = n.d[0]; i; --i){
        n.d[i] += mod * 10;
        mod = n.d[i] & 1;
        n.d[i] >>= 1;
    }
    while(!n.d[n.d[0]] && n.d[0] > 1)
        --n.d[0];
    power();
    ret = ret * ret;
    if(tmp)
        ret = ret * mul;
}

int main(){
    freopen("nice.in", "r", stdin);
    freopen("nice.out", "w", stdout);
    char c = getchar();
    n.d[0] = 0;
    while(c >= '0' && c <= '9'){
        n.d[++n.d[0]] = c - '0';
        c = getchar();
    }
    rep(i, n.d[0] / 2)
        swap(n.d[n.d[0] - i], n.d[i + 1]);
    cin >> m >> p;
    sz = 1 << m;
    for(int i = 0; i < sz; ++i)
        for(int j = 0; j < sz; ++j){
            int tmp = i ^ j;
            mul.d[i][j] = 1;
            for(int k = 1; k < m; ++k)
                if(!(tmp & (1 << k)) && !(tmp & (1 << (k - 1)))
                        && ((i & (1 << k)) > 0) == ((i & (1 << (k - 1))) > 0))
                    mul.d[i][j] = 0;
        }
    rep(i, sz)
        base.d[0][i] = 1, ret.d[i][i] = 1;
    int pos = 1;
    while(n.d[pos] == 0)
        n.d[pos] = 9, ++pos;
    n.d[pos]--;
    while(!n.d[n.d[0]] && n.d[0] > 1)
        --n.d[0];
    power();
    base = base * ret;
    rep(i, sz)
        ans = (ans + base.d[0][i]) % p;
    cout << ans << endl;
    return 0;
}
