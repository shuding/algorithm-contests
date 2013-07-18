/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : H.cpp
*   Creation Time : 2013/06/20 14:09:06
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
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;

const int base = 10000;

struct number{
    int d[100];
    void initWith(int x){
        d[0] = 1;
        d[1] = x;
    }
    void operator += (number &n){
        int dig = max(d[0], n.d[0]);
        rep(i, dig + 1){
            if(i > d[0])
                d[i] = 0;
            if(i <= n.d[0])
                d[i] += n.d[i];
        }
        rep(i, dig){
            d[i + 1] += d[i] / base;
            d[i] %= base;
        }
        d[0] = dig;
        if(d[d[0] + 1])
            ++d[0];
    }
    void operator *= (number &n){
        number tmp;
        clr(tmp.d);
        tmp.initWith(0);
        int dig = d[0] + n.d[0];
        rep(i, d[0])
            rep(j, n.d[0])
                tmp.d[i + j - 1] += d[i] * n.d[j];
        rep(i, dig){
            tmp.d[i + 1] += tmp.d[i] / base;
            tmp.d[i] %= base;
            d[i] = tmp.d[i];
        }
        while(!d[dig] && dig > 1)
            --dig;
        d[0] = dig;
    }
    void power(int n){
        if(n == 1)
            return;
        number tmp;
        memcpy(tmp.d, d, sizeof d);
        power(n / 2);
        *this *= *this;
        if(n & 1)
            *this *= tmp;
    }
    void operator /= (int n){
        int res = 0;
        for(int i = d[0]; i; --i){
            d[i] = d[i] + res * base;
            res = d[i] % n;
            d[i] /= n;
        }
        while(!d[d[0]] && d[0] > 1)
            --d[0];
    }
    void output(){
        printf("%d", d[d[0]]);
        for(int i = d[0] - 1; i; --i)
            printf("%04d", d[i]);
        puts("");
    }
} tot, bin;

int n, m, cnt, num, table[25][25], tmp[25][25];

void shiftx(){
    rep(i, n){
        int tmp = table[i][1];
        rep(j, m - 1)
            table[i][j] = table[i][j + 1];
        table[i][m] = tmp;
    }
}

void shifty(){
    rep(i, m){
        int tmp = table[1][i];
        rep(j, n - 1)
            table[j][i] = table[j + 1][i];
        table[n][i] = tmp;
    }
}

void rotate(){
    rep(i, n)
        rep(j, m)
            tmp[j][n + 1 - i] = table[i][j];
    swap(n, m);
    rep(i, n)
        rep(j, m)
            table[i][j] = tmp[i][j];
}

bool vst[410];

int getP(){
    clr(vst);
    int res = 0, x, y, t;
    rep(i, n)
        rep(j, m){
            x = i;
            y = j;
            if(!vst[(x - 1) * m + y]){
                ++res;
                while(!vst[(x - 1) * m + y]){
                    t = table[x][y];
                    vst[(x - 1) * m + y] = 1;
                    x = (t + m - 1) / m;
                    y = (t - 1) % m + 1;
                }
            }
        }
    return res;
}

void calc(){
    num = getP();
    bin.initWith(2);
    bin.power(num);
    tot += bin;
    ++cnt;
}

int main(){
    freopen("tickets.in", "r", stdin);
    freopen("tickets.out", "w", stdout);
    cin >> n >> m;
    cnt = 0;
    rep(i, n)
        rep(j, m)
            table[i][j] = ++cnt;
    tot.initWith(0);
    cnt = 0;
    rep(i, n){
        rep(j, m){
            calc();
            rotate();
            if(n == m)
                calc();
            rotate();
            calc();
            rotate();
            if(n == m)
                calc();
            rotate();
            shiftx();
        }
        shifty();
    }
    tot /= cnt;
    tot.output();
    return 0;
}
