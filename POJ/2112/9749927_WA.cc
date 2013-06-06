#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAX 500
using namespace std;

const int inf = 1000000000;

int k, c, m, S, T, g[MAX][MAX], f[MAX][MAX], _g[MAX][MAX];
int l = 0, r = 0, mid;

int h[MAX], hn[MAX];

int Aug(int v, int lim)
{
    if(v == T || !lim)
	return lim;
    int left = lim, tmp = T - 1;
    rep(i, T)
    {
	if(f[v][i] && h[v] == h[i] + 1)
	{
	    int MIN = min(left, f[v][i]);
	    int F = Aug(i, MIN);
	    left -= F;
	    f[v][i] -= F;
	    f[i][v] += F;
	    if(h[S] == T)
		return lim - left;
	}
	if(f[v][i])
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
    memset(f, 0, sizeof(f));
    hn[0] = T;
    int F = 0;
    rep(i, k)
	f[S][i] = m;
    rep(i, c)
	f[k + i][T] = 1;
    rep(i, k + c)
	rep(j, k + c)
	    _g[i][j] = g[i][j];
    rep(_k, k + c)
	rep(i, k + c)
	    rep(j, k + c)
		if(_g[i][_k] <= mid && _g[_k][j] <= mid)
		    _g[i][j] = min(_g[i][j], _g[i][_k] + _g[_k][j]);
    rep(i, k + c)
	rep(j, k + c)
	    if(_g[i][j] <= mid)
		f[i][j] = inf;
    while(h[S] != T)
	F += Aug(S, inf);
    return F;
}

int main()
{
    scanf("%d%d%d", &k, &c, &m);
    rep(i, k + c)
	rep(j, k + c)
	{
	    scanf("%d", &g[i][j]);
	    if(!g[i][j])
		g[i][j] = inf;
	}
    S = k + c + 1;
    T = S + 1;
    r = 256;
    while(l <= r)
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
