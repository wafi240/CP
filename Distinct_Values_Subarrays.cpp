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
        ll n;
    cin >> n;
    vector<ll> v(n + 1, 0);
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 1; i <= n; i++)
    {

        mp[v[i]] = 0;
    }
    ll count = 1;
    ll cntra = 0;
    mp[v[1]] = 1;
    ll pre = 1;
    ll ans = 0;
    bool f = false;
    for (ll i = 2; i <= n; i++)
    {
        if (i == n)
        {
            // cout << "last" << endl;
            
             if (v[i] == v[i - 1])
             {
                ans+=2;
             }
            else if (!f)
            {
                count++;
                // if (count == 0)
                //     count++;
                ans += ((count + 1) * count) / 2;
            }
        }
        else if (pre == mp[v[i]] && v[i] == v[i - 1])
        {
            // cout << "case-2" << endl;
            ans++;
            count = 1;
            f = false;
        }
        else if (mp[v[i]] > pre)
        {
            // cout << "case-3" << endl;

            cntra++;
            ans += ((count + 1) * count) / 2;
            count = 2;
            f = false;
        }
        else
        {
            // cout << "case-4" << endl;
            if (!f)
                count++;
        }
        // cout << v[i] << " " << pre << " " << mp[v[i]] << endl;

        pre = mp[v[i]];
        mp[v[i]] = i;
        // cout << v[i] << " " << count << " " << ans << endl
            //  << endl;
    }
    cout << ans - cntra << endl;

    return 0;
}