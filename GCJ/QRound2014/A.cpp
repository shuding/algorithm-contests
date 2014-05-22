/*
*   Copyright (C) Ds ds303077135@gmail.com
*   File Name     : A.cpp
*   Creation Time : 2014/04/13 01:41:21
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

int T, n, m, a[5][5], b[5][5];

int main(){
    cin >> T;
    rep(_, T){
        cout << "Case #" << _ << ": ";
        cin >> n;
        rep(i, 4)
            rep(j, 4)
                scanf("%d", &a[i][j]);
        cin >> m;
        rep(i, 4)
            rep(j, 4)
                scanf("%d", &b[i][j]);
        int cnt = 0, num;
        rep(i, 4)
            rep(j, 4)
                if(a[n][i] == b[m][j]){
                    ++cnt;
                    num = a[n][i];
                    break;
                }
        if(cnt == 1)
            cout << num << endl;
        else if(cnt > 1)
            cout << "Bad magician!" << endl;
        else
            cout << "Volunteer cheated!" << endl;
    }
    return 0;
}
