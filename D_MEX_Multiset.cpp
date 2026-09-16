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
bool func(ll a, ll b, ll c)
{
    ll x = (a + b + c) - 2 * (max({a, b, c}));
    if (x >= 0)
        return true;
    else
        return false;
}
int main()
{
    fast tt
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<pair<ll, ll>> p;
        ll c0 = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            p.pb({v[i], i});
            if (v[i] == 0)
                c0++;
        }

        sort(all(p));
        vector<char> ans(n);
        vector<ll> a;
        vector<ll> b;
        vector<ll> c;
        ll i = 0;
        if (c0 > 0)
        {
            a.pb(p[i].first);
            ans[p[i].second] = 'A';
            i++;
        }
        if (c0 > 1)
        {
            b.pb(p[i].first);
            ans[p[i].second] = 'B';
            i++;
        }

        for (; i < n; i++)
        {
            ll x = p[i].first;
            ll y = p[i].second;
            if (!a.empty() && x - a.back() == 0)
            {
                a.pb(x);
                ans[y] = 'A';
            }
            else if (!b.empty() && x - b.back() == 0)
            {
                b.pb(x);
                ans[y] = 'B';
            }
            else
            {
                c.pb(x);
                ans[y] = 'C';
            }
        }

        ll q1 = 0;
        for (ll i = 0; i < a.size(); i++)
        {
            if (a[i] == q1)
            {
                q1++;
            }
            else
            {
                break;
            }
        }
        ll q2 = 0;
        for (ll i = 0; i < b.size(); i++)
        {
            if (b[i] == q2)
            {
                q2++;
            }
            else
            {
                break;
            }
        }
        ll q3 = 0;
        for (ll i = 0; i < c.size(); i++)
        {
            if (c[i] == q3)
            {
                q3++;
            }
            else
            {
                break;
            }
        }
        // cout<<q1<<" "<<q2<<" "<<q3<<endl;
        if (func(q1, q2, q3))
        {
            yes;
            for (ll i = 0; i < n; i++)
            {
                cout << ans[i];
            }
            nl;
        }
        else
            no;
    }
    return 0;
}