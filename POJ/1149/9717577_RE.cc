#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAXN 150
using namespace std;
const int inf = 1000;//~0U >> 1;
int n, m, S, T, g[MAXN][MAXN], hn[MAXN], h[MAXN];
int S0[MAXN], ST[MAXN], NUM[MAXN];

int aug(int v, int lim)
{
	if(v == T || !lim)
		return lim;
	int left = lim, tmp = n - 1;
	rep(i, n)
	{
		if(g[v][i] && h[v] == h[i] + 1)
		{
			int MIN = min(g[v][i], left);
			int f = aug(i, MIN);
			left -= f;
			g[v][i] -= f;
			g[i][v] += f;
			if(!left || h[S] == n)
				return lim - left;
		}
		if(g[v][i])
			tmp = min(tmp, h[i]);
	}
	if(left == lim)
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
/************BUILD_GRAPH**************/
	scanf("%d%d", &m, &n);
	rep(i, m)
		scanf("%d", &NUM[i]);
	int a, b, N;
	rep(i, n)
	{
		scanf("%d", &a);
		rep(j, a)
		{
			scanf("%d", &N);
			if(!S0[N])
				S0[N] = i;
			if(ST[N])
				g[ST[N]][i] = inf;
			ST[N] = i;
		}
		scanf("%d", &b);
		g[i][n + 2] += b;
	}
	rep(i, m)
		if(S0[i])
			g[n + 1][S0[i]] += NUM[i];
	n = n + 2;
	S = n - 1;
	T = n;
/*****************SAP*****************/
	int MaxFlow = 0;
	hn[0] = n;
	while(h[S] != n)
		MaxFlow += aug(S, inf);
	printf("%d", MaxFlow);
}
