/***************************************************
*
*   Copyright (C) 2012 All rights reserved.
*   File name:  1179.cpp
*   Author:     Parabola_ds
*   Creat time: 2012.04.27
*
***************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define MAXN 500050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct edge{
	int t, next;
	edge(){}
	edge(int t, int n): t(t), next(n){}
} e[MAXN];

int n, m, s, t, top, index, tot, S, P, etop, st[MAXN];
int w[MAXN], dfn[MAXN], low[MAXN], stack[MAXN], ref[MAXN], f[MAXN];
long long sum[MAXN];
bool instack[MAXN];
vector<int> g[MAXN];

void add(int a, int b){
	e[++etop] = edge(b, st[a]);
	st[a] = etop;
}

void tarjan(int v){
	dfn[v] = low[v] = ++index;
	instack[v] = 1;
	stack[++top] = v;
	for(int j = st[v]; j; j = e[j].next)
		if(!dfn[e[j].t]){
			tarjan(e[j].t);
			low[v] = min(low[v], low[e[j].t]);
		}
		else if(instack[e[j].t])
			low[v] = min(low[v], dfn[e[j].t]);
	if(dfn[v] == low[v]){
		tot++;
		int tmp;
		do{
			tmp = stack[top--];
			ref[tmp] = tot;
			instack[tmp] = 0;
			sum[tot] += (long long)w[tmp];
		}while(tmp != v);
	}
}

long long dis[MAXN];
bool inque[MAXN];
deque<int> que;

long long max_cost(){
	rep(i, tot) dis[i] = inque[i] = 0;
	inque[ref[S]] = 1;
	dis[ref[S]] = sum[ref[S]];
	que.push_back(ref[S]);
	while(!que.empty()){
		int Q = que.back();
		for(vector<int>::iterator it = g[Q].begin(); it != g[Q].end(); ++it)
			if(dis[Q] + sum[*it] > dis[*it]){
				dis[*it] = dis[Q] + sum[*it];
				if(!inque[*it])
					que.push_front(*it);
				inque[*it] = 1;
			}
		que.pop_back();
		inque[Q] = 0;
	}
	long long max_dis = 0;
	rep(i, P)
		max_dis = max(max_dis, dis[ref[f[i]]]);
	return max_dis;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, m){
		scanf("%d%d", &s, &t);
		add(s, t);
	}
	rep(i, n)
		scanf("%d", &w[i]);
	scanf("%d%d", &S, &P);
	rep(i, P)
		scanf("%d", &f[i]);
	rep(i, n)
		if(!dfn[i])
			tarjan(i);
	rep(i, n)
		for(int j = st[i]; j; j = e[j].next)
			if(ref[e[j].t] != ref[i])
				g[ref[i]].push_back(ref[e[j].t]);
	printf("%lld\n", max_cost());
	return 0;
}
