/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/06/13 04:59:04
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
#define MAXN 500010
using namespace std;

int n, topX, topY, num;
long long x[MAXN], y[MAXN];
long long sum, a, b;

long long getNum(){
    if(topY > num)
        return x[topX++];
    if(topX > n)
        return y[topY++];
    if(x[topX] < y[topY])
        return x[topX++];
    return y[topY++];
}

int main(){
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        scanf("%I64d", &x[i]);
    sort(x + 1, x + 1 + n);
    topX = 1;
    topY = 1;
    num = 0;
    rep(i, n - 1){
        a = getNum();
        b = getNum();
        sum += a + b;
        y[++num] = a + b;
    }
    cout << sum << endl;
    return 0;
}
