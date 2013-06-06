#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;

struct point{
	long long x, y;
	bool operator < (const point &p) const{
		return x < p.x;
	}
} p[400010];

int n, tot = 0, c[400010];
long long ans = 0;
stack<int> q;

long long dis(int i, int j){
	return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
}

long long det(int x, int y, int z){
	return p[x].x * p[y].y + p[x].y * p[z].x + p[y].x * p[z].y - p[y].y * p[z].x - p[x].x * p[z].y - p[x].y * p[y].x;
}

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	sort(p + 1, p + 1 + n);
	q.push(1);
	for(int i = 2; i <= n; i++){
		while(q.size() >= 2){
			int j = q.top();
			q.pop();
			if(det(q.top(), j, i) < 0){
				q.push(j);
				break;
			}
		}
		q.push(i);
	}
	while(!q.empty()){
		c[++tot] = q.top();
		q.pop();
	}
	q.push(n);
	for(int i = n - 1; i >= 1; i--){
		while(q.size() >= 2){
			int j = q.top();
			q.pop();
			if(det(q.top(), j, i) < 0){
				q.push(j);
				break;
			}
		}
		q.push(i);
	}
	while(!q.empty()){
		c[++tot] = q.top();
		q.pop();
	}
	int j = 2;
	rep(i, tot){/*
		while(j <= tot && dis(c[i], c[j]) < dis(c[i], c[j + 1]))
			j++;
		ans = max(ans, dis(c[i], c[j]));
		*/
		while(abs(det(c[i], c[i % tot + 1], c[j])) < abs(det(c[i], c[i % tot + 1], c[j % tot + 1])))
			j = j % tot + 1;
		ans = max(ans, dis(c[i], c[j]));
	}
	printf("%lld\n", ans);
	return 0;
}
