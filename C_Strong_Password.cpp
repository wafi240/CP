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
#define no cout << "NO\n"y
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
        string s;
        cin >> s;
        map<ll, ll> mp;
        map<ll, ll> mc;
        map<ll, ll> mf;
        ll n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        for (ll i = 0; i < s.size(); i++)
        {
            mp[s[i] - '0'] = i + 1;
            mc[s[i] - '0']++;
            if (mf[s[i] - '0'] == 0)
            {
                mf[s[i] - '0'] = i + 1;
            }
        }
        bool hbe = false;
        map<ll, ll> q;
        for (ll i = 0; i < n; i++)
        {
            for (ll x = s1[i] - '0'; x <= s2[i] - '0'; x++)
            {
                q[x]++;
            }
        }
        for (ll i = 0; i <= 9; i++)
        {
            if (mc[i] < q[i])
            {
                hbe = true;
                // cout << i<<" "<<mc[i]<<" "<<q[i] << endl;
            }
        }

        if (hbe)
        {
            yes;
            continue;
        }
        for (ll i = 0; i < n - 1; i++)
        {
            for (ll x = s1[i] - '0'; x <= s2[i] - '0'; x++)

                for (ll y = s1[i + 1] - '0'; y <= s2[i + 1] - '0'; y++)
                {
                    if (x == y)
                    {
                        continue;
                    }
                    else if (mp[y] < mf[x])
                    {
                        hbe = true;
                        // cout << "hoise" << endl;
                        // cout << i << " " << x << " " << y << endl;
                        // cout << i << " " << mf[x] << " " << mp[y] << endl;
                        goto dhon;
                    }
                }
        }
    dhon:
        if (hbe)
            yes;
        else
            no;
    }
    return 0;
}