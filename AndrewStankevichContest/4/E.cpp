/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : E.cpp
*   Creation Time : 2013/06/12 17:12:38
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
#define MAXN 2010
#define inf -10000
using namespace std;

struct dvd{
    string name;
    int year, region;
    void read(){
        name.clear();
        char c = getchar();
        while(c != '"')
            c = getchar();
        do{
            name += c;
            c = getchar();
        } while(c != '"');
        name += c;
        scanf("%d%d", &year, &region);
    }
    bool operator < (const dvd &d) const{
        if(year != d.year)
            return year < d.year;
        return region != d.region;
    }
} d[MAXN];

int n, m, f[MAXN][6][6][6], num[6], st[11], L[MAXN], R[MAXN], T[MAXN];
int dp[MAXN][6][6], preJ[MAXN][6][6], preK[MAXN][6][6], preR[MAXN][6][6];
int ansI, ansJ, ansK;
bool preD[MAXN][6][6], inPre[6][6], used[6];
vector<int> reg[MAXN][6];

void calcOutput(int i, int j, int k){
    if(!i)
        return;
    L[i] = preR[i][j][k];
    R[i] = j;
    T[i] = k - preK[i][j][k] - preD[i][j][k];
    calcOutput(i - 1, preJ[i][j][k], preK[i][j][k]);
}

void output(int v){
    memset(used, 0, sizeof used);
    for(int i = 0; i < reg[v][L[v]].size(); ++i)
        printf("%s\n", d[reg[v][L[v]][i]].name.c_str());
    used[L[v]] = used[R[v]] = 1;
    rep(i, T[v] - 1){
        int tmp = -1;
        rep(j, 5)
            if(!used[j] && (tmp == -1 || reg[v][j].size() > reg[v][tmp].size()))
                tmp = j;
        used[tmp] = 1;
        for(int j = 0; j < reg[v][tmp].size(); ++j)
            printf("%s\n", d[reg[v][tmp][j]].name.c_str());
    }
    if(L[v] != R[v])
        for(int i = 0; i < reg[v][R[v]].size(); ++i)
            printf("%s\n", d[reg[v][R[v]][i]].name.c_str());
}

int main(){
//    freopen("dvd.in", "r", stdin);
//    freopen("dvd.out", "w", stdout);
    scanf("%d", &n);
    rep(i, n)
        d[i].read();
    sort(d + 1, d + 1 + n);
    for(int top = 1, ed = 1; top <= n; top = ed){
        rep(i, 5)
            num[i] = 0;
        while(ed <= n && d[ed].year == d[top].year){
            num[d[ed].region]++;
            reg[m + 1][d[ed].region].pb(ed);
            ++ed;
        }
        ++m;
        rep(i, 5)
            st[i] = -num[i], st[i + 5] = 0;
        sort(st + 1, st + 1 + 5);
        rep(i, 5)
            rep(j, 5)
                inPre[i][j] = (num[i] >= -st[j]);
        rep(i, 10)
            st[i] += st[i - 1];
        rep(i, 5) if(num[i])
            rep(j, 5) if(num[j])
                if(i == j)
                    f[m][i][j][0] = num[i];
                else
                    rep(k, 5)
                        f[m][i][j][k] =
                        - st[k - 1 + inPre[i][k - 1] + inPre[j][k - 1]]
                        - inPre[i][k - 1] * num[i] - inPre[j][k - 1] * num[j]
                        + num[i] + num[j];
        rep(i, 5)
            rep(j, 5) if(i != j)
                f[m][i][j][0] = inf;
    }
    int ans = 0;
    rep(i, m)
        rep(j, 5) if(!reg[i][j].empty())
            for(int k = 0; k <= 5; ++k){
                dp[i][j][k] = 0;
                rep(p, 5) if(!reg[i - 1][p].empty() || i == 1)
                    for(int q = 0; q <= k; ++q){
                        if(dp[i][j][k] < dp[i - 1][p][q] + f[i][p][j][k - q]){
                            dp[i][j][k] = dp[i - 1][p][q] + f[i][p][j][k - q];
                            preJ[i][j][k] = p;
                            preK[i][j][k] = q;
                            preR[i][j][k] = p;
                            preD[i][j][k] = 0;
                        }
                        if(k > q)
                            rep(r, 5)
                                if(dp[i][j][k] <
                                    dp[i - 1][p][q] + f[i][r][j][k - q - 1]){
                                    dp[i][j][k] = dp[i - 1][p][q] 
                                                + f[i][r][j][k - q - 1];
                                    preJ[i][j][k] = p;
                                    preK[i][j][k] = q;
                                    preR[i][j][k] = r;
                                    preD[i][j][k] = 1;
                                }
                    }
                if(dp[i - 1][j][k] > dp[i][j][k]){
                    dp[i][j][k] = dp[i - 1][j][k];
                    preJ[i][j][k] = j;
                    preK[i][j][k] = k;
                    preR[i][j][k] = 0;
                    preD[i][j][k] = 0;
                }
                if(ans < dp[i][j][k])
                    ans = dp[i][j][k], ansI = i, ansJ = j, ansK = k;
            }
    cout << ans << endl;
    calcOutput(ansI, ansJ, ansK);
    rep(i, n)
        if(L[i])
            output(i);
    return 0;
}

