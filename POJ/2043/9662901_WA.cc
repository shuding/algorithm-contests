#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define rep(i, n, m) for(int i = n; i <= m; i++)
#define rep0(i, n) for(int i = 0; i < n; i++) 
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;
const int inf = ~0U>>1;
struct dou_coor
{
    double y1, y2;
};
int n, x[100], y[100], tot, minx, maxx;
vector<dou_coor> cr;

bool compare(dou_coor a, dou_coor b)
{
    return (a.y1 > b.y1)||((a.y1 == b.y1)&&(a.y2 >= b.y2));
}

bool is_cross(int a, int b, int xl)
{
    if(x[a] > x[b])
        swap(a, b);
    return x[a] <= xl && x[b] > xl;
}
//判断是否相交

double get_coor(int a, int b, int xl)
{
    if(x[a] > x[b])
        swap(a, b);
    return double((y[b] - y[a]) * (xl - x[a])) / double(x[b] - x[a]) + y[a];
}
//求交点纵坐标 

int main()
{
    scanf("%d", &n);
    while(n)
    {
        minx = inf;
        maxx = -inf;
        rep0(i, n)
        {
            scanf("%d%d", &x[i], &y[i]);
            minx = min(minx, x[i]);
            maxx = max(maxx, x[i]);
        }
        tot = 0;
        rep(i, minx, maxx)
        {
            cr.clear();
            rep0(j, n)
                if(is_cross(j, (j + 1) % n, i))
                {
                    dou_coor p = {get_coor(j, (j + 1) % n, i), get_coor(j, (j + 1) % n, i + 1)}; 
                    cr.push_back(p);
                }
            sort(cr.begin(), cr.end(), compare);
            int tt = 0, maxy = inf;
            while(tt < cr.size())
            {
                int a = floor(max(cr[tt].y1, cr[tt].y2) + 0.999), b = floor(min(cr[tt + 1].y1, cr[tt + 1].y2));
                tot += max(min(maxy, a) - b, 0);
                maxy = min(maxy, b);
                tt += 2;
            }
        }
        printf("%d\n", tot);
        scanf("%d", &n);
    }
    return 0;
}
