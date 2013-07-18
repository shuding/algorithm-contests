/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : H.cpp
*   Creation Time : 2013/06/27 17:18:52
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

int n, m, p, d[410][410];
pair<int, int> que[200000];
char g[1000][1000];

void dfs(int x, int y, int dis){
    que[p = 1] = mp(x, y);
    d[x][y] = dis;
    rep(i, p){
        x = que[i].first;
        y = que[i].second;
        dis = d[x][y];
        if(x < n && g[x * 2][y * 2 - 1] == '|'
            && (d[x + 1][y] == -1 || d[x + 1][y] > dis + 1))
                d[x + 1][y] = dis + 1, que[++p] = mp(x + 1, y);
        if(x > 1 && g[x * 2 - 2][y * 2 - 1] == '|'
            && (d[x - 1][y] == -1 || d[x - 1][y] > dis + 1))
                d[x - 1][y] = dis + 1, que[++p] = mp(x - 1, y);
        if(y < m && g[x * 2 - 1][y * 2] == '-'
            && (d[x][y + 1] == -1 || d[x][y + 1] > dis + 1))
                d[x][y + 1] = dis + 1, que[++p] = mp(x, y + 1);
        if(y > 1 && g[x * 2 - 1][y * 2 - 2] == '-'
            && (d[x][y - 1] == -1 || d[x][y - 1] > dis + 1))
                d[x][y - 1] = dis + 1, que[++p] = mp(x, y - 1);
    }
}

void print(int x, int y, int dis, int dir){
loop:
    if(!dis)
        return;
    if(dis == d[n][1]){
        if(x > 1 && g[x * 2 - 2][y * 2 - 1] == '|' && d[x - 1][y] == dis - 1){
            printf("N\n");
            x--;
            dis--;
            dir = 1;
            goto loop;
        }
        else{
            printf("E\n");
            y++;
            dis--;
            dir = 4;
            goto loop;
        }
    }
    switch(dir){
        case 1:
            goto U;
            break;
        case 2:
            goto D;
            break;
        case 3:
            goto L;
            break;
        case 4:
            goto R;
            break;
        default:
            goto st;
    }
st:
D:
    if(x < n && g[x * 2][y * 2 - 1] == '|' && d[x + 1][y] == dis - 1){
        if(dir == 2)
            printf("F");
        else if(dir == 4)
            printf("R");
        else
            printf("L");
        x++;
        dis--;
        dir = 2;
        goto loop;
    }
U:
    if(x > 1 && g[x * 2 - 2][y * 2 - 1] == '|' && d[x - 1][y] == dis - 1){
        if(dir == 1)
            printf("F");
        else if(dir == 4)
            printf("L");
        else
            printf("R");
        x--;
        dis--;
        dir = 1;
        goto loop;
    }
R:
    if(y < m && g[x * 2 - 1][y * 2] == '-' && d[x][y + 1] == dis - 1){
        if(dir == 2)
            printf("L");
        else if(dir == 1)
            printf("R");
        else
            printf("F");
        y++;
        dis--;
        dir = 4;
        goto loop;
    }
L:
    if(y > 1 && g[x * 2 - 1][y * 2 - 2] == '-' && d[x][y - 1] == dis - 1){
        if(dir == 2)
            printf("R");
        else if(dir == 1)
            printf("L");
        else
            printf("F");
        y--;
        dis--;
        dir = 3;
        goto loop;
    }
    goto st;
}

int main(){
    freopen("straight.in", "r", stdin);
    freopen("straight.out", "w", stdout);
    cin >> n >> m;
    rep(i, 2 * n - 1)
        rep(j, 2 * m - 1){
            g[i][j] = getchar();
            while(g[i][j] != '-' && g[i][j] != '|' && g[i][j] != '+' && g[i][j] != ' ')
                g[i][j] = getchar();
        }
    memset(d, -1, sizeof d);
    dfs(1, m, 0);
    print(n, 1, d[n][1], 0);
    puts("");
    return 0;
}
