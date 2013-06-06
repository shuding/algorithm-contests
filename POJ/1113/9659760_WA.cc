/*
*Title          凸包模板 
*Algorithm      Graham算法 
*Complexity     sort~O(nlogn) + algo~O(n) = O(nlogn)
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;
struct point
{
    int x, y;
} p[5005];
vector<point> vp;
stack<point> sp;
int n, l;
double tot = 0;
point p1;
bool compare(point a, point b)
{
    return a.x < b.x;
}
bool turn(point a, point b, point c)
{
    return a.x * b.y + a.y * c.x + b.x * c.y - b.y * c.x - c.y * a.x - a.y * b.x > 0;
}
double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
main()
{
    scanf("%d%d", &n, &l);
    rep(i, n)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        vp.push_back(p[i]);
    }
    sort(vp.begin(), vp.end(), compare);
    rep(i ,n)
        p[i] = vp[i];
    sp.push(p[0]);
    rep(i, n - 1)
    {
        while(sp.size() >= 2)
        {
            p1 = sp.top();
            sp.pop();
            if(turn(sp.top(), p1, p[i + 1]))
            {
                sp.push(p1);
                break;
            }               
        }
        sp.push(p[i + 1]);
    }
    while(!sp.empty())
    {
        p1 = sp.top();
        sp.pop();
        if(!sp.empty())
            tot += dis(p1, sp.top());
    }
    sp.push(p[0]);
    rep(i, n - 1)
    {
        while(sp.size() >= 2)
        {
            p1 = sp.top();
            sp.pop();
            if(!turn(sp.top(), p1, p[i + 1]))
            {
                sp.push(p1);
                break;
            }               
        }
        sp.push(p[i + 1]);
    }
    while(!sp.empty())
    {
        p1 = sp.top();
        sp.pop();
        if(!sp.empty())
            tot += dis(p1, sp.top());
    }
    tot += 3.141592653 * 2 * l;
    printf("%d\n", int(tot + 0.5));
    return 0;
}
