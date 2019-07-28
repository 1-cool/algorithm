/**************************HDU-1171****************************/
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
int f[1000005], v[1000005], m[1000005];
int main()
{
    int n;
    while (cin >> n && n >= 0)
    {
        memset(f, 0, sizeof(f));
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i] >> m[i];
            sum += v[i] * m[i];
        }
        for (int i = 0; i < n; ++i)
            for (int j = sum / 2; j >= 0; --j)
                for (int k = 1; k <= m[i] && k * v[i] <= j; ++k)
                    f[j] = max(f[j], f[j - k * v[i]] + k * v[i]);
        printf("%d %d\n", sum - f[sum / 2], f[sum / 2]);
    }
    return 0;
}
