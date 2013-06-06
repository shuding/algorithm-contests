#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int n, m, x, y, yu, yd, xl, xr, xu[5000], xd[5000], num[5001], l, r, mid;
bool cmp(int x, int y, int n)
{
	return x * yu + y * xd[n] + xu[n] * yd - x * yd - y * xu[n] - yu * xd[n] < 0;
}
int main()
{
	while(scanf("%d%d%d%d%d%d", &n, &m, &xl, &yu, &xr, &yd) == 6)
	{
		rep(i, n)
			scanf("%d%d", &xu[i], &xd[i]);
		xu[n] = xr;
		xd[n] = xr;
		n++;
		memset(num, 0, sizeof(num));
		rep(i, m)
		{
			scanf("%d%d", &x, &y);
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
		rep(i, n)
			printf("%d: %d\n", i, num[i]);
		printf("\n");
	}
	return 0;
}
