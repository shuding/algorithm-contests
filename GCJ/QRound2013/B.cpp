/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
*	Creation Time : 2013/04/13 11:57:24
*	Environment   : OS X 10.8
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, h[200][200];

int main(){
    int t; cin >> t;
    rep(testNum, t){
        scanf("%d%d", &n, &m);
        rep(i, n)
            rep(j, m)
                scanf("%d", &h[i][j]);
        bool can = 1, res, tmp;
        rep(i, n)
            rep(j, m){
                res = 0;
                tmp = 1;
                rep(k, m)
                    if(h[i][k] > h[i][j]){
                        tmp = 0;
                        break;
                    }
                res |= tmp;
                tmp = 1;
                rep(k, n)
                    if(h[k][j] > h[i][j]){
                        tmp = 0;
                        break;
                    }
                res |= tmp;
                can &= res;
            }
        printf("Case #%d: %s\n", testNum, can ? "YES" : "NO");
    }
    return 0;
}
