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
        ll x, y;
        cin >> x >> y;
        // if (x == y)
        // {
        //     cout << y-1 << " " << y << endl;
        // }
        // else if (abs(x - y) == 1)
        // {
        //     if (x > y)
        //     {
        //         cout << min(x, y) << " " << min(x, y) << endl;
        //     }
        //     else
        //     {
        //         ll d = max(x, y) - min(x, y);
        //         d++;
        //         cout << 0 << " " << d << endl;
        //     }
        // }
        // else
        // {
        //     ll d = max(x, y) - min(x, y);
        //     d++;
        //     if (x > y)
        //     {
        //         cout << d << " " << 0 << endl;
        //     }
        //     else
        //     {
        //         cout << 0 << " " << d << endl;
        //     }
        // }
        cout << x - 1 << " " << y << endl;
    }
    return 0;
}