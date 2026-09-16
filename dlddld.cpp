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
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        bool hbe = true;
        vector<ll> v1;
        vector<ll> v2;
        for (ll i = 0; i < n; i++)
        {
            if (c[i] < b[i] || c[i] > a[i] || (a[i] - c[i]) % 2 != 0)
            {
                hbe = false;
                break;
            }
            ll x = c[i] - b[i];

            v1.pb(2 * x);
            ll y = a[i] - c[i];
            v2.pb(y);
        }

       
        ll s1=accumulate(all(v1),0LL);
        ll s2=accumulate(all(v2),0LL);
       if(s1!=s2)
       {
        hbe=false;
       }

        if (hbe)
            yes;
        else
            no;
    }
    return 0;
}