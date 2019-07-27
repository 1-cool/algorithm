/***********************************POJ - 1611***************************************/
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
int main()
{
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        for (int i = 0; i < 30005; ++i)
            a[i] = i;
        while (m--)
        {
            int k, temp;
            cin >> k >> temp;
            --k;
            while (k--)
            {
                int t;
                cin >> t;
                a[find(t)] = find(temp);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (find(i) == find(0))
                ++cnt;
        cout << cnt << endl;
    }
    return 0;
}
