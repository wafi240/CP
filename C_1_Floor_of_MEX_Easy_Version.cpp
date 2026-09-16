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

        vector<ll> v(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        vector<bool> vp(n, true);

        vector<ll> nx(n + 1);
        for (ll i = 0; i <= n; i++)
        {
            nx[i] = i;
        }

        for (ll i = 1; i <= n; i++)
        {
            ll L = v[i] * i;
            if (L >= n)
            {
                continue;
            } // cout << L << " ";
            // cout<<(v[i]+1)*i-1<<endl;
            ll R = min(n - 1, (v[i] + 1) * i - 1);
            // cout << R << " ";
            ll curr = L;
            while (curr <= R)
            {
                vp[curr] = false;
                // cout<<j<<endl;
                ll j = curr + 1;
                while (j <= R && !vp[j])
                {
                    j = nx[j];
                }
                if (j < n + 1)
                {
                    nx[curr] = j;
                    curr = j;
                } // cout<<nx[curr]<<" "j<<endl;
            }
        }

        vector<ll> ans;
        for (ll i = 0; i < n; i++)
        {
            if (vp[i])
            {
                ans.push_back(i);
            }
        }

        cout << ans.size() << endl;
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}