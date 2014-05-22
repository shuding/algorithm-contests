/*
* Copyright (C) 2012 All rights reserved.
* File name:  2222.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.11
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define MAXL 1000000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct nodeStruct{
    int cnt, fail, ch[26];
} node[500001];

int tot, q[500001];;
void insert(char *s){
    int p = 1, len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(!node[p].ch[s[i] - 'a']){
            node[p].ch[s[i] - 'a'] = ++tot;
			node[tot].cnt = 0;
			node[tot].fail = 0;
			memset(node[tot].ch, 0, sizeof(node[tot].ch));
		}
        p = node[p].ch[s[i] - 'a'];
    }
    node[p].cnt++;
}

void build(){
    int l, r;
    q[l = r = 1] = 1;
    node[1].fail = 0;
    while(l <= r){
        int x = q[l++];
        for(int i = 0; i < 26; ++i){
            int now = node[x].ch[i], t = (x == 1) ? 1 : node[node[x].fail].ch[i];
            if(!now) node[x].ch[i] = t;
            else{
                node[now].fail = t;
                q[++r] = now;
            }
        }
    }
}

int count(){
    int tot = 0, p = 1;
    char c = getchar();
    while(c < 'a' || c > 'z') c = getchar();
    while(c >= 'a' && c <= 'z'){
        p = node[p].ch[c - 'a'];
        for(int x = p; x != 1; x = node[x].fail){
            if(node[x].cnt >= 0){
                tot += node[x].cnt;
                node[x].cnt = -1;
            }
            else break;
        }
        c = getchar();
    }
    return tot;
}

char sstr[100];

int main(){
    int testNum, n;
    scanf("%d", &testNum);
    while(testNum--){
		tot = 1;
		memset(node[1].ch, 0, sizeof(node[1].ch));
        scanf("%d", &n); getchar();
        rep(i, n){
            gets(sstr);
            insert(sstr);
        }
        build();
        printf("%d\n", count());
    }
    return 0;
}

