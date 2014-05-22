#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#define MAXN 40010
#define S 37
using namespace std;

int n, m, tmp, num[MAXN], a[MAXN], ans;
int l[S], times[S][S][MAXN], plural[S][S], sn, sl;
int bel[MAXN], vst[MAXN], vt[MAXN];
map<int, int> hash;

void init(){
	int st = 1;
	sl = int(pow(n, 2.0 / 3.0));
	while(st <= n){
		l[++sn] = st;
		st += sl;
	}
	l[sn + 1] = n + 1;
	for(int i = 1; i <= sn; ++i)
		for(int j = i; j <= sn; ++j){
			for(int k = 1; k <= n; ++k)
				times[i][j][k] = times[i][j - 1][k];
				plural[i][j] = plural[i][j - 1];
			for(int k = l[j]; k < l[j + 1]; ++k){
				times[i][j][a[k]]++;
				if(times[i][j][a[k]] > times[i][j][plural[i][j]] ||
					(times[i][j][a[k]] == times[i][j][plural[i][j]] && num[a[k]] < num[plural[i][j]]))
					plural[i][j] = a[k];
			}
		}
	st = 1;
	for(int i = 1; i <= n; ++i){
		if(i >= l[st + 1])
			st++;
		bel[i] = st;
	}
	bel[n + 1] = sn + 1;
}

int query(int left, int right){
	if(bel[left] == bel[right]){
		int ret = 0;
		for(int i = left; i <= right; ++i){
			if(vst[a[i]] == m)
				vt[a[i]]++;
			else
				vst[a[i]] = m, vt[a[i]] = 1;
			if(vt[a[i]] > vt[ret] || (vt[a[i]] == vt[ret] && num[a[i]] < num[ret]))
				ret = a[i];
		}
		return num[ret];
	}
	int ret = 0, *tmp = times[bel[left] + 1][bel[right] - 1];
	for(int i = left; bel[i] == bel[left]; ++i){
		tmp[a[i]]++;
		if(tmp[a[i]] > tmp[ret] || (tmp[a[i]] == tmp[ret] && num[a[i]] < num[ret]))
			ret = a[i];
	}
	for(int i = right; bel[i] == bel[right]; --i){
		tmp[a[i]]++;
		if(tmp[a[i]] > tmp[ret] || (tmp[a[i]] == tmp[ret] && num[a[i]] < num[ret]))
			ret = a[i];
	}
	if(tmp[plural[bel[left] + 1][bel[right] - 1]] > tmp[ret]
		|| (tmp[plural[bel[left] + 1][bel[right] - 1]] == tmp[ret]
		&& num[plural[bel[left] + 1][bel[right] - 1]] < num[ret]))
		ret = plural[bel[left] + 1][bel[right] - 1];
	for(int i = left; bel[i] == bel[left]; ++i)
		tmp[a[i]]--;
	for(int i = right; bel[i] == bel[right]; --i)
		tmp[a[i]]--;
	return num[ret];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tmp);
		int &t = hash[tmp];
		num[a[i] = t ? t : (t = i)] = tmp;
	}
	init();
	int left, right;
	while(m--){
		scanf("%d%d", &left, &right);
		left = (left + ans - 1) % n + 1;
		right = (right + ans - 1) % n + 1;
		if(left > right) swap(left, right);
		printf("%d\n", ans = query(left, right));
	}
	return 0;
}
