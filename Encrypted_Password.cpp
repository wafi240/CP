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
        string s1,
        s2;
    cin >> s1 >> s2;

    ll n = s2.size();
    if (s1.size() < s2.size())
    {
        //    ot("case");
        no;
        return 0;
    }

    vector<ll> v(26, 0);
    vector<ll> p(26, 0);
    for (ll i = 0; i < n; i++)
    {
        ll x = s2[i] - 'a';
        v[x]++;
    }
    ll s = 0;

    for (ll i = 0; i < n; i++)
    {

        ll x = s1[i] - 'a';
        if (x >= 0 && x <= 25)
            p[x]++;
    }
    if (v == p)
    {
        yes;
        return 0;
    }
    bool hbe = false;
    for (ll i = n; i < s1.size(); i++)
    {

        ll x = s1[i] - 'a';
        if (x >= 0 && x <= 25)

            p[x]++;

        ll y = s1[i - n] - 'a';
        
        if(y>=0 && y<=25)
        {
            p[y]--;
        }

        if (v == p)
        {
            hbe = true;
            break;
        }
    }
    if (hbe)
        yes;
    else
        no;

    return 0;
}