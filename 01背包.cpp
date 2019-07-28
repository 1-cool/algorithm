/************************HDU-2602****************************/
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
int p[10005], ti[10005], r[10005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(r, 0, sizeof(r));
        int n, v;
        cin >> n >> v;
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        for (int i = 0; i < n; ++i)
            cin >> ti[i];
        for (int i = 0; i < n; ++i)
            for (int j = v; j >=ti[i]; --j)
                r[j] = max(r[j], r[j - ti[i]] + p[i]);
        cout << r[v] << endl;
    }
    return 0;
}
