// Note		SAP算法,邻接表 
#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5050
#define MAXM 30050
using namespace std;
struct EDGE
{
	int s, t, flow, ant, next;
} E[MAXN * 2];
const long long inf = (1ll)<<60;
int ST[MAXN], Etop[MAXN], n, m, S, T, W, etop;
void add_edge(int s, int t, int w, int _ant)
{
	etop++;
	E[etop].s = s;
	E[etop].t = t;
	E[etop].flow = w;
	E[etop].ant = etop + _ant;
	if(Etop[s])
		E[Etop[s]].next = etop;
	else
		ST[s] = etop;
	Etop[s] = etop;
}
int h[MAXN], vn[MAXN];
long long MaxFlow;
int find(int v, long long F_limit)
{
	if(v == n)
		return F_limit;
	long long left = F_limit;
	int f, temp = n - 1;
	for(int i = ST[v]; i; i = E[i].next)
	{
		int res = E[i].flow;
		if(res)
			if(h[v] == h[E[i].t] + 1)
			{
				int MIN = res < left ? res : left;
				f = find(E[i].t, MIN);
				left -= f;
				E[i].flow -= f;
				E[E[i].ant].flow += f;
				if(!left || h[1] == n)
					return F_limit - left;
			}
		if(res)
			temp = min(h[E[i].t], temp);
	}
	if(left == F_limit)
	{
		vn[h[v]]--;
		if(!vn[h[v]])
			h[1] = n;
		else
		{
			h[v] = temp + 1;
			vn[h[v]]++;
		}
	}
	return F_limit - left;
}
int main()
{
	scanf("%d%d", &n, &m);
	etop = 0;
	while(m--)
	{
		scanf("%d%d%d", &S, &T, &W);
		add_edge(S, T, W, 1);
		add_edge(T, S, W, -1);
		add_edge(T, S, 0, -1);
	}
	memset(h, 0, sizeof(h));
	MaxFlow = 0;
	vn[0] = n;
	while(h[1] < n)
		MaxFlow += find(1, inf);
	printf("%lld\n", MaxFlow);
	return 0;
}
