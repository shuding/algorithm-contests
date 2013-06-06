/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : blockade.cpp
*	Creation Time : 2013/01/18 17:12:52
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl
#define MAXN 50010
#define INF 10000000000000000ll
using namespace std;

struct edge{
	int t, w, next;
} e[MAXN * 2];

int n, m, u, v, w, sn;
int eTop, st[MAXN], num[MAXN];
long long rDis[MAXN];
multiset<pair<long long, int> > disList;
vector<pair<long long, int> > unReached;

void add(int u, int v, int w){
	eTop++;
	e[eTop].t = v;
	e[eTop].w = w;
	e[eTop].next = st[u];
	st[u] = eTop;
}

long long L, R, M;

pair<long long, bool> bfs(int f, int v, int V, long long d){
	pair<long long, bool> tmp;
	long long near = INF;
	bool son = 1;
	if(e[st[v]].t == f && e[st[v]].next == 0)
		son = 0;
	if(num[v]){
		if(rDis[v] >= d)
			near = 0;
		else
			for(int i = 1; i <= num[v]; ++i)
				disList.insert(make_pair(rDis[v], V));
	}
	for(int i = st[v]; i; i = e[i].next) if(e[i].t != f){
		tmp = bfs(v, e[i].t, V, d);
		if(tmp.second && tmp.first + e[i].w <= d){
			if(tmp.first + e[i].w + rDis[v] >= d)
				near = min(near, tmp.first + e[i].w);
			else
				disList.insert(make_pair(tmp.first + e[i].w + rDis[v], V));
		}
		son &= tmp.second;
	}
	return make_pair(near, son || near <= d);
}

long long used[MAXN + 10];

bool succ(int d){
	bool ret = 1;
	disList.clear();
	unReached.clear();
	for(int i = st[1]; i; i = e[i].next)
		if(!bfs(1, e[i].t, e[i].t, d).second)
			unReached.push_back(make_pair(e[i].w, e[i].t));
	if(unReached.empty())
		return 1;
	memset(used, 0, sizeof used);
	for(multiset<pair<long long, int> >::iterator it = disList.begin(); it != disList.end(); ++it)
		used[it->second] = max(used[it->second], it->first);
	sort(unReached.begin(), unReached.end());
	vector<pair<long long, int> >::iterator it = unReached.end();
	multiset<pair<long long, int> >::iterator itS;
	do{
		it--;
		if(used[it->second] && disList.find(make_pair(used[it->second], it->second)) != disList.end()){
			itS = disList.find(make_pair(used[it->second], it->second));
			disList.erase(itS);
		}
		else{
			if(disList.empty())
				return 0;
			itS = disList.begin();
			if(itS->first + it->first > d)
				return 0;
			disList.erase(itS);
		}
	}while(it != unReached.begin());
	return 1;
}

long long solve(){
	L = 0; R = 100000;
	while(L + 1 < R){
		M = (L + R) >> 1;
		if(succ(M))
			R = M;
		else
			L = M;
	}
	if(succ(L))
		return L;
	else 
		if(succ(R))
			return R;
	return -1;
}

void dfs(int v, int f, long long rD){
	rDis[v] = rD;
	for(int i = st[v]; i; i = e[i].next)
		if(e[i].t != f)
			dfs(e[i].t, v, rD + e[i].w);
}

int main(){
	freopen("blockade.in", "r", stdin);
	freopen("blockade.out", "w", stdout);
	scanf("%d", &n);
	rep(i, n - 1){
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 1, 0);
	int pos;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &pos), num[pos]++;
	for(int i = st[1]; i; i = e[i].next)
		sn++;
	if(sn > m){
		printf("-1\n");
		return 0;
	}
	cout << solve() << endl;
	return 0;
}
