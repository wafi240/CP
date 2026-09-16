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
bool func1(string s)
{
    bool hbe1 = false;
    bool hbe2 = false;

    ll n = s.size();
    ll indx = -1;

    for (ll i = 0; i < n - 1; i++)
    {

        if (s[i] == 'A' && s[i + 1] == 'B')
        {
            hbe1 = true;
            indx = i;
            break;
        }
    }
    if (hbe1)
    {
        for (ll i = indx + 2; i < n - 1; i++)
        {
            if (s[i] == 'B' && s[i + 1] == 'A')
            {
                hbe2 = true;
                indx = i;
                break;
            }
        }
    }
    return hbe1 && hbe2;
}
bool func2(string s)
{
    bool hbe1 = false;
    bool hbe2 = false;

    ll n = s.size();
    ll indx = -1;

    for (ll i = 0; i < n - 1; i++)
    {

        if (s[i] == 'B' && s[i + 1] == 'A')
        {
            hbe1 = true;
            indx = i;
            break;
        }
    }
    if (hbe1)
    {
        for (ll i = indx + 2; i < n - 1; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B')
            {
                hbe2 = true;
                indx = i;
                break;
            }
        }
    }
    return hbe1 && hbe2;
}
int main()
{
    fast
        string s;
    cin >> s;
    bool hbe1 = func1(s);
    bool hbe2 = func2(s);
    if (hbe1 || hbe2)
    {
        yes;
    }
    else
        no;

    return 0;
}