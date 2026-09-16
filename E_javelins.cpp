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
    cin >> n >> k;
    vector<pair<ll, ll>> v(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> v[i].second;
    for (ll i = 1; i <= n; i++)
        cin >> v[i].first;

    sort(v.begin() + 1, v.end(), greater<pair<ll, ll>>());
    vector<ll> dp(n + 1, LLONG_MAX);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll a=v[i].second;
        ll b=v[i].first;
        for (ll j = i; j >= 1; j--)
        {
            if (dp[j - 1] != LLONG_MAX && dp[j - 1] + a + (j - 1) * b <= k)
                dp[j] = min(dp[j], dp[j - 1] + a + (j - 1) * b);
        }
    }
    ll mx = 0;
    for (ll i = n; i >= 1; i--)
    {
        if (dp[i] != LLONG_MAX)
        {
            mx = i;
            break;
        }
    }

    cout << mx << " " << dp[mx] << endl;

    return 0;
}