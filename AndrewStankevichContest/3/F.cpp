/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : F.cpp
*   Creation Time : 2013/07/08 16:41:58
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

int rk[300];
int n, la, lb, f[2010][2010], g[210][210], t[210], p[210], pre[2010][2010];
char s[210], a[2010], b[2010];

void printa(int la, int lb){
    if(!la && !lb)
        return;
    if(pre[la][lb] == 0){
        printa(la - 1, lb - 1);
        printf("%c", a[la - 1]);
    }
    else if(pre[la][lb] == 1){
        printa(la - 1, lb);
        printf("%c", a[la - 1]);
    }
    else{
        printa(la, lb - 1);
        printf("%c", s[p[rk[(int)b[lb - 1]]] - 1]);
    }
}

void printb(int la, int lb){
    if(!la && !lb)
        return;
    if(pre[la][lb] == 0){
        printb(la - 1, lb - 1);
        printf("%c", b[lb - 1]);
    }
    else if(pre[la][lb] == 2){
        printb(la, lb - 1);
        printf("%c", b[lb - 1]);
    }
    else{
        printb(la - 1, lb);
        printf("%c", s[t[rk[(int)a[la - 1]]] - 1]);
    }
}

int main(){
    freopen("dissim.in", "r", stdin);
    freopen("dissim.out", "w", stdout);
    cin >> s >> a >> b;
    n = strlen(s);
    la = strlen(a);
    lb = strlen(b);
    rep(i, n)
        g[i][0] = g[0][i] = 5000, rk[int(s[i - 1])] = i;
    rep(i, n)
        rep(j, n){
            scanf("%d", &g[i][j]);
            if(g[i][j] < g[i][t[i]])
                t[i] = j;
            if(g[i][j] < g[p[j]][j])
                p[j] = i;
        }
    for(int i = 0; i <= la; ++i)
        for(int j = 0; j <= lb; ++j) if(i + j > 0){
            pre[i][j] = 0;
            f[i][j] = ~0u >> 1;
            if(i && j)
                f[i][j] = f[i - 1][j - 1] + g[rk[(int)a[i - 1]]][rk[(int)b[j - 1]]];
            if(i && f[i - 1][j] + g[rk[(int)a[i - 1]]][t[rk[(int)a[i - 1]]]] < f[i][j])
                pre[i][j] = 1, f[i][j] = f[i - 1][j] + g[rk[(int)a[i - 1]]][t[rk[(int)a[i - 1]]]];
            if(j && f[i][j - 1] + g[p[rk[(int)b[j - 1]]]][rk[(int)b[j - 1]]] < f[i][j])
                pre[i][j] = 2, f[i][j] = f[i][j - 1] + g[p[rk[(int)b[j - 1]]]][rk[(int)b[j - 1]]];
        }
    cout << f[la][lb] << endl;
    printa(la, lb);
    puts("");
    printb(la, lb);
    puts("");
    return 0;
}

