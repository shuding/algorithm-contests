/*
* Copyright (C) 2012 All rights reserved.
* File name:  GSS5.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.18
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define MAXN 10000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
 
int pos, sum[MAXN + 10];
 
struct node{
        int l, r, c[2], sum, lmax, rmax, mmax;
        void init(int L, int R){
                l = L; r = R;
                c[0] = c[1] = sum = lmax = rmax = mmax = 0;
        }
} t[MAXN * 2 + 10];
 
void update(int n){
        t[n].sum = t[t[n].c[0]].sum + t[t[n].c[1]].sum;
        t[n].mmax = max(t[t[n].c[0]].mmax, t[t[n].c[1]].mmax);
        int value = sum[(t[n].l + t[n].r) >> 1] - sum[((t[n].l + t[n].r) >> 1) - 1];
        if(value >= 0)
                t[n].mmax = max(t[n].mmax, t[t[n].c[0]].rmax + t[t[n].c[1]].lmax);
        else
                t[n].mmax = max(t[n].mmax, (t[t[n].c[0]].rmax > 0 ? t[t[n].c[0]].rmax : value) + t[t[n].c[1]].lmax);
        t[n].lmax = max(t[t[n].c[0]].lmax, t[t[n].c[0]].sum + t[t[n].c[1]].lmax);
        t[n].rmax = max(t[t[n].c[1]].rmax, t[t[n].c[1]].sum + t[t[n].c[0]].rmax);
}
 
int n, m, x1, y, x2, y2, tot;
 
void build(int n, int l, int r){
        t[n].init(l, r);
        if(l == r){
                scanf("%d", &t[n].sum);
                t[n].mmax = t[n].sum;
                t[n].lmax = t[n].rmax = max(0, t[n].sum);
                sum[pos + 1] = sum[pos] + t[n].sum;
                pos++;
                return;
        }
        int m = (t[n].l + t[n].r) >> 1;
        build(t[n].c[0] = ++tot, l, m);
        build(t[n].c[1] = ++tot, m + 1, r);
        update(n);
}
 
int querySum(int l, int r){
        if(l > r) return 0;
        return sum[r] - sum[l - 1];
}
 
int queryLeft(int n, int l, int r){
        if(l > r) return 0;
        if(l == t[n].l && r == t[n].r)
                return t[n].lmax;
        int m = (t[n].l + t[n].r) >> 1;
        if(r <= m) return queryLeft(t[n].c[0], l, r);
        if(l > m)  return queryLeft(t[n].c[1], l, r);
        return max(queryLeft(t[n].c[0], l, m), querySum(l, m) + queryLeft(t[n].c[1], m + 1, r));
}
 
int queryRight(int n, int l, int r){
        if(l > r) return 0;
        if(l == t[n].l && r == t[n].r)
                return t[n].rmax;
        int m = (t[n].l + t[n].r) >> 1;
        if(r <= m) return queryRight(t[n].c[0], l, r);
        if(l > m)  return queryRight(t[n].c[1], l, r);
        return max(queryRight(t[n].c[1], m + 1, r), querySum(m + 1, r) + queryRight(t[n].c[0], l, m));
}
 
int queryMid(int n, int l, int r){
        if(l > r) return 0;
        if(l == t[n].l && r == t[n].r)
                return t[n].mmax;
        int m = (t[n].l + t[n].r) >> 1;
        if(r <= m) return queryMid(t[n].c[0], l, r);
        if(l > m)  return queryMid(t[n].c[1], l, r);
        int tmp = max(queryMid(t[n].c[0], l, m), queryMid(t[n].c[1], m + 1, r));
        return max(tmp, queryRight(t[n].c[0], l, m - 1) + queryLeft(t[n].c[1], m + 1, r) + querySum(m, m));
}
 
int main(){
        int testNum;
        scanf("%d", &testNum);
        while(testNum--){
                scanf("%d", &n);
                tot = 1; pos = 0;
                build(1, 1, n);
                scanf("%d", &m);
                while(m--){
                        scanf("%d%d%d%d", &x1, &y, &x2, &y2);
                        if(y + 1 <= x2)
                                printf("%d\n", querySum(y, x2) + queryRight(1, x1, y - 1) + queryLeft(1, x2 + 1, y2));
                        else
                                printf("%d\n",
                                        max(max(queryRight(1, x1, x2 - 1) + queryLeft(1, x2 + 1, y2) + querySum(x2, x2),
                                        queryRight(1, x1, y - 1) + queryLeft(1, y + 1, y2) + querySum(y, y)),
                                        queryMid(1, x2, y)));
                }
        }
        return 0;
}
 