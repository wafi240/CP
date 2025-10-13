#include <bits/stdc++.h>
#include <numeric>
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

ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}
vector<vector<ll>> v;

int main()
{
    ll n;
    cin >> n;
    ll i = 1;
    while (i <= n)
    {
        if (i == 1)
        {
            i++;
            cout << 0 << endl;
        }
        else if (i == 2)
        {
            i++;
            cout << 6 << endl;
        }
        else if (i == 3)
        {
            i++;
            cout << 28 << endl;
        }
        else if (i == 4)
        {
            i++;
            cout << 96 << endl;
        }
        else
        {
            ll t=i*i;
            ll tot = nCr(t, 2);

            ll p = i;
            ll x = (i + 1) / 2;
            i++;
            ll s1 = 2 * (p - 2) * 2;
            ll s2 = 2 * (p - 2) * 3;
            ll s3 = (p - 4) * 4 * (p - 2);
            ll s4 = 4;
            ll s5 = (p - 4) * 2;
            ll sum = s1 + s2 + s3 + s4 + s5;
            cout << tot-sum << endl;
        }
    }
}