/*********************HDU-1312*******************************/
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
char a[25][25];
//int nextx[8] = {0, 0, -1, 1, -1, 1, -1, 1}, nexty[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int nextx[4] = {0, 0, -1, 1}, nexty[4] = {-1, 1, 0, 0};
int sum = 1, w, h;
void dfs(int x, int y)
{
    if ((x < 0 || x >= w) || (y < 0 || y >= h))
        return;
    if (a[y][x] == '#')
        return;
    ++sum;
    a[y][x] = '#';
    for (int i = 0; i < 4; ++i)
        dfs(x + nextx[i], y + nexty[i]);
}
int main()
{
    while (cin >> w >> h && w != 0 && h != 0)
    {
        sum = 1;
        memset(a, 0, sizeof(a));
        int x, y;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                    y = i, x = j;
            }
        dfs(x, y);
        cout << sum-1 << endl;
    }
    return 0;
}
