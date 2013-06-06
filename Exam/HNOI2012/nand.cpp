#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#define MAXN 4200000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k;
long long l, r, a[MAXN];
long long re, tot(0);
bool t[MAXN];
set<long long> s;
deque<long long> que;

long long nand(const long long &a, const long long &b){
	return a & b & re ^ re;
}

void bfs1(){
	int P, Q;
	while(!que.empty()){
		P = que.back();
		rep(i, n){
			Q = nand(P, a[i]);
			if(!t[Q]){
				que.push_front(Q);
				t[Q] = 1;
				a[++n] = Q;
			}
		}
		if(P >= l && P <= r) ++tot;
		que.pop_back();
	}
}

void bfs2(){
	int P, Q;
	while(!que.empty()){
		P = que.back();
		rep(i, n){
			Q = nand(P, a[i]);
			if(!s.count(Q)){
				que.push_front(Q);
				s.insert(Q);
				a[++n] = Q;
			}
		}
		if(P >= l && P <= r) ++tot;
		que.pop_back();
	}
}
 
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> k >> l >> r;
	re = (1ll << k) - 1;
	if(l > re){
		cout << 0 << endl;
		return 0;
	}
	rep(i, n){
		cin >> a[i];
		que.push_front(a[i]);
	}
	if(k <= 22)
		rep(i, n) t[a[i]] = 1;
	else
		rep(i, n) s.insert(a[i]);
	if(k <= 22)
		bfs1();
	else
		bfs2();
	cout << tot << endl;
	return 0;
}
