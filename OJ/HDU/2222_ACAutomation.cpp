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
#define MAXN 500000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct nodeStruct{
	int cnt, fail, ch[26];
} node[MAXN + 10];

int tot, q[MAXN + 10];

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
	node[0].fail = 0;
	while(l <= r){
		int x = q[l++];
		for(int i = 0; i < 26; ++i){
			int now = node[x].ch[i];
			if(now){
				int y = node[x].fail;
				while(y && !node[y].ch[i]) y = node[y].fail;
				if(y)
					node[now].fail = node[y].ch[i];
				else
					node[now].fail = 1;
				q[++r] = now;
			}
		}
	}
}

int count(char *s){
	int tot = 0, p = 1, len = strlen(s);
	for(int i = 0; i < len; ++i){
		while(p && !node[p].ch[s[i] - 'a']) p = node[p].fail;
		if(!p) p = 1; else p = node[p].ch[s[i] - 'a'];
		for(int x = p; x && node[x].cnt >= 0; x = node[x].fail){
			tot += node[x].cnt;
			node[x].cnt = -1;
		}
	}
	return tot;
}

char str[MAXL + 10];

int main(){
	int testNum, n;
	scanf("%d", &testNum);
	while(testNum--){
		tot = 1;
		memset(node[1].ch, 0, sizeof(node[1].ch));
		scanf("%d", &n);
		rep(i, n){
			scanf("%s", str);
			insert(str);
		}
		build();
		scanf("%s", str);
		printf("%d\n", count(str));
	}
	return 0;
}

