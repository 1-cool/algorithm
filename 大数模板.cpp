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
struct biginteger
{
    static const int base = 100000000;
    static const int width = 8;
    vector<int> s;
    biginteger(long long num = 0) { *this = num; }
    biginteger operator=(long long num)
    {
        s.clear();
        do
        {
            s.push_back(num % base);
            num /= base;
        } while (num > 0);
        return *this;
    }
    biginteger operator=(const string &str)
    {
        s.clear();
        int x, len = (str.length() - 1) / width + 1;
        for (int i = 0; i < len; ++i)
        {
            int end = str.length() - i * width;
            int start = max(0, end - width);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    biginteger operator+(const biginteger &b) const
    {
        biginteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % base);
            g = x / base;
        }
        return c;
    }
};
ostream &operator<<(ostream &out, const biginteger &x)
{
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++)
            out << buf[j];
    }
    return out;
}
istream &operator>>(istream &in, biginteger &x)
{
    string s;
    if (!(in >> s))
        return in;
    x = s;
    return in;
}

int main()
{
    biginteger a, b, c;
    cin >> a >> b >> c;
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
