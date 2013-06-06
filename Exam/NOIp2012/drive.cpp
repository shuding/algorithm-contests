/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : NOIp_2012_Day1_Drive_HandworkStack.cpp
*	Creation Time : 2013/01/14 21:58:15
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#define MAXN 100000
#define MAXM 100000
using namespace std;

struct query{
	int x, num, a, b;
	query(){}
	query(int x0, int n0): x(x0), num(n0){}
};

vector<query> q[MAXN * 10 + 10];
int n, m, x0, s, x, h[MAXN + 10];
vector<int> pre1[MAXN + 10], pre2[MAXN + 10];
set<pair<int, int> > hSet;
pair<int, int> nearest[5];

void init(){
	set<pair<int, int> >::iterator it;
	int num;
	for(int i = n; i; --i){
		it = hSet.insert(make_pair(h[i], i)).first;
		num = 0;
		it++;
		if(it != hSet.end()){
			nearest[++num] = *it;
			it++;
			if(it != hSet.end())
				nearest[++num] = *it;
			it--;
		}
		it--;
		if(it != hSet.begin()){
			it--;
			nearest[++num] = *it;
			if(it != hSet.begin()){
				it--;
				nearest[++num] = *it;
				it++;
			}
			it++;
		}
		for(int j = 1; j < num; ++j)
			for(int k = j + 1; k <= num; ++k){
				if(abs(nearest[j].first - h[i]) > abs(nearest[k].first - h[i]))
					swap(nearest[j], nearest[k]);
				else if(abs(nearest[j].first - h[i]) == abs(nearest[k].first - h[i]) &&
						nearest[j].first > nearest[k].first)
					swap(nearest[j], nearest[k]);
			}
		if(num > 0)
			pre1[nearest[1].second].push_back(i);
		if(num > 1)
			pre2[nearest[2].second].push_back(i);
	}
}

int top;
long long disN[MAXN + 10], dis[MAXN + 10];
bool vst[MAXN + 10][2];

struct stack{
	int v, flag;
	bool calc;
	vector<int>::iterator pre;
} st[MAXN + 10];
int sTop;

void dfs(int v, int flag){
	sTop = top = 1;
	st[sTop].v = v;
	st[sTop].flag = flag;
	st[sTop].pre = flag ? pre2[v].begin() : pre1[v].begin();
	st[sTop].calc = 0;
	while(sTop){
		vst[st[sTop].v][st[sTop].flag] = 1;
		if(!st[sTop].calc && !st[sTop].flag){
			st[sTop].calc = 1;
			int l, r, m;
			for(vector<query>::iterator it = q[st[sTop].v].begin(); it != q[st[sTop].v].end(); ++it){
				l = 1; r = top;
				while(l + 1 < r){
					m = (l + r) >> 1;
					if(dis[top] - dis[m] > it->x)
						l = m;
					else
						r = m;
				}
				if(dis[top] - dis[l] > it->x)
					m = r;
				else 
					m = l;
				it->b = disN[top] - disN[m];
				it->a = dis[top] - dis[m] - it->b;
			}
		}
		if(!st[sTop].flag){
			if(st[sTop].pre != pre1[st[sTop].v].end()){
				disN[top + 1] = disN[top] + abs(h[*st[sTop].pre] - h[st[sTop].v]);
				dis[top + 1] = dis[top] + abs(h[*st[sTop].pre] - h[st[sTop].v]);
				st[sTop + 1].v = *st[sTop].pre;
				st[sTop + 1].flag = !st[sTop].flag;
				st[sTop + 1].pre = pre2[*st[sTop].pre].begin();
				st[sTop + 1].calc = 0;
				++st[sTop].pre;
				++sTop;
				++top;
			}
			else{
				--top;
				--sTop;
			}
		}
		else
			if(st[sTop].pre != pre2[st[sTop].v].end()){
				disN[top + 1] = disN[top];
				dis[top + 1] = dis[top] + abs(h[*st[sTop].pre] - h[st[sTop].v]);
				st[sTop + 1].v = *st[sTop].pre;
				st[sTop + 1].flag = !st[sTop].flag;
				st[sTop + 1].pre = pre1[*st[sTop].pre].begin();
				st[sTop + 1].calc = 0;
				++st[sTop].pre;
				++sTop;
				++top;
			}
			else{
				--top;
				--sTop;
			}
	}
}

pair<int, int> ans[MAXM + 10];
int city;
long long rA = 1000000000, rB = 0;

void solve(){
	for(int i = n; i; --i){
		if(!vst[i][0])
			dfs(i, 0);
		if(!vst[i][1])
			dfs(i, 1);
	}
	for(int i = 1; i <= n; ++i)
		for(vector<query>::iterator it = q[i].begin(); it != q[i].end(); ++it)
			if(it->num == 0){
				if(it->b == 0){
					if(rB == 0 && h[i] > h[city])
						city = i;
				}
				else{
					if(it->a * rB < it->b * rA){
						rA = it->a;
						rB = it->b;
						city = i;
					}
					else if(it->a * rB == it->b * rA && h[i] > h[city])
						city = i;
				}
			}
			else
				ans[it->num] = make_pair(it->a, it->b);
	printf("%d\n", city);
	for(int i = 1; i <= m; ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
}

int main(){
	freopen("drive.in", "r", stdin);
	freopen("drive.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	scanf("%d", &x0);
	for(int i = 1; i <= n; ++i)
		q[i].push_back(query(x0, 0));
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &s, &x);
		q[s].push_back(query(x, i));
	}
	init();
	solve();
	return 0;
}
