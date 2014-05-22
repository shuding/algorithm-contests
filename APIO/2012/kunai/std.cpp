#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
 
using namespace std;
 
struct segment {
        int x, l, r;
        segment(int _x = 0, int _l = 0, int _r = 0) : x(_x), l(_l), r(_r) {}
} seg1[100000], seg2[100000], seg3[100000];
 
struct event {
        int x1, y1, x2, y2, t;
        event(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _t = 0) :
                x1(_x1), y1(_y1), x2(_x2), y2(_y2), t(_t) {}
        bool operator < (const event &o) const {
                return t > o.t;
        }
};
 
map< int, set<int> > L1, L2, L3, L4, L5, L6, R1, R2, R3, R4, R5, R6;
int axisX[200002], axisY[100000], cover[100000], sum[100000];
map< pair<int, int>, int > D, T;
set< pair<int, int> > S;
priority_queue<event> pq;
 
int getL(int x, set<int> &L, set<int> &R) {
        set<int>::iterator p, q;
        p = L.lower_bound(x);
        if (p == L.begin()) return -1;
        p --;
        q = R.lower_bound(*p);
        if (*q != x) return -1; else return *p;
}
 
int getR(int x, set<int> &L, set<int> &R) {
        set<int>::iterator p, q;
        p = R.lower_bound(x);
        if (p == R.end()) return -1;
        q = L.lower_bound(*p);
        q --;
        if (*q != x) return -1; else return *p;
}
 
void deleteL(int x, set<int> &L, set<int> &R, int type, int flag) {
        int y = getR(x, L, R);
        L.erase(x);
        if (y != -1) {
                int t = getL(y, L, R);
                if (t != -1) {
                        if (type == 1) pq.push(event(flag, t, flag, y, y - t));
                        if (type == 2) pq.push(event(t, flag, y, flag, y - t));
                        if (type == 3 || type == 4) pq.push(event(t, t - flag, y, y - flag, (y - t) * 2));
                        if (type == 5 || type == 6) pq.push(event(t, flag - t, y, flag - y, (y - t) * 2));
                }
        }
}
 
void deleteR(int y, set<int> &L, set<int> &R, int type, int flag) {
        int x = getL(y, L, R);
        R.erase(y);
        if (x != -1) {
                int t = getR(x, L, R);
                if (t != -1) {
                        if (type == 1) pq.push(event(flag, x, flag, t, t - x));
                        if (type == 2) pq.push(event(x, flag, t, flag, t - x));
                        if (type == 3 || type == 4) pq.push(event(x, x - flag, t, t - flag, (t - x) * 2));
                        if (type == 5 || type == 6) pq.push(event(x, flag - x, t, flag - t, (t - x) * 2));
                }
        }
}
 
bool cmp1(const segment &a, const segment &b) {
        return a.x < b.x || a.x == b.x && a.l < b.l;
}
 
bool cmp2(const segment &a, const segment &b) {
        return a.l < b.l;
}
 
bool cmp3(const segment &a, const segment &b) {
        return a.r < b.r;
}
 
int main() {
        int n, w, h;
        scanf("%d%d%d", &w, &h, &n);
        for (int i = 0; i < n; i ++) {
                int x, y, d;
                scanf("%d%d%d", &y, &x, &d);
                D[make_pair(x, y)] = d;
                S.insert(make_pair(x, y));
                if (d == 0) {
                        T[make_pair(x, y)] = (w - y) * 2 + 1;
                        L1[x].insert(y);
                        L3[x-y].insert(x);
                        R6[x+y].insert(x);
                }
                if (d == 1) {
                        T[make_pair(x, y)] = x * 2 - 1;
                        R2[y].insert(x);
                        R3[x-y].insert(x);
                        R5[x+y].insert(x);
                }
                if (d == 2) {
                        T[make_pair(x, y)] = y * 2 - 1;
                        R1[x].insert(y);
                        R4[x-y].insert(x);
                        L5[x+y].insert(x);
                }
                if (d == 3) {
                        T[make_pair(x, y)] = (h - x) * 2 + 1;
                        L2[y].insert(x);
                        L4[x-y].insert(x);
                        L6[x+y].insert(x);
                }
        }
        
        map< int, set<int> >::iterator p;
        set<int>::iterator q;
        for (p = L1.begin(); p != L1.end(); p ++)
                for (q = p->second.begin(); q != p->second.end(); q ++) {
                        int t1 = *q, t2 = getR(t1, L1[p->first], R1[p->first]);
                        if (t2 != -1) pq.push(event(p->first, t1, p->first, t2, t2 - t1));
                }
        for (p = L2.begin(); p != L2.end(); p ++)
                for (q = p->second.begin(); q != p->second.end(); q ++) {
                        int t1 = *q, t2 = getR(t1, L2[p->first], R2[p->first]);
                        if (t2 != -1) pq.push(event(t1, p->first, t2, p->first, t2 - t1));
                }
        for (p = L3.begin(); p != L3.end(); p ++)
                for (q = p->second.begin(); q != p->second.end(); q ++) {
                        int t1 = *q, t2 = getR(t1, L3[p->first], R3[p->first]);
                        if (t2 != -1) pq.push(event(t1, t1 - p->first, t2, t2 - p->first, (t2 - t1) * 2));
                }
        for (p = L4.begin(); p != L4.end(); p ++)
                for (q = p->second.begin(); q != p->second.end(); q ++) {
                        int t1 = *q, t2 = getR(t1, L4[p->first], R4[p->first]);
                        if (t2 != -1) pq.push(event(t1, t1 - p->first, t2, t2 - p->first, (t2 - t1) * 2));
                }
        for (p = L5.begin(); p != L5.end(); p ++)
                for (q = p->second.begin(); q != p->second.end(); q ++) {
                        int t1 = *q, t2 = getR(t1, L5[p->first], R5[p->first]);
                        if (t2 != -1) pq.push(event(t1, p->first - t1, t2, p->first - t2, (t2 - t1) * 2));
                }
        for (p = L6.begin(); p != L6.end(); p ++)
                for (q = p->second.begin(); q != p->second.end(); q ++) {
                        int t1 = *q, t2 = getR(t1, L6[p->first], R6[p->first]);
                        if (t2 != -1) pq.push(event(t1, p->first - t1, t2, p->first - t2, (t2 - t1) * 2));
                }
 
		while(!pq.empty()){
			cout << pq.top().x1 << "," << pq.top().y1 << " " << pq.top().x2 << "," << pq.top().y2 << " " << pq.top().t << endl;
			pq.pop();
		}

		return 0;
}
 

