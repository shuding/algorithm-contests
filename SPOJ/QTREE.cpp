#include <cstdio>
#define MAXN 10050
using namespace std;

const int inf = ~0U >> 1;
int n, eTop;

struct node{
	int c[2], f, fw, maxCost;
	inline void update();
} nodes[MAXN];

inline void node::update(){
	maxCost = fw;
	if(c[0]) if(maxCost < nodes[c[0]].maxCost)
		maxCost = nodes[c[0]].maxCost;
	if(c[1]) if(maxCost < nodes[c[1]].maxCost)
		maxCost = nodes[c[1]].maxCost;
}

struct edge{
	int t, w, f, next;
} e[MAXN * 2];

int st[MAXN];

inline void addEdge(int s, int t, int w){
	eTop++;
	e[eTop].t = t;
	e[eTop].w = w;
	e[eTop].f = 0;
	e[eTop].next = st[s];
	st[s] = eTop;
}

inline void bfsInit(){
	for(int i = 1; i <= n; ++i)
		nodes[i].f = nodes[i].c[0] = nodes[i].c[1] = 0, 
		nodes[i].fw = nodes[i].maxCost = -inf;
	static int Queue[MAXN];
	int qTop = 0, q;
	Queue[0] = 1;
	for(int i = 0; i <= qTop; ++i){
		q = Queue[i];
		for(int j = st[q]; j; j = e[j].next)
			if(e[j].t != 1 && !nodes[e[j].t].f){
				e[j].f = q;
				Queue[++qTop] = e[j].t;
				nodes[e[j].t].f = q;
				nodes[e[j].t].fw = e[j].w;
			}
	}
	for(int i = 1; i <= eTop; ++i)
		if(e[i].f)
			e[((i - 1) ^ 1) + 1].f = e[i].f;
}

inline void rotate(int n, bool d){
	int p = nodes[n].f, q = nodes[p].f;
	nodes[nodes[p].c[d] = nodes[n].c[!d]].f = p;
	nodes[nodes[n].c[!d] = p].f = n;
	nodes[n].f = q;
	if(q && (nodes[q].c[0] == p || nodes[q].c[1] == p))
		nodes[q].c[nodes[q].c[1] == p] = n;
	nodes[p].update();
}

inline void splay(int n){
	int p, q;
	while(nodes[n].f && (nodes[nodes[n].f].c[0] == n || nodes[nodes[n].f].c[1] == n)){
		p = nodes[n].f;
		q = nodes[p].f;
		if(q && (nodes[q].c[0] == p || nodes[q].c[1] == p)){
			if((n == nodes[p].c[1]) == (p == nodes[q].c[1])){
				bool d = n == nodes[p].c[1];
				rotate(p, d), rotate(n, d);
			}
			else{
				bool d = n == nodes[p].c[1];
				rotate(n, d), rotate(n, !d);
		else
			rotate(n, n == nodes[p].c[1]);
	}
	nodes[n].update();
}

inline int access(int n){
	int v = 0;
	for(; n; n = nodes[n].f){
		splay(n);
		nodes[n].c[1] = v;
		nodes[v = n].update();
	}
	return v;
}

inline int query(int a, int b){
	access(a);
	int lca = access(b), ret = -inf;
	if(nodes[lca].c[1])
		ret = nodes[nodes[lca].c[1]].maxCost;
	if(lca != a){
		splay(a);
		if(ret < nodes[a].maxCost)
			ret = nodes[a].maxCost;
	}
	return ret;
}

inline void change(int k, int w){
	int a = e[k].f, b = e[k].t + e[k - 1].t - a;
	splay(b);
	nodes[b].fw = w;
	nodes[b].update();
}

int main(){
	int testNum;
	char cmd[10];
	scanf("%d", &testNum);
	while(testNum--){
		scanf("%d", &n);
		int a, b, c;
		for(int i = 1; i < n; ++i){
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
			addEdge(b, a, c);
		}
		bfsInit();
		scanf("%s", cmd);
		while(cmd[0] != 'D'){
			if(cmd[0] == 'Q'){
				scanf("%d%d", &a, &b);
				printf("%d\n", query(a, b));
			}
			else{
				scanf("%d%d", &a, &b);
				change(a * 2, b);
			}
			scanf("%s", cmd);
		}
	}
	return 0;
}
