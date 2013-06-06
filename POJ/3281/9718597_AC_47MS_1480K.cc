#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAXN 500
using namespace std;
const int inf = ~0U >> 1;
int n, ff, dd, S, T, f[MAXN][MAXN], h[MAXN], hn[MAXN], M = 0;
int aug(int v, int lim)
{
	if(v == T || !lim)
		return lim;
	int left = lim, tmp = n - 1;
	rep(i, n)
	{
		if(f[v][i] && h[v] == h[i] + 1)
		{
			int MIN = min(left, f[v][i]);
			int flow = aug(i, MIN);
			left -= flow;
			f[v][i] -= flow;
			f[i][v] += flow;
			if(h[S] == n || !left)
				return lim - left;
		}
		if(f[v][i])
			tmp = min(tmp, h[i]);
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
	scanf("%d%d%d", &n, &ff, &dd);
	S = n + n + ff + dd + 1;
	T = S + 1;
	int F, D, t;
	rep(i, n)
	{
		scanf("%d%d", &F, &D);
		rep(j, F)
		{
			scanf("%d", &t);
			f[t][ff + i] = 1;
		}
		rep(j, D)
		{
			scanf("%d", &t);
			f[ff + n + i][ff + n + n + t] = 1;
		}
		f[ff + i][ff + n + i] = 1;
	}
	rep(i, ff)
		f[S][i] = 1;
	rep(i, dd)
		f[ff + n + n + i][T] = 1;
	n = ff + n + n + dd + 2;
	hn[0] = n;
	while(h[S] != n)
		M += aug(S, inf);
	printf("%d", M);
}
