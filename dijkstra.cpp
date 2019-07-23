//POJ - 2387 
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
int w[2005][2005], vis[2005], d[2005];
int main()
{
    int t, n;
    cin >> t >> n;
    memset(w, 0x3f, sizeof(w));
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 0; i < t; ++i)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        // cin >> w[t1][t2];
        if (w[t1][t2] > t3)
            w[t1][t2] = w[t2][t1] = t3;
    }
    /**********Dijkstra算法核心语句**********/
    for (int i = 0; i < t; ++i)
    {
        int x, m = 0x3f3f3f3f;
        for (int y = 1; y <= n; ++y)
            if (!vis[y] && d[y] < m)
                m = d[x = y];
        vis[x] = 1;
        for (int y = 1; y <= n; ++y)
            d[y] = min(d[y], d[x] + w[x][y]);
    }
    /**************************************/
    cout << d[n] << endl;
    return 0;
}
