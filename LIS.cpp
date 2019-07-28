/****************************HDU-1257*************************/
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
int a[10005], ans[10005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > ans[j])
                ans[++j] = a[i];
            else
                ans[lower_bound(ans, ans + j, a[i]) - ans] = a[i];
        }
        cout << j << endl;
    }
    return 0;
}
