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
	int s, t, ant, next;
	long long flow;
} E[MAXM * 2];
const long long inf = 2000000000000000LL;
int ST[MAXN], Etop[MAXN], n, m, S, T, etop;
long long W;
void add_edge(int s, int t, long long w, int _ant)
{
	etop++;
	E[etop].s = s;
	E[etop].t = t;
	E[etop].flow = w;
	E[etop].ant = etop + _ant;
	E[etop].next = 0;
	if(Etop[s])
		E[Etop[s]].next = etop;
	else
		ST[s] = etop;
	Etop[s] = etop;
}
int h[MAXN], vn[MAXN];
long long MaxFlow;
long long find(int v, long long F_limit)
{
	if(v == n)
		return F_limit;
	long long left = F_limit, f;
	int temp = n - 1;
	for(int i = ST[v]; i; i = E[i].next)
	{
		long long res = E[i].flow;
		if(res)
			if(h[v] == h[E[i].t] + 1)
			{
				long long MIN = res < left ? res : left;
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
while(scanf("%d%d", &m, &n))
{
	etop = 0;
	while(m--)
	{
		scanf("%d%d%lld", &S, &T, &W);
		add_edge(S, T, W, 1);
		add_edge(T, S, 0, -1);
	}
	memset(h, 0, sizeof(h));
	memset(vn, 0, sizeof(vn));
	MaxFlow = 0;
	vn[0] = n;
	while(h[1] < n)
		MaxFlow += find(1, inf);
	printf("%lld\n", MaxFlow);
}
	return 0;
}
