#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define MAXN 500
using namespace std;
typedef long long int64;
const int64 inf = 200000000000;
int f, p, S, T;
int64 s, t, _path, l, r, mid, N = 0, h[MAXN], hn[MAXN], g[MAXN][MAXN], _g[MAXN][MAXN];

inline void read(int64 &n)
{
	char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	n = 0;
	while(c >= '0' && c <= '9')
	{
		n = n * 10 + c - '0';
		c = getchar();
	}
}

void init()
{
	scanf("%d%d", &f, &p);
	S = 2 * f + 1;
	T = S + 1;
	rep(i, f)
	{
		read(g[S][i]);
		read(g[i + f][T]);
		N += g[S][i];
		g[i][i + f] = inf;
	}
	rep(i, p)
	{
		read(s);
		read(t);
		read(_path);
		if(!g[s][t] || _path < g[s][t])
			g[t][s] = g[s][t] = _path;
	}
}

void floyd()
{
	rep(k, f)
		rep(i, f)
			rep(j, f)
				if(g[i][k] && g[k][j])
					if(g[i][j])
						g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
					else
						g[i][j] = g[i][k] + g[k][j];
	rep(i, f)
		rep(j, f)
			if(i != j && g[i][j])
			{
				g[i][j + f] = g[i][j];
				g[i][j] = 0;
			}
	memcpy(_g, g, sizeof(g));
}

int64 aug(int v, int64 lim)
{
	if(v == T || !lim)
		return lim;
	int64 left = lim, _f, tmp = T - 1;
	rep(i, T)
	{
		if(g[v][i] && h[v] == h[i] + 1)
		{
			_f = aug(i, min(left, g[v][i]));
			left -= _f;
			g[v][i] -= _f;
			g[i][v] += _f;
			if(h[S] == T)
				return lim - left;
		}
		if(g[v][i])
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

int64 MaxFlow()
{
	memset(h, 0, sizeof(h));
	memset(hn, 0, sizeof(hn));
	memcpy(g, _g, sizeof(_g));
	hn[0] = T;
	int64 flow = 0;
	rep(i, f)
		rep(j, f)
		{
			if(i != j && g[i][j + f] > mid)
				g[i][j + f] = 0;
			if(g[i][j + f])
				g[i][j + f] = inf;
			if(i == j)
				g[i][j] = g[i + f][j + f] = 0;
		}
	while(h[S] != T)
		flow += aug(S, inf);
	return flow;
}

void calc()
{
	l = 0;
	r = inf;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(MaxFlow() == N)
			r = mid - 1;
		else
			l = mid + 1;
	}
	if(l < inf)
		cout << l << endl;
	else
		cout << -1 << endl;
}

int main()
{
	init();
	floyd();
	calc();
	return 0;
}
