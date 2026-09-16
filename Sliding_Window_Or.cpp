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

int main()
{
    fast
        ll n,
        k;
    if (!(cin >> n >> k))
        return 0;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    // Corner case: window size 1
    if (k == 1)
    {
        ll cur = x;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ans ^= cur;
            cur = (a * cur + b) % c;
        }
        cout << ans << "\n";
        return 0;
    }

    vector<int> v(n);
    v[0] = x;
    for (ll i = 1; i < n; i++)
    {
        v[i] = ((a * v[i - 1]) + b) % c;
    }

    vector<ll> sf(k, 0);
    sf[k - 1] = v[k - 1];
    for (ll i = k - 2; i >= 0; i--)
    {
        sf[i] = sf[i + 1] | v[i];
    }
    ll zor = sf[0];

    if (n == k)
    {
        cout << zor << endl;
        return 0;
    }

    ll temp = 0;
    for (ll i = k; i < n; i += k)
    {
        ll x = min(k, n - i);
        vector<ll> pf(x, 0);
        pf[0] = v[i];
        for (ll j = 1; j < x; j++)
        {
            pf[j] = pf[j - 1] | v[i + j];
        }

        for (ll j = 1; j <= x; j++)
        {
            if (j == k)
            {
                zor ^= pf[k - 1];
            }
            else
            {
                temp = sf[j] | pf[j - 1];
                zor ^= temp;
            }
        }


        if (i + x < n)
        {
            sf[x - 1] = v[i + x - 1];
            for (ll j = x - 2; j >= 0; j--)
            {
                sf[j] = sf[j + 1] | v[i + j];
            }
        }
    }

    cout << zor << endl;
    return 0;
}