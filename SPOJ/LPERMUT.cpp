#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 100010
using namespace std;
 
int n, pos, ans, a[MAXN], times[MAXN], next;
long long s[MAXN * 2];
deque<pair<int, int> > deq;
 
void solve(){
	next = n + 1;
	pos = n;
	deq.clear();
	memset(s, 0, sizeof s);
	memset(times, 0, sizeof times);
	for(int i = n; i; --i){
		times[a[i]]++;
		s[i] = s[i + 1] + a[i];
		if(a[i] == 1)
			next = i;
		while(!deq.empty() && a[i] >= deq.back().first)
			deq.pop_back();
		deq.push_back(make_pair(a[i], i));
		while(!deq.empty() && deq.front().second > next)
			deq.pop_front();
		if(times[a[i]] > 1){
			do{
				times[a[pos]]--;
				if(!deq.empty() && deq.front().second == pos)
					deq.pop_front();
				pos--;
			} while(times[a[i]] > 1);
		}
		if(!deq.empty() && pos >= next){
			long long tmp = deq.front().first;
			if(pos >= i + tmp - 1 && s[i] - s[i + tmp] == (tmp + 1) * tmp / 2)
				ans = max(ans, (int)tmp);
		}
	}
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	solve();
	for(int i = 1; i * 2 <= n; ++i)
		swap(a[i], a[n - i + 1]);
	solve();
	printf("%d\n", ans);
}