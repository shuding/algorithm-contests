#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAXN 5050
#define MAXM 60050
using namespace std;
struct edge
{
	int b, e, w, next, ANT;
	long long flow;
} E[MAXM];
int n, m, s, t, w, ST[MAXN], TOP[MAXN], etop(0);
void add_edge(int s, int t, int w, int A)
{
	etop++;
	E[etop].b = s;
	E[etop].e = t;
	E[etop].w = w;
	E[etop].ANT = etop + A;
	if(TOP[s])
		E[TOP[s]].next = etop;
	else
		ST[s] = etop;
	TOP[s] = etop;
}
long long Flow(0), dis[MAXN];
bool vst[MAXN];
int Que[MAXN], Pre[MAXN], p, q;
const long long inf = 1 << 20;
long long MaxFlow(int S, int T)
{
	while(true)
	{
		memset(dis, 0, sizeof(dis));
		memset(vst, 0, sizeof(vst));
		p = q = 0;
		Que[0] = S;
		dis[S] = inf;
		vst[S] = true;
		while(p <= q)
		{
			int i = ST[Que[p]];
			while(i)
			{
				if(!vst[E[i].e] && min(dis[Que[p]], E[i].w - E[i].flow) > dis[E[i].e])
				{
					Que[++q] = E[i].e;
					dis[E[i].e] = min(dis[Que[p]], E[i].w - E[i].flow);
					vst[E[i].e] = true;
					Pre[E[i].e] = i;
				}
				i = E[i].next;
			}
			vst[Que[p++]] = false;
		}
		if(!dis[T])
			break;
		Flow += dis[T];
		int i = Pre[T];
		while(i)
		{
			E[i].flow += dis[T];
			E[E[i].ANT].flow -= dis[T];
			i = Pre[E[i].b];
		}
	}
	return Flow;
}
int main()
{
	while(scanf("%d%d", &n, &m))
	{
	rep(i, m)
	{
		scanf("%d%d%d", &s, &t, &w);
		add_edge(s, t, w, 1);
		add_edge(t, s, w, -1);
	}
	printf("%lld\n", MaxFlow(1, n));
	}
}
