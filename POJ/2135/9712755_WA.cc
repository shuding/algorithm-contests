// Note		SPFA最小费用最大流
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAXN 1000
using namespace std;

const int inf = ~0U >> 1;
int n, m, s, t, w, p, MaxFlow, Aug, M = 0, S, T;
int f[MAXN][MAXN], v[MAXN][MAXN];
queue<int> que;
int spfa()
{
	int	dis[MAXN], pre[MAXN];
	bool vst[MAXN] = {0};

	rep(i, n)
		dis[i] = inf;
	pre[S] = 1;
	dis[S] = 0;
	vst[S] = 1;
	que.push(S);
	while(!que.empty())
	{
		rep(i, n)
			if(f[que.front()][i] && dis[que.front()] + v[que.front()][i] < dis[i])
			{
				dis[i] = dis[que.front()] + v[que.front()][i];
				if(!vst[i])
				{
					que.push(i);
					vst[i] = 1;
					pre[i] = que.front();
				}
			}
		vst[que.front()] = 0;
		que.pop();
	}
	if(!pre[T])
		return 0;
	int V = T, MIN = inf, TOT = 0;
	while(V != S)
	{
		MIN = min(MIN, f[pre[V]][V]);
		V = pre[V];
	}
	V = T;
	while(V != S)
	{
		f[pre[V]][V] -= MIN;
		f[V][pre[V]] += MIN;
		TOT += MIN * v[pre[V]][V];
		V = pre[V];
	}
	M += MIN;
	return TOT;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m)
	{
		//scanf("%d%d%d%d", &s, &t, &w, &p);
		scanf("%d%d%d", &s, &t, &p);
		//f[s][t] = f[t][s] = w;
		f[s][t] = f[t][s] = 1;
		v[s][t] = v[t][s] = p;
	}

	S = 1; T = n;
	MaxFlow = 0;
	while((Aug = spfa()) > 0)
		MaxFlow += Aug;

	printf("MaxFlow = %d\nMinCost = %d\n", M, MaxFlow);
	return 0;
}
