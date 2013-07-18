/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/07/15 01:16:48
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

// T_T

int m;

int phi(int n){
    int res = 1;
    for(int i = 2; i <= n; ++i)
        if(n % i == 0){
            res *= i - 1;
            n /= i;
            while(n % i == 0)
                res *= i, n /= i;
        }
    return res;
}

int power(int n, int k, int m){
    if(!k)
        return 1;
    int tmp = power(n, k / 2, m);
    tmp = tmp * tmp % m;
    if(k & 1)
        tmp = tmp * n % m;
    return tmp;
}

int calc(int n){
    if(n == 1)
        return 0;
    int tmp = phi(n);
    return power(2, tmp + calc(tmp), n);
}

int high(int n, int k){
    if(n == 1)
        return 2;
    if(n <= 4)
        return power(2, high(n - 1, k), 100000);
    int tmp = phi(k);
    return power(2, tmp + high(n - 1, tmp), k);
}

int main(){
    freopen("ackerman.in", "r", stdin);
    freopen("ackerman.out", "w", stdout);
    int t, n, m, p, ans, testNum = 0;
    cin >> t;
    p = calc(t);
    while(scanf("%d%d", &n, &m), n + m > 0){
        if(n == 1)
            ans = m * 2 % t;
        else if(n == 2)
            ans = power(2, m, t);
        else if(n == 3)
            ans = (m < 32) ? high(m, t) % t : p;
        else{
            if(m == 1)
                ans = 2 % t;
            else if(m == 2)
                ans = 4 % t;
            else if(n == 4 && m == 3)
                ans = high(4, t) % t;
            else
                ans = p;
        }
        printf("Case %d: %d\n", ++testNum, ans);
    }
    return 0;
}
