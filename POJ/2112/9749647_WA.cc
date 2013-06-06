#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAX 500
using namespace std;

const int inf = 1000000000;

int k, c, m, S, T, g[MAX][MAX], f[MAX][MAX];
int l = 0, r = 0, mid;

int h[MAX], hn[MAX];

int Aug(int v, int lim)
{
    if(v == T || !lim)
	return lim;
    int left = lim, tmp = T - 1, f;
    rep(i, T)
    {
	if(g[v][i] && (g[v][i] <= mid || v == S || i == T) && h[v] == h[i] + 1)
	{
	    int MIN = min(left, g[v][i]);
	    f = Aug(i, MIN);
	    left -= f;
	    g[v][i] -= f;
	    g[i][v] += f;
	    if(h[S] == T)
		return lim - left;
	}
	if(g[v][i] && (g[v][i] <= mid || v == S || i == T))
	    tmp = min(tmp, h[i]);
    }
    if(lim == left)
    {
	hn[h[v]]--;
	if(!hn[h[v]])
	    h[S] = T;
	else
	{
	    h[v] = tmp + 1;
	    hn[h[v]]++;
	}
    }
    return lim - left;
}

int MaxFlow()
{
    memset(h, 0, sizeof(h));
    memset(hn, 0, sizeof(hn));
    hn[0] = T;
    int F = 0;
    rep(i, T)
	rep(j, T)
	    g[i][j] = f[i][j];
    while(h[S] != T)
	F += Aug(S, inf);
    return F;
}

int main()
{
    scanf("%d%d%d", &k, &c, &m);
    rep(i, k + c)
	rep(j, k + c)
	    scanf("%d", &g[i][j]);
    S = k + c + 1;
    T = S + 1;
    rep(_k, k + c)
	rep(i, k + c)
	    rep(j, k + c)
		if(g[i][_k] && g[_k][j])
		    g[i][j] = min(g[i][j], g[i][_k] + g[_k][j]);
    rep(i, k + c)
	rep(j, k + c)
	    r = max(r, g[i][j]);
    rep(i, k)
	g[S][i] = m;
    rep(i, c)
	g[k + i][T] = 1;
    rep(i, T)
	rep(j, T)
	    f[i][j] = g[i][j];
    while(l < r)
    {
	mid = (l + r) / 2;
	if(MaxFlow() == c)
	    r = mid - 1;
	else
	    l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
