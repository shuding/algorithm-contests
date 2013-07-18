/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File ame     : B.cpp
*   Creation Time : 2013/06/26 11:58:38
*   Environment   : OS  10.8 & Vim 7.3
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

typedef set<pair<int, int> >::iterator spiiit;
set<pair<int, int> > in, out;
int n, x, y, d;

void add(int j, int k){
    in.insert(mp(j, k));
    out.insert(mp(j - 1, k - 1));
    out.insert(mp(j - 1, k));
    out.insert(mp(j - 1, k + 1));
    out.insert(mp(j, k - 1));
    out.insert(mp(j, k + 1));
    out.insert(mp(j + 1, k - 1));
    out.insert(mp(j + 1, k));
    out.insert(mp(j + 1, k + 1));
}

bool check(int x, int y){
    return in.find(mp(x, y)) != in.end()
        || in.find(mp(x - 1, y)) != in.end()
        || in.find(mp(x, y - 1)) != in.end()
        || in.find(mp(x - 1, y - 1)) != in.end();
}

bool isHangPoint(pair<int, int> p){
    return check(p.first, p.second)
        && check(p.first + 1, p.second)
        && check(p.first, p.second + 1)
        && check(p.first + 1, p.second + 1);
}

int main(){
    freopen("control.in", "r", stdin);
    freopen("control.out", "w", stdout);
    while(scanf("%d", &n) != EOF && n > 0){
        in.clear();
        out.clear();
        rep(i, n){
            scanf("%d%d%d", &x, &y, &d);
            for(int j = x - d - 1; j <= x + d + 1; ++j)
                for(int k = y - d - 1; k <= y + d + 1; ++k)
                    if(abs(j - x) + abs(k - y) <= d + 2)
                        add(j, k);
        }
        spiiit it, t;
        while(!out.empty()){
            it = out.begin();
            t = in.find(*it);
            if(t == in.end() && isHangPoint(*it))
                add(it->first, it->second);
            out.erase(it);
        }
        cout << in.size() << endl;
    }
    return 0;
}
