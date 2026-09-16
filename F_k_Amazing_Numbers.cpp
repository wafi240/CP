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
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<vector<ll>> vp(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            vp[i].pb(0);
        }
        for (ll i = 0; i < n; i++)
        {
            vp[v[i]].pb(i + 1);
        }
        for (ll i = 1; i <= n; i++)
        {
            vp[i].pb(n + 1);
        }
        map<ll, ll> mp;
        vector<ll> ans(n + 2, LLONG_MAX);

        for (ll i = 1; i <= n; i++)
        {
            ll mx = LLONG_MIN;
            for (ll j = 1; j < vp[i].size(); j++)
            {

                mx = max(mx, vp[i][j] - vp[i][j - 1]);
            }
            mp[i] = mx;
            
        }

        auto it = mp.begin();

        ll ele = -1;
        ll mn = LLONG_MAX;
        while (it != mp.end())
        {
            if (it->second < mn)
            {
                ele = it->first;
                mn = min(mn, it->second);
            }
            ans[it->second] = min(ans[it->second], it->first);
            it++;
        }
        ll mumpi = LLONG_MAX;
        for (ll i = 1; i <= n; i++)
        {
            mumpi = min(ans[i], mumpi);
            ans[i] = mumpi;
        }

        for (ll i = 1; i <= n; i++)
        {
            if (ans[i] == LLONG_MAX)
                cout << -1 << " ";
            else
                cout << ans[i] << " ";
        }

        nl;
    }
    return 0;
}