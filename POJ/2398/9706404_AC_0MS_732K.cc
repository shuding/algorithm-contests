#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll n, m, x, y, yu, yd, xl, xr, xu[1001], xd[1001], num[1001], l, r, mid, SORT[1001];
bool cmp(ll x, ll y, ll n)
{
	return x * yu + y * xd[n] + xu[n] * yd - x * yd - y * xu[n] - yu * xd[n] < 0;
}
int main()
{
	while(scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &xl, &yu, &xr, &yd) == 6)
	{
		rep(i, n)
			scanf("%lld%lld", &xu[i], &xd[i]);
		xu[n] = xr;
		xd[n] = xr;
		n++;
		sort(xu, xu + n);
		sort(xd, xd + n);
		memset(num, 0, sizeof(num));
		memset(SORT, 0, sizeof(SORT));
		rep(i, m)
		{
			scanf("%lld%lld", &x, &y);
			l = 0; r = n - 1;
			while(l <= r)
			{
				mid = (l + r) / 2;
				if(cmp(x, y, mid))
					r = mid - 1;
				else
					l = mid + 1;
			}
			num[l]++;
		}
		printf("Box\n");
		rep(i, n)
			SORT[num[i]]++;
		rep(i, m)
			if(SORT[i + 1])
				printf("%d: %lld\n", i + 1, SORT[i + 1]);
	}
	return 0;
}
