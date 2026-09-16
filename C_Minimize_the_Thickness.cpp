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
#define ot(x) cout << x << '\n'
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
void in() {}
template <typename T, typename... Args>
void in(T &first, Args &...rest)
{
    cin >> first;
    in(rest...);
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
        // input
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        // nested loop
        ll sum = 0;
        ll ans = n;
        for (ll i = 0; i < n - 1; i++)
        {
            sum += v[i];
            ll temp = 0;
            bool f = true;
            ll count = 0;
            ll mx = 0;
            for (ll j = i + 1; j < n; j++)
            {

                temp += v[j];
                count++;

                if (temp == sum)
                {
                    temp = 0;
                    mx = max(mx, count);
                    count = 0;
                }
                else if(temp>sum)
                {
                    f = false;
                    break;
                }
            }
            if (f && temp == 0)
            {
                mx=max(i+1,mx);
                ans = min(ans, mx);
                // ans=min(i+1,ans)
                // cout<<sum<<endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}