/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : A.cpp
*	Creation Time : 2013/04/13 11:01:59
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char g[10][10];

char read(){
    char c = getchar();
    while(c != 'X' &&  c != 'O' && c != '.' && c != 'T') c = getchar();
    return c;
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; ++i){
        int state = -1, n1, n2, n3;
        bool flag = 0;
        for(int x = 1; x <= 4; ++x)
            for(int y = 1; y <= 4; ++y)
                g[x][y] = read(), flag |= g[x][y] == '.';
        for(int x = 1; x <= 4; ++x){
            n1 = n2 = n3 = 0;
            for(int y = 1; y <= 4; ++y)
                n1 += g[x][y] == 'T', n2 += g[x][y] == 'X', n3 += g[x][y] == 'O';
            if(n2 == 4 || n2 + n1 == 4) state = 1;
            else if(n3 == 4 || n3 + n1 == 4) state = 0;
        }
        for(int x = 1; x <= 4; ++x){
            n1 = n2 = n3 = 0;
            for(int y = 1; y <= 4; ++y)
                n1 += g[y][x] == 'T', n2 += g[y][x] == 'X', n3 += g[y][x] == 'O';
            if(n2 == 4 || n2 + n1 == 4) state = 1;
            else if(n3 == 4 || n3 + n1 == 4) state = 0;
        }
        n1 = n2 = n3 = 0;
        for(int x = 1; x <= 4; ++x)
            n1 += g[x][x] == 'T', n2 += g[x][x] == 'X', n3 += g[x][x] == 'O';
        if(n2 == 4 || n2 + n1 == 4) state = 1;
        else if(n3 == 4 || n3 + n1 == 4) state = 0;
        n1 = n2 = n3 = 0;
        for(int x = 1; x <= 4; ++x)
            n1 += g[x][5 - x] == 'T', n2 += g[x][5 - x] == 'X', n3 += g[x][5 - x] == 'O';
        if(n2 == 4 || n2 + n1 == 4) state = 1;
        else if(n3 == 4 || n3 + n1 == 4) state = 0;

        printf("Case #%d: ", i);
        if(state != -1) puts(state ? "X won" : "O won");
        else puts(flag ? "Game has not completed" : "Draw");
    }
}
