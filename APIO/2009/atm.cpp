/***************************************************
*
*   Copyright (C) 2012 All rights reserved.
*   File name:  atm.cpp
*   Author:     Parabola_ds
*   Creat time: 2012.04.29
*
***************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define MAXN 500050
#define MAXM 500050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct edge{
	int t, next;
	edge(){}
	edge(int t, int n): t(t), next(n){}
} e[MAXM];

int n, m, a, b, S, P, index, tot, s[MAXN], _s[MAXN];
int etop, st[MAXN], bar[MAXN], bel[MAXN];
int stop, dfn[MAXN], low[MAXN], stack[MAXN];
bool instack[MAXN];

void add(int a, int b){
	e[++etop] = edge(b, st[a]);
	st[a] = etop;
}

void tarjan(int v){
	dfn[v] = low[v] = ++index;
	stack[++stop] = v;
	instack[v] = 1;
	for(int u = st[v]; u; u = e[u].next)
		if(!dfn[e[u].t]){
			tarjan(e[u].t);
			low[v] = min(low[v], low[e[u].t]);
		}
		else if(instack[e[u].t])
			low[v] = min(low[v], dfn[e[u].t]);
	if(low[v] == dfn[v]){
		tot++;
		int tmp;
		do{
			tmp = stack[stop--];
			bel[tmp] = tot;
			_s[tot] += s[tmp];
		}while(tmp != v);
	}
}

int dis[MAXN], que[MAXN];
bool v[MAXN];
vector<int> g[MAXN];

void spfa(){
	int p, q, Q;
	que[p = q = 1] = bel[S];
	dis[bel[S]] = _s[bel[S]];
	while(p <= q){
		Q = que[p];
		for(vector<int>::iterator it = g[Q].begin(); it != g[Q].end(); ++it)
			if(dis[*it] < dis[Q] + _s[*it]){
				dis[*it] = dis[Q] + _s[*it];
				if(!v[*it])
					que[++q] = *it;
				v[*it] = 1;
			}
		v[que[p++]] = 0;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, m){
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	rep(i, n)
		scanf("%d", &s[i]);
	scanf("%d%d", &S, &P);
	rep(i, P)
		scanf("%d", &bar[i]);
	rep(i, n)
		if(!dfn[i])
			tarjan(i);
	rep(i, n)
		for(int j = st[i]; j; j = e[j].next)
			if(bel[i] != bel[e[j].t])
				g[bel[i]].push_back(bel[e[j].t]);
	spfa();
	int ans = 0;
	rep(i, P)
		ans = max(ans, dis[bel[bar[i]]]);
	printf("%d\n", ans);
	return 0;
}

