/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/07/04 20:37:14
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
#define MAXN 1010
using namespace std;

int n, m, x, p, a[MAXN];

int getPrevTwo(int pos){
    while(a[pos] != 2 && pos < n)
        ++pos;
    return pos;
}

void change(int x, int d){
    a[x] = d;
    printf("  %d %d", x, d);
}

int main(){
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
    cin >> n >> m;
    rep(i, m){
        scanf("%d", &x);
        switch(a[x]){
            case 0:
                p = getPrevTwo(x);
                if(p < n)
                    printf("3"), change(p + 1, a[p + 1] + 1), change(p, 0);
                else
                    printf("1");
                change(x, 1);
                break;
            case 1:
                if(a[x + 1] == 0){
                    printf("2");
                    change(x + 1, 1);
                    change(x, 0);
                }
                else{
                    p = getPrevTwo(x);
                    if(p < n)
                        printf("4"), change(p + 1, a[p + 1] + 1), change(p, 0);
                    else
                        printf("2");
                    change(x + 1, a[x + 1] + 1);
                    change(x, 0);
                }
                break;
            case 2:
                printf("2");
                change(x + 1, a[x + 1] + 1);
                change(x, 1);
                break;
        }
        printf("\n");
    }
    return 0;
}
