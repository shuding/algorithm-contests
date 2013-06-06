#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 30010
using namespace std;
 
int n, q;
int _f[MAXN];
 
struct disjointSet{
	void init(){
		for(int i = 1; i <= n; ++i)
			_f[i] = i;
	}
	int father(int i){
		return _f[i] == i ? i : _f[i] = father(_f[i]);
	}
	bool connected(int i, int j){
		return father(i) == father(j);
	}
	void connect(int i, int j){
		_f[father(i)] = father(j);
	}
} set;
 
struct node{
	int c[2], f, w, sum;
} nodes[MAXN];
 
void update(int n){
	nodes[n].sum = nodes[n].w;
	if(nodes[n].c[0]) nodes[n].sum += nodes[nodes[n].c[0]].sum;
	if(nodes[n].c[1]) nodes[n].sum += nodes[nodes[n].c[1]].sum;
}
 
void rotate(int n, bool d){
	int p = nodes[n].f, q = nodes[p].f;
	nodes[nodes[p].c[d] = nodes[n].c[!d]].f = p;
	nodes[nodes[n].c[!d] = p].f = n;
	nodes[n].f = q;
	if(q && (nodes[q].c[0] == p || nodes[q].c[1] == p))
		nodes[q].c[nodes[q].c[1] == p] = n;
	update(p);
}
 
void splay(int n){
	int p, q; bool d;
	while(nodes[n].f && (nodes[nodes[n].f].c[0] == n || nodes[nodes[n].f].c[1] == n)){
		p = nodes[n].f; q = nodes[p].f;
		d = nodes[p].c[1] == n;
		if(q && (nodes[q].c[0] == p || nodes[q].c[1] == p)){
			if(d == (nodes[q].c[1] == p))
				rotate(p, d), rotate(n, d);
			else
				rotate(n, d), rotate(n, !d);
		}
		else
			rotate(n, d);
	}
	update(n);
}
 
int access(int n){
	int v = 0;
	for(; n; n = nodes[n].f){
		splay(n);
		nodes[n].c[1] = v;
		update(v = n);
	}
	return v;
}
 
void modify(int n, int x){
	splay(n);
	nodes[n].w = x;
	update(n);
}
 
int query(int a, int b){
	access(a);
	int lca = access(b), ret = nodes[lca].w;
	if(lca != b)
		ret += nodes[nodes[lca].c[1]].sum;
	if(a != lca){
		splay(a);
		ret += nodes[a].sum;
	}
	return ret;
}
 
void evert(int n){
	if(!n) return;
	swap(nodes[n].c[0], nodes[n].c[1]);
	evert(nodes[n].c[0]);
	evert(nodes[n].c[1]);
}
 
void connect(int a, int b){
	access(a);
	splay(a);
	evert(a);
	nodes[a].f = b;
	update(a);
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &nodes[i].w);
		nodes[i].sum = nodes[i].w;
	}
	scanf("%d", &q);
	char cmd[10];
	int a, b;
	set.init();
	while(q--){
		scanf("%s%d%d", cmd, &a, &b);
		switch(cmd[0]){
			case 'b':
				if(!set.connected(a, b)){
					puts("yes");
					set.connect(a, b);
					connect(a, b);
				}
				else
					puts("no");
				break;
			case 'p':
				modify(a, b);
				break;
			case 'e':
				if(!set.connected(a, b))
					puts("impossible");
				else
					printf("%d\n", query(a, b));
				break;
		}
	}
	return 0;
}