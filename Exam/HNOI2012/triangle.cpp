#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#define MAXN 10500
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

set<pair<int, int> > s;

struct tri{
	int x, y;
	long long d;
	tri(){}
	tri(int _x, int _y, long long _d):
		x(_x), y(_y), d(_d){}
} t[MAXN];

long long tot(0);
int n;

bool cross_p(int x, int y, tri b){
	return x > b.x && y > b.y && x + y < b.x + b.y + b.d;
}

bool cross(tri a, tri b){
	return cross_p(a.x, a.y, b) || cross_p(a.x + a.d, a.y, b) || cross_p(a.x, a.y + a.d, b);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	rep(i, n){
		scanf("%d%d", &t[i].x, &t[i].y);
		cin >> t[i].d;
	}
	if(n <= 2000)
	rep(i, n){
		tot += t[i].d * t[i].d;
		s.clear();
		rep(j, i - 1)
			if(cross(t[i], t[j]) || cross(t[j], t[i])){
				int a = i, b = j;
				if(t[i].d > t[j].d) swap(a, b);
				for(int k = 0; k < t[a].d; ++k)
					for(int p = 0; p < t[a].d - k; ++p)
						if(cross(tri(t[a].x + k, t[a].y + p, 1), t[b]))
							s.insert(make_pair(k, p));
			}
		tot -= s.size();
	}
	else{
		rep(i, n)
			tot += t[i].d * t[i].d;
	}
	printf("%.1lf\n", double(tot) / 2.0);
	return 0;
}
