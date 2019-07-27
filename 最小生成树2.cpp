/******************************POJ - 1287*****************************/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <sstream>
using namespace std;
int a[30005];
int find(int x)
{
    return a[x] == x ? x : a[x] = find(a[x]);
}
struct node
{
    int from, to, w;
} x[30006];
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int main()
{
    int p, r;
    while (cin >> p && p != 0)
    {
        for (int i = 0; i < 30005; ++i)
            a[i] = i;
        cin >> r;
        for (int i = 1; i <= r; ++i)
        {
            cin >> x[i].from >> x[i].to >> x[i].w;
        }
        sort(x+1, x + r+1, cmp);
        int sum = 0, cnt = 0;
        for (int i = 1; i <= r; ++i)
        {
            int root1 = find(x[i].from), root2 = find(x[i].to);
            if (root1 != root2)
            {
                ++cnt;
                sum += x[i].w;
                a[root1] = root2;
            }
            if (cnt == p - 1)
                break;
        }
        cout << sum << endl;
    }
    return 0;
}
