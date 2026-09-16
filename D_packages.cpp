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
pair<ll, ll> func(ll k, vector<pair<ll, ll>> &v, ll mid, vector<ll> &temp)
{
    temp.clear();
    ll c = 0;

    ll indx = 0;

    for (ll i = 0; i < v.size(); i++)
    {

        ll a = v[i].first - v[i].second;
        ll b = v[i].second;
        temp.pb(a + (b * mid));
    }
    sort(all(temp));

    for (ll i = 0; i < mid; i++) 
    {
        c += temp[i];
    }
    
    if (c <= k)
    {
        indx = mid;
    }
    else
    {
        indx = -1; 
    }
    
    return {indx, c};
}
int main()
{
    fast
        ll n,
        k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        v.pb({a[i] + b[i], b[i]});
    }
    sort(all(v));

    ll mx = 0LL;
    ll mn = 0LL; 

    ll lo = 1, hi = n; 
    vector<ll> maxima;
    vector<ll> temp;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        pair<ll, ll> x = func(k, v, mid, temp);
        if (x.first == mx)
        {
            maxima.pb(x.first);
            lo = mid + 1; 
            mn = min(mn, x.second);
        }
        else if (x.first > mx)
        {
            mx = x.first;
            maxima.clear();
            maxima.pb(mx);
            lo = mid + 1; 
            mn = x.second;
        }
        else
        {
            hi = mid - 1; 
        }
    }

    cout << mx << " " << mn << endl;

    return 0;
}