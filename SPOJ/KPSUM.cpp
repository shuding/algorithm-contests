#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
 
typedef long long Int64;
 
const int MaxLog10N = 16;
 
Int64 f[MaxLog10N + 1][10];
 
inline void strangeInit()
{
	for (int j = 0; j < 10; j++)
		f[1][j] = j;
	Int64 t = 10ll;
	for (int i = 2; i <= MaxLog10N; i++)
	{
		if (i % 2 == 1)
			fill(f[i], f[i] + 10, 5ll * t / 10ll);
		else
		{
			Int64 v = 45 * t / 10;
			f[i][0] = 0;
			for (int j = 1; j < 10; j++)
				f[i][j] = -j * t + v;
		}
		t *= 10ll;
	}
	
	for (int j = 1; j < 10; j++)
		if (j % 2 == 1)
			f[1][j] = f[1][j] + f[1][j - 1];
		else
			f[1][j] = -f[1][j] + f[1][j - 1];
	for (int i = 2; i <= MaxLog10N; i++)
	{
		f[i][0] = f[i - 1][9];
		for (int j = 1; j < 10; j++)
			f[i][j] += f[i][j - 1];
	}
}
 
inline Int64 strangeCalc(const Int64 &n)
{
	int a[MaxLog10N + 1];
	int l = 0;
	Int64 t = n;
	while (t > 0)
		a[++l] = t % 10, t /= 10ll;
	
	Int64 res = 0ll;
	
	if (l > 1)
		res += f[l][a[l] - 1];
	
	if (l % 2 == 0)
	{
		Int64 tenI = 10ll;
		for (int i = 2; i < l; i++)
		{
			if (i % 2 == 0 && a[i] > 0)
				res += 45 * a[i] * tenI / 10ll;
			for (int j = 1; j < a[i]; j++)
				if (i % 2 == 0)
					res -= j * tenI;
				else
					res += j * tenI;
			tenI *= 10ll;
		}
		
		int p = -1;
		for (int i = 2; i <= l; i++)
		{
			Int64 temp = 0;
			for (int j = i - 1; j > 1; j--)
				temp = temp * 10ll + a[j];
			temp *= 10ll;
			
			if (a[i] > 0)
				res += p * temp * a[i];
			p *= -1;
		}
	}
	else
	{
		Int64 t = 1ll;
		for (int i = 2; i < l; i++)
		{
			if (a[i] > 0)
				res += a[i] * 5 * t;
			t *= 10ll;
		}
	}
	
	for (int ai = 0; ai <= a[1]; ai++)
	{
		int clone = a[1];
		a[1] = ai;
		
		int p = l % 2 == 1 && a[1] % 2 == 1 ? 1 : -1;
		for (int i = l; i >= 1; i--)
			res += a[i] * p, p *= -1;
		a[1] = clone;
	}
 
	return res;
}
 
int main()
{
 
	Int64 n;
 
	strangeInit();
 
	while (cin >> n, n != 0)
		cout << strangeCalc(n) << endl;
 
	return 0;
}