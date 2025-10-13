#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define YES puts("YES")
#define NO puts("NO")
#define in(x) cin >> x
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define ot(x) cout << x << " ";
#define out(x) cout << x << endl;
#define nl cout << endl;
#define vi(n) vector<int> v(n);
#define vi1(n) vector<int> v1(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v1(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
int main()
{

    tt()
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a <= b) // if col beshi
        {
            if (b < (y / 2))
            {
                y = b;
            }
            else
            {
                y = y - b;
            }
        }
        else
        {
            if (a < (x / 2))
            {
                x = a;
            }
            else
            {
                x = x - a;
            }
        }
        ll count = 1;
        while (true)
        {
            if (x == 1 && y == 1)
            {
                break;
            }
            if (x > y)
            {
                x = x / 2;
            }
            else
            {
                y = y / 2;
            }
            count++;
        }
        cout << count << endl;
    }
}
