#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 20020
#define MAXM 200020
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int inf = ~0U >> 1;
struct edge
{
	int s, t, flow, ant, next;
} E[4 * MAXN + 2 * MAXM];
int n, m, S, T, etop, ST[MAXN], ET[MAXN];
int h[MAXN], hn[MAXN];
void add_edge(int s, int t, int w, int _ant)
{
	etop++;
	E[etop].s = s;
	E[etop].t = t;
	E[etop].flow = w;
	E[etop].ant = etop + _ant;
	if(!ST[s])
		ST[s] = etop;
	else
		E[ET[s]].next = etop;
	ET[s] = etop;
}
int aug(int v, int lim)
{
	if(v == T || !lim)
		return lim;
	int left = lim, tmp = n - 1;
	for(int i = ST[v]; i; i = E[i].next)
	{
		if(E[i].flow && h[v] == h[E[i].t] + 1)
		{
			int MIN = min(left, E[i].flow);
			int f = aug(E[i].t, MIN);
			left -= f;
			E[i].flow -= f;
			E[E[i].ant].flow += f;
			if(h[S] == n)
				return lim - left;
		}
		if(E[i].flow)
			tmp = min(tmp, h[E[i].t]);
	}
	if(lim == left)
	{
		hn[h[v]]--;
		if(!hn[h[v]])
			h[S] = n;
		else
		{
			h[v] = tmp + 1;
			hn[h[v]]++;
		}
	}
	return lim - left;
}
int main()
{
	scanf("%d%d", &n, &m);
	S = n + 1;
	T = S + 1;
	int a, b, c, MaxFlow = 0;
	rep(i, n)
	{
		scanf("%d%d", &a, &b);
		add_edge(S, i, a, 1);
		add_edge(i, S, a, -1);
		add_edge(T, i, b, 1);
		add_edge(i, T, b, -1);
	}
	rep(i, m)
	{
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c, 1);
		add_edge(b, a, c, -1);
	}
	n += 2;
	hn[0] = n;
	while(h[S] != n)
		MaxFlow += aug(S, inf);
	printf("%d\n", MaxFlow);
}
