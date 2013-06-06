#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <deque>
#include <cmath>
#define MAXN 3010
#define MAXM 30010
#define rep(i, n) for(int i = 1; i <= (n); i++)
using namespace std;

struct edge{
	int s, t, w, f, next, ant;
} e[MAXM];

int n, m, S, T, etop(0), top[MAXN];
int pre[MAXN], dis[MAXN];
deque<int> que;
bool v[MAXN];

void add(int s, int t, int w, int f, int a){
	etop++;
	e[etop].s = s;
	e[etop].t = t;
	e[etop].w = w;
	e[etop].f = f;
	e[etop].ant = etop + a;
	e[etop].next = top[s];
	top[s] = etop;
}

bool SPFA(){
	memset(pre, 0, sizeof(pre));
	memset(v, 0, sizeof(v));
	rep(i, T)
		dis[i] = INT_MAX;
	que.clear();
	dis[S] = 0;
	v[S] = 1;
	que.push_front(S);
	while(!que.empty()){
		int V = top[que.back()];
		while(V){
			if(e[V].f && dis[e[V].s] + e[V].w < dis[e[V].t]){
				dis[e[V].t] = dis[e[V].s] + e[V].w;
				pre[e[V].t] = V;
				if(!v[e[V].t])
					que.push_front(e[V].t);
				v[e[V].t] = 1;
			}
			V = e[V].next;
		}
		v[e[top[que.back()]].s] = 0;
		que.pop_back();
	}
	return dis[T] != INT_MAX;
}

int min_cost_max_flow(){
	int cost = 0, flow, v;
	while(SPFA()){
		flow = INT_MAX;
		v = T;
/**************************
		while(v != S){
			flow = min(flow, e[pre[v]].f);
			v = e[pre[v]].s;
		}
**************************/
		flow = 1;
		v = T;
		while(v != S){
			cost += flow * e[pre[v]].w;
			e[pre[v]].f -= flow;
			e[e[pre[v]].ant].f += flow;
			e[e[pre[v]].ant].w = -e[pre[v]].w;
			v = e[pre[v]].s;
		}
	}
	return cost;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, m){
		int s, t, w;
		scanf("%d%d%d", &s, &t, &w);
		add(s, t, w, 1, 1);
		add(t, s, w, 1, -1);
	}
	add(n + 1, 1, 0, 2, 2);
	add(n, n + 2, 0, 2, 1);
	S = n + 1; T = n + 2;
	printf("%d\n", min_cost_max_flow());
	return 0;
}
