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
        m;
    cin >> n >> m;
    vector<ll> v1(n);
    vector<ll> v2(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    vector<vector<ll>> v(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll lc=lcm(v1[i], v2[j]);
            ll gc=gcd(v1[i], v2[j]);
            if(gc==1)
            {
                v[i][j]=1;
            }
            else
            v[i][j] = lc;
        }
    }
    bool hbe = true;
    for (ll i = 0; i < n; i++)
    {
        ll x = 1;
        for (ll j = 0; j < m; j++)
        {
            x = lcm(x, v[i][j]);
        }
        if (v1[i] != x)
        {
            hbe = false;
            break;
        }
    }
    for (ll i = 0; i < m; i++)
    {
        ll x = 0;
        for (ll j = 0; j < n; j++)
        {
            x = gcd(x, v[j][i]);
        }
        if (v2[i] != x)
        {
            hbe = false;
            break;
        }
    }
    if (!hbe)
    {
        no;
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < m; j++)
        //     {
        //         cout << v[i][j] << " ";
        //     }
        //     nl;
        // }
    }
    else
    {
        yes;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cout << v[i][j] << " ";
            }
            nl;
        }
    }
    return 0;
}