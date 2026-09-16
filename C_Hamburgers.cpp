// wafi the laura — farming aura
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define error(...)
#endif
#define ll long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
const ll mod = 1e9 + 7;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ot(x) cout << x << endl
#define in(x) cin >> x
#define nl cout << '\n';
#define tt    \
    ll t;     \
    cin >> t; \
    while (t--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortrv(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define all(x) x.begin(), x.end()
#define setbit(x, i) ((x) | (1LL << (i)))
#define checkbit(x, i) ((x) & (1LL << (i)))
#define togglebit(x, i) ((x) ^ (1LL << (i)))
void in_variadic() {}
template <typename T, typename... Args>
void in_variadic(T &first, Args &...rest)
{
    cin >> first;
    in_variadic(rest...);
}
ll adds(ll a, ll b) { return (a + b) % mod; }
ll subs(ll a, ll b) { return (a - b + mod) % mod; }
ll muls(ll a, ll b) { return (a * b) % mod; }
ll binexp(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = muls(res, a);
        a = muls(a, a);
        b >>= 1;
    }
    return res;
}
ll inv(ll a) { return binexp(a, mod - 2); }
ll divs(ll a, ll b) { return muls(a, inv(b)); }
bool f(ll mid, ll p1, ll p2, ll p3, ll x, ll y, ll z, ll ache1, ll ache2, ll ache3, ll budget)
{
    ll tot = 0;

    if (x > 0)
        tot += (mid * x - min(mid*x, ache1)) * p1;
    if (y > 0)
        tot += (mid * y - min(mid*y, ache2)) * p2;
    if (z > 0)
        tot += (mid * z - min(mid*z, ache3)) * p3;
    // cout << "tot :" << tot << endl;
    // cout << mid << " " << tot << endl;
    if (tot <= budget)
        return true;
    else
        return false;
}
int main()
{
    fast
        string s;
    cin >> s;
    ll ache1, ache2, ache3;
    cin >> ache1 >> ache2 >> ache3;
    ll p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    ll c;
    cin >> c;
    ll x = 0, y = 0, z = 0;
    // cin >> x >> y >> z;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            x++;
        if (s[i] == 'S')
            y++;
        if (s[i] == 'C')
            z++;
    }
    // cout << x << " " << y << " " << z << endl;
    ll count = LLONG_MAX;
    if (x > 0)
        count = min(count, ache1 / x);
    if (y > 0)
        count = min(count, ache2 / y);
    if (z > 0)
        count = min(count, ache3 / z);
    if (count == LLONG_MAX)
    {
        cout << 0 << endl;
        return 0;
    }

    ache1 -= (count * x);
    ache2 -= (count * y);
    ache3 -= (count * z);

    // cout << count << endl;
    // cout << ache1 << " " << ache2 << " " << ache3 << endl;

    ll lo = 0;
    // ll hi = min({(ache1 + p1) / x, (ache2 + p2) / y, (ache3 + p3) / z});
    ll hi = 1e12;

    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        if (f(mid, p1, p2, p3, x, y, z, ache1, ache2, ache3, c))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << ans + count << endl;

    return 0;
}