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
    fast tt
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll c1 = 0;
        vector<ll> v(n + 2, 0);
        for (ll i = 0; i < n; i++)
        {
            ll x = s[i] - '0';
            v[i] = x - 1;
            // cout << i + 1 << " " << v[i] << endl;
        }

        vector<ll> pf(n + 2, 0);
        for (ll i = 1; i <= n; i++)
        {
            pf[i] = pf[i - 1] + v[i-1];
        }
        map<ll, ll> mp;
        for (ll i = 0; i <= n; i++)
        {
            // cout<<pf[i]<<endl;
            mp[pf[i]]++;
        }
        ll ans = 0;
        auto it = mp.begin();
        while (it != mp.end())
        {
            ll x = it->second;
            ll temp = (x * (x - 1)) / 2;
            ans += temp;
            // cout<<x<<" ";
            it++;
        }
        nl;
        cout<<ans<<endl;
    }
    return 0;
}