/**************************HDU - 1576********************************/
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
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x, y, b;
        cin >> n >> b;
        exgcd(b, 9973, x, y);
        x *= n;
        x = (x % 9973 + 9973) % 9973;
        cout << x << endl;
    }
    return 0;
}
