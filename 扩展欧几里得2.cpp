/**********************************HDU - 1211********************************/
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
void exgcd(int a, int b, int &x, int &y)
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
int fastpow(int a, int b, int c)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return ans % c;
}
int main()
{
    int p, q, e, l;
    while (cin >> p >> q >> e >> l)
    {
        int n = p * q, fn = (p - 1) * (q - 1);
        int x, y;
        exgcd(e, fn, x, y);
        int d = (x % fn + fn) % fn;
        string ch = "";
        while (l--)
        {
            int text;
            cin >> text;
            text = fastpow(text, d, n);
            ch += text;
            //printf("%c", text);
        }
        cout << ch << endl;
    }
    return 0;
}
