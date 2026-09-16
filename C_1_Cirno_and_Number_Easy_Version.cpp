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
        string a;
        ll n;
        cin >> a >> n;

        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        ll x = stoll(a);
        ll ans = LLONG_MAX;
        ll a_l = (ll)a.length();
        ll mx = max(1LL, a_l - 1);

        if (n == 1 && v[0] == 0)
        {
            cout << x << '\n';
            continue;
        }

        for (ll len = mx; len <= a_l + 1; len++)
        {

            ll total = 1LL << len;
            for (ll mask = 0; mask < total; mask++)
            {
                ll zr = (mask >> (len - 1)) & 1;
                if (len > 1 && v[zr] == 0)
                    continue;

                string b = "";
                b.reserve(len);
                for (ll j = len - 1; j >= 0; j--)
                {
                    ll dg = (mask >> j) & 1;
                    b += to_string(v[dg]);
                }

                ll bn = stoll(b);
                ll diff = LLONG_MAX;
                if (x > bn)
                {
                    diff = x - bn;
                }
                else

                {
                    diff = bn - x;
                }
                if (diff < ans)
                    ans = diff;

                if (ans == 0)
                    break;
            }
            if (ans == 0)
                break;
        }

        cout << ans << endl;
    }
    return 0;
}