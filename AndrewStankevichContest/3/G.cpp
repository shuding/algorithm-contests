/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : G.cpp
*   Creation Time : 2013/06/25 03:37:04
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

int n, s[110];
bool p[60][110], q[60][110];
char c;

int getTp(int x0, int y0, int dx, int dy, int x1, int y1){
    int n = 0;
    for(; x0 <= x1 && y0 <= y1; x0 += dx, y0 += dy){
        ++n;
        s[n] = (int)p[x0][y0] + s[n - 1];
    }
    if(s[n] == n || s[n] == 0)
        return 0;
    if(!s[n - s[n]])
        return 1;
    else if(s[n] == s[s[n]])
        return 2;
    return -1;
}

bool check(){
    int tp, type = 0;
    rep(i, n){
        tp = getTp(i, 1, 0, 1, i, i * 2 - 1);
        if(tp == -1)
            return 0;
        if(tp && type && type != tp)
            return 0;
        if(tp && !type)
            type = tp;
    }
    return 1;
}

void rotate(){
    rep(i, n)
        rep(j, i * 2 - 1)
            q[n + 1 - (j + 1) / 2][i * 2 - j] = p[i][j];
    rep(i, n)
        rep(j, i * 2 - 1)
            p[i][j] = q[i][j];
}

int main(){
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    int num = 0;
    while(scanf("%d", &n), n > 0){
        rep(i, n)
            rep(j, i * 2 - 1){
                c = getchar();
                while(c != '0' && c != '1')
                    c = getchar();
                p[i][j] = (c == '1');
            }
        printf("Puzzle %d\n", ++num);
        if(check())
            puts("Parts can be separated");
        else{
            rotate();
            if(check())
                puts("Parts can be separated");
            else{
                rotate();
                if(check())
                    puts("Parts can be separated");
                else
                    puts("Parts cannot be separated");
            }
        }
        puts("");
    }
    return 0;
}
