/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : G.cpp
*   Creation Time : 2013/06/27 17:08:43
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
#define MAXN    110
#define MAXM     30
#define MAXLEN  110
using namespace std;

struct teamData{
    char name[MAXLEN];
    double score;
    int contestNum;
    teamData(){
        score = 0;
        contestNum = 0;
    }
} team[MAXN];

int n, m, nameLen;
int teamNum, probNum, runNum, teamNo[MAXN], timeCnt[MAXN], probCnt[MAXN];
int solved[MAXN][MAXM];
double a, b;
pair<int, pair<int, int> > sortData[MAXN];

void handleContest(){
    scanf("%d", &teamNum);
    rep(i, teamNum)
        scanf("%d", &teamNo[i]);
    scanf("%d%d", &probNum, &runNum);
    memset(timeCnt, 0, sizeof timeCnt);
    memset(probCnt, 0, sizeof probCnt);
    memset(solved, 0, sizeof solved);
    int n, p, t;
    char c;
    rep(i, runNum){
        scanf("%d", &n);
        c = getchar();
        while(c > 'Z' || c < 'A')
            c = getchar();
        p = int(c - 'A') + 1;
        scanf("%d", &t);
        c = getchar();
        while(c != '+' && c != '-')
            c = getchar();
        if(solved[n][p] != -1){
            if(c == '+')
                timeCnt[n] += t + solved[n][p], probCnt[n]++, solved[n][p] = -1;
            else
                solved[n][p] += 20;
        }
    }
    b = teamNum - 2;
    a = 2 * (1 + b);
    rep(i, teamNum){
        sortData[i].first = -probCnt[teamNo[i]];
        sortData[i].second = mp(timeCnt[teamNo[i]], teamNo[i]);
    }
    sort(sortData + 1, sortData + 1 + teamNum);
    int rk = 0;
    rep(i, teamNum){
        if(i == 1 || sortData[i].first != sortData[i - 1].first || 
                sortData[i].second.first != sortData[i - 1].second.first)
            rk = i;
        team[sortData[i].second.second].score +=
            double(sortData[i].first) / sortData[1].first * a / (rk + b);
        team[sortData[i].second.second].contestNum ++;
    }
}

int main(){
    cin >> n;
    rep(i, n){
        cin.getline(team[i].name, MAXLEN);
        nameLen = max(nameLen, (int)strlen(team[i].name));
    }
    cin >> m;
    rep(i, m)
        handleContest();
    rep(i, n){
        if(!team[i].contestNum)
            team[i].score = 0;
        else
            team[i].score /= team[i].contestNum;
        printf("%s", team[i].name);
        int len = nameLen + 1 - strlen(team[i].name);
        rep(j, len)
            printf(" ");
        printf("%.4lf\n", team[i].score);
    }
    return 0;
}
