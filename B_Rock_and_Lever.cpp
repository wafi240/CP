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
ll binaryLength(long long num)
{
    if (num == 0)
        return 1;
    return (int)log2(std::abs(num)) + 1;
}
ll nCr(ll n, ll r)
{
    if (r > n)
        return 0; // Invalid case
    if (r == 0 || r == n)
        return 1; // nC0 = nCn = 1
    if (r > n - r)
        r = n - r; // Optimize using nCr = nC(n-r)

    ll result = 1;
    for (ll i = 1; i <= r; ++i)
    {
        result *= (n - r + i);
        result /= i; // Division is safe due to product property
    }
    return result;
}
int main()
{
    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll x = binaryLength(v[i]);
            mp[x]++;
        }
        ll count = 0;
        auto it = mp.begin();
        while (it != mp.end())
        {
            ll d = nCr(it->second,2);
            count += d;it++;
        }
        cout << count << endl;
    }
    return 0;
}