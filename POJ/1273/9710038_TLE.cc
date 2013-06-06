// Note		Dinic模板,USACO测试通过. 
// 			链表,适用于任何图. 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAXN 5050
#define MAXM 60050
using namespace std;
struct edge
{
	int b, e, next, ANT;
	long long flow;
} E[MAXM];
const long long inf = ~0U >> 1;
int n, m, s, t, w, ST[MAXN], TOP[MAXN], etop;
long long MaxFlow, add;

void add_edge(int s, int t, int w, int A)
{
	etop++;
	E[etop].b = s;
	E[etop].e = t;
	E[etop].flow = w;
	E[etop].ANT = etop + A;
	if(TOP[s])
		E[TOP[s]].next = etop;
	else
		ST[s] = etop;
	TOP[s] = etop;
}

int D[MAXN];
queue<int> Que;

bool bfs()
{
	memset(D, 0, sizeof(D));
	Que.push(1);
	while(!Que.empty())
	{
		int v = Que.front();
		Que.pop();
		for(int i = ST[v]; i != 0; i = E[i].next)
			if(!D[E[i].e] && E[i].e != 1 && E[i].flow)
			{
				D[E[i].e] = D[v] + 1;
				Que.push(E[i].e);
			}
	}
	return D[n] != 0;
}

long long dfs(int v, long long Lim)
{
	if(v == n)
		return Lim;
	long long _Lim = Lim;
	for(int i = ST[v]; i != 0; i = E[i].next)
		if(E[i].flow > 0 && D[E[i].e] == D[v] + 1)
		{
			long long Adj = dfs(E[i].e, min(_Lim, E[i].flow));
			E[i].flow -= Adj;
			E[E[i].ANT].flow += Adj;
			_Lim -= Adj;
		}
	return Lim - _Lim;
}

int main()
{
while(scanf("%d%d", &m, &n)){
	etop = 0;
	MaxFlow = 0;
	rep(i, m)
	{
		scanf("%d%d%d", &s, &t, &w);
		add_edge(s, t, w, 1);
		add_edge(t, s, 0, -1); //If it's unidirectional, then change w to 0.
	}
	while(bfs())
		while(add = dfs(1, inf))
			MaxFlow += add;
	printf("%lld\n", MaxFlow);}
}
