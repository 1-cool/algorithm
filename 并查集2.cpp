/*************************************POJ-2236**********************************/
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
int a[30005], s[30005];
int find(int x)
{
    return a[x] == x ? x : a[x] = find(a[x]);
}
struct node
{
    int x, y;
} p[1005];
int main()
{
    memset(s, 0, sizeof(s));
    for (int i = 0; i < 20005; ++i)
        a[i] = i;
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }
    char ch;

    while (cin >> ch)
    {
        if (ch == 'O')
        {
            int t;
            cin >> t;
            s[t] = 1;
            for (int i = 1; i <= n; ++i)
            {
                if (s[i] == 1)
                {
                    if (abs((p[t].x - p[i].x) * (p[t].x - p[i].x) + (p[t].y - p[i].y) * (p[t].y - p[i].y)) <= d * d)
                    {
                        int x = find(a[t]), y = find(a[i]);
                        if (x != y)
                            a[x] = y;
                    }
                }
            }
        }
        else
        {
            int t1,t2;
            cin >> t1>>t2;
            int x = find(a[t1]), y = find(a[t2]);
            if (x != y)
                cout << "FAIL" << endl;
            else
                cout << "SUCCESS" << endl;
        }
    }
    return 0;
}
