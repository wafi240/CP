// wafi is too lazy to code
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

// ll recurse(ll x, ll y, ll n)
// {
//     if (n == 1)
//     {
//         return x % mod;
//     }
//     if (n == 2)
//     {
//         return y % mod;
//     }
//     return (modify(recurse(x, y, n - 1), mod) - modify(recurse(x, y, n - 2), mod));
// }

int main()
{

    ll x, y;
    cin >> x >> y;
    ll n;
    cin >> n;

    ll m = n % 6;
    ll ans;
    if (m == 0)
    {
        ans = (x - y);
    }
    else if (m == 1)
    {
        ans = x;
    }
    else if (m == 2)
    {
        ans = y;
    }
    else if (m == 3)
    {
        ans = (y - x);
    }
    else if (m == 4)
    {
        ans = (-x);
    }
    else if (m == 5)
    {
        ans = (-y);
    }
    else
    {
        ans = (x - y);
    }
    // cout << m << endl;
    // cout << ans << endl;
    // if (m == 0)
    // {
    //     cout << mod << endl;
    //     return 0;
    // }

    // else
    if (ans < 0)
    {
        ans = (mod + (ans % mod)) % mod;
    }

    else
    {
        ans = ans % mod;
    }
    cout << ans << endl;
    return 0;
}