//HDU - 1241 
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
using namespace std;
char a[105][105];
int nextx[8] = {0, 0, -1, 1, -1, 1, -1, 1}, nexty[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int sum = 0, n, m;
void dfs(int x, int y)
{
    if ((x < 0 || x >= n) || (y < 0 || y >= m))
        return;
    if (a[y][x] != '@')
        return;
    a[y][x] = '*';
    for (int i = 0; i < 8; ++i)
        dfs(x + nextx[i], y + nexty[i]);
}
int main()
{
    while (cin >> m >> n && n != 0 && m != 0)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; ++i)
            cin >> a[i];
        int sum = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (a[i][j] == '@')
                {
                    dfs(j, i);
                    ++sum;
                }
        }
        cout << sum << endl;
    }
    return 0;
}
