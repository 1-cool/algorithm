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
int a[10000005];
int main()
{
    memset(a, 0, sizeof(a));
    for (int k = 2; k <= 10000000; ++k)
    {
        if (a[k] == 1)
            continue;
        for (int i = k+k; i <= 10000000; i += k)
            a[i] = 1;
    }
    int n ;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 2; i <= n; ++i)
            if (a[i] == 0)
                ++cnt;
        cout << cnt << endl;
    }
    return 0;
}
