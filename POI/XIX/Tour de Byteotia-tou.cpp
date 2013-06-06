#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define MAXN 1000010
#define MAXM 2000010
using namespace std;

struct edgeStruct{
	int t, id, next;
} edge[MAXM * 2];

int n, m, k, ind, top, sggNum;
int e[MAXM][2], dfn[MAXN], low[MAXN], stack[MAXN], bel[MAXN];
bool instack[MAXN];
int eTop, st[MAXN];

void addEdge(int a, int b){
	eTop++;
	edge[eTop].t = b;
	edge[eTop].id = (eTop + 1) / 2;
	edge[eTop].next = st[a];
	st[a] = eTop;
}

void tarjan(int	v){
	dfn[v] = low[v] = ++ind;
	instack[stack[++top] = v] = 1;
	for(int it = st[v]; it; it = edge[it].next)
		if(edge[it].t > k){
			if(!dfn[edge[it].t]){
				tarjan(edge[it].t);
				low[v] = min(low[v], low[edge[it].t]);
			}
			else if(instack[edge[it].t])
				low[v] = min(low[v], dfn[edge[it].t]);
		}
	if(low[v] == dfn[v]){
		sggNum++;
		int tmp;
		do{
			instack[tmp = stack[top--]] = 0;
			bel[tmp] = sggNum;
		}while(tmp != v);
	}
}

int que[MAXN];
bool inq[MAXN] = {0}, vst[MAXN] = {0}, use[MAXM] = {0}, del[MAXM] = {0};
	
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &e[i][0], &e[i][1]);
		addEdge(e[i][0], e[i][1]);
		addEdge(e[i][1], e[i][0]);
	}
	for(int i = 1; i <= k; ++i)
		bel[i] = ++sggNum;
	for(int i = k + 1; i <= n; ++i)
		if(!dfn[i])
			tarjan(i);
	for(int t = 1; t <= k; ++t) if(!vst[bel[t]]){
		vst[bel[que[top = 1] = t]] = 1;
		inq[t] = 1;
		for(int i = 1; i <= top; ++i){
			for(int it = st[que[i]]; it; it = edge[it].next)
				if(!use[edge[it].id]){
					use[edge[it].id] = 1;
					if(!vst[bel[edge[it].t]] || 
						(bel[edge[it].t] == bel[que[i]] && !inq[edge[it].t])){
						vst[bel[edge[it].t]] = 1;
						inq[edge[it].t] = 1;
						que[++top] = edge[it].t;
					}
					else if(bel[que[i]] != bel[edge[it].t])
						del[edge[it].id] = 1;
				}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= m; ++i)
		cnt += del[i];
	printf("%d\n", cnt);
	for(int i = 1; i <= m; ++i)
		if(del[i])
			printf("%d %d\n", e[i][0], e[i][1]);
	return 0;
}

