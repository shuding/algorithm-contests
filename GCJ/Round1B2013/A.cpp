/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/05/05 00:10:00
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

int n, a, b[200];

int main(){
    int testNum; cin >> testNum;
    rep(i, testNum){
        scanf("%d%d", &a, &n);
        rep(j, n)
            scanf("%d", &b[j]);
        sort(b + 1, b + 1 + n);
        int top = 1, ans = 0;
        while(top <= n){
            while(a > b[top] && top <= n)
                a += b[top++];
            if(top <= n){
                if(a + a - 1 <= b[top])
                    ++top;
                else
                    a += a - 1;
                ans++;
            }
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
