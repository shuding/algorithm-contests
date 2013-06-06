/*
* Copyright (C) 2012 All rights reserved.
* File name:  fes.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.12
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
#define MAXN 600
#define MAXM 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = ~0U >> 2;

struct edge{
	int t, l, next;
	edge(){}
	edge(int t, int l, int n):
		t(t), l(l), next(n){}
} e[MAXM * 2 + 10];

int n, m1, m2, etop, st[MAXN + 10], bel[MAXN + 10];
int dfn[MAXN + 10], low[MAXN + 10], dis[MAXN + 10][MAXN + 10];
int now, Index, sccNum, stackSize, stack[MAXN + 10], maxl[MAXN + 10];
bool inStack[MAXN + 10];

void addEdge(int s, int t, int l){
	e[++etop] = edge(t, l, st[s]);
	st[s] = etop;
}

void tarjan(int v){
	dfn[v] = low[v] = ++Index;
	inStack[v] = 1;
	stack[++stackSize] = v;
	for(int i = st[v]; i; i = e[i].next)
		if(!dfn[e[i].t]){
			tarjan(e[i].t);
			low[v] = min(low[v], low[e[i].t]);
		}
		else if(inStack[e[i].t])
			low[v] = min(low[v], dfn[e[i].t]);
	if(low[v] == dfn[v]){
		sccNum++;
		do{
			now = stack[stackSize--];
			inStack[now] = 0;
			bel[now] = sccNum;
		}while(now != v);
	}
}

int main(){
	scanf("%d%d%d", &n, &m1, &m2);
	int a, b;
	rep(i, m1){
		scanf("%d%d", &a, &b);
		addEdge(a, b, 1);
		addEdge(b, a, -1);
	}
	rep(i, m2){
		scanf("%d%d", &a, &b);
		addEdge(a, b, 0);
	}
	rep(i, n)
		if(!dfn[i]) tarjan(i);
	rep(i, n)
		rep(j, n)
			dis[i][j] = i == j ? 0 : -inf;
	rep(i, n)
		for(int j = st[i]; j; j = e[j].next)
			if(bel[i] == bel[e[j].t])
				dis[i][e[j].t] = max(dis[i][e[j].t], e[j].l);
	rep(k, n)
		rep(i, n)
			rep(j, n)
				dis[i][j] = max(dis[i][k] + dis[k][j], dis[i][j]);
	rep(i, n)
		if(dis[i][i] > 0){
			puts("NIE");
			return 0;
		}
	rep(i, n)
		rep(j, n) if(bel[i] == bel[j])
			maxl[bel[i]] = max(maxl[bel[i]], abs(dis[i][j]));
	int tot = sccNum;
	rep(i, sccNum)
		tot += maxl[i];
	printf("%d\n", tot);
	return 0;
}

