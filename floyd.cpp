/*****************************POJ - 2253*****************************/
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
int d[205][205];
struct d
{
    int x, y;
} x[205];

int main()
{
    int n, cnt = 1;
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; ++i)
            cin >> x[i].x >> x[i].y;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = (x[i].x - x[j].x) * (x[i].x - x[j].x) + (x[i].y - x[j].y) * (x[i].y - x[j].y);
        /**********************floyd核心算法**********************/
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        /*******************************************************/
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", cnt++, sqrt(d[0][1]));
    }
    return 0;
}
