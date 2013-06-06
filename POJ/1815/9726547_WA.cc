/*
ID:ds303071
TASK:telecow
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int inf = ~0U >> 1;
const int MAXN = 200 + 10;
int dn, n, m, S, T, MaxFlow, g[MAXN][MAXN], f[MAXN][MAXN];
int h[MAXN], hn[MAXN];
bool del[MAXN], ans[MAXN], vst[MAXN];

int augment(int v, int lim)
{
	if(v == T || !lim)
		return lim;
	int left = lim, f, tmp = dn - 1;
	rep(i, n)
		if(!del[i] && !vst[i])
		{
			if(g[v][i] && h[v] == h[i] + 1)
			{
				int MIN = min(g[v][i], left);
				f = augment(i, MIN);
				left -= f;
				g[v][i] -= f;
				g[i][v] += f;
				if(f && i != S && i != T)
					vst[i] = 1;
				if(!left || h[S] == dn)
					return lim - left;
			}
			if(g[v][i])
				tmp = min(tmp, h[i]);
		}
	if(lim == left)
	{
		hn[h[v]]--;
		if(!hn[h[v]])
			h[S] = dn;
		else
		{			
			h[v] = tmp + 1;
			hn[h[v]]++;
		}
	}
	return lim - left;
}

int SAP()
{
	memset(h, 0, sizeof(h));
	memset(hn, 0, sizeof(hn));
	memset(vst, 0, sizeof(vst));
	hn[0] = dn;
	int tot = 0;
	while(h[S] != dn)
		tot += augment(S, inf);
	return tot;
}

int main()
{
	scanf("%d%d%d", &n, &S, &T);
	rep(i, n)
		rep(j, n)
		{
			scanf("%d", &g[i][j]);
			f[i][j] = g[i][j];
		}
	memset(del, 0, sizeof(del));
	dn = n;
	MaxFlow = SAP();
	if(MaxFlow == inf)
	{
		printf("NO ANSWER!\n");
		return 0;
	}
	bool _space = 0;
	printf("%d\n", MaxFlow);
	rep(i, n)
		if(i != S && i != T)
		{
			del[i] = 1;
			dn--;
			rep(j, n)
				rep(k, n)
					g[j][k] = f[j][k];
			int NowFlow = SAP();
			if(NowFlow < MaxFlow)
			{
				if(_space)
					printf(" ");
				printf("%d", i);
				_space = 1;
				MaxFlow = NowFlow;
			}
			else
			{
				del[i] = 0;
				dn++;
			}
		}
	return 0;
}
