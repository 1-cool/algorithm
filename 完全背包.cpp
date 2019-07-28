/****************************HDU-1114****************************/
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
int p[10005], w[10005], r[10005];
int main()
{
    int t, e, f, n;
    cin >> t;
    while (t--)
    {
        memset(r, 0x3f, sizeof(r));
        r[0]=0;
        cin >> e >> f >> n;
        int c = f - e;
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> w[i];
        for (int i = 0; i < n; ++i)
            for (int j = w[i]; j <= c; ++j)
            {
                r[j] = min(r[j], r[j - w[i]] + p[i]);
                
            }
        if (r[c] != 0x3f3f3f3f)
            cout << "The minimum amount of money in the piggy-bank is " << r[c] << "." << endl;
        else
            cout << "This is impossible." << endl;
    }
    return 0;
}
