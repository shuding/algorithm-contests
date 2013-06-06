#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <limits>
using namespace std;
typedef long long ll;

int main() {
 setbuf(stdout, NULL);
 ll N;
 ll p;
 ll a;
 ll res;
 while (cin >> N) {
  res = N;
  for (ll i = 2; i * i <= N; i++) {
   if (N % i == 0) {
    p = i;
    a = 0;
    while (N % p == 0) {
     a++;
     N /= p;
    }
    res = res + res * a * (p - 1) / p;
   }
  }
  if (N != 1) {
   res = res * (2 * N - 1) / N;
  }
  cout << res << endl;
 }
 return 0;
}