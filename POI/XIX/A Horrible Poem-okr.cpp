#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 500010
#define SEED 1331ll
using namespace std;

int n, q;
char s[MAXN];
bool inp[MAXN];
vector<pair<int, int> > prime[MAXN];
unsigned long long hash[MAXN], power[MAXN];

int main(){
	scanf("%d%s%d", &n, s, &q);
	for(int i = 2; i <= n; ++i)
		if(!inp[i])
			for(int j = i; j <= n; j += i){
				inp[j] = 1;
				int tmp = j, times = 0;
				while(tmp % i == 0){
					tmp /= i;
					times++;
				}
				prime[j].push_back(make_pair(i, times));
			}
	power[0] = 1;
	for(int i = 1; i <= n; ++i)
		power[i] = power[i - 1] * SEED,
		hash[i] = hash[i - 1] * SEED + s[i - 1];
	while(q--){
		int a, b, len, res = 1;
		scanf("%d%d", &a, &b);
		len = b - a + 1;
		for(vector<pair<int, int> >::iterator it = prime[len].begin();
				it != prime[len].end(); ++it){
			int l = 1, hl;
			for(int i = 1; i <= it->second; ++i) l *= it->first;
			for(int i = 1; i <= it->second; ++i){
				hl = len / l;
				unsigned long long h1 = hash[b - hl] - hash[a - 1] * power[b - hl - a + 1];
				unsigned long long h2 = hash[b] - hash[a + hl - 1] * power[b - hl - a + 1];
				if(h1 == h2){
					res *= l;
					break;
				}
				l /= it->first;
			}
		}
		printf("%d\n", len / res);
	}
	return 0;
}

