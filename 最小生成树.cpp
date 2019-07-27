/*********************************HDU - 1213***********************************/
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
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 30005; ++i)
            a[i] = i;
        int n, m;
        cin >> n >> m;
        while (m--)
        {
            int t1, t2;
            cin >> t1 >> t2;
            a[find(t1)] = find(t2);
        }
        for(int i=1;i<=n;++i)
        a[i]=find(a[i]);
        sort(a+1, a + n+1);
        int cnt = 1;
        for (int i = 2; i <= n; ++i)
            if (a[i] != a[i - 1])
                ++cnt;
        cout << cnt<<endl;
    }
    return 0;
}
