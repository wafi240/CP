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

#define vi(v, n) vector<ll> v(n, 0)
#define vi1(v, n) vector<ll> v(n + 1, 0)

#define loop0(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, n) for (ll i = 1; i <= n; i++)

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
    fast

        tt
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        map<pair<ll, ll>, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.pb(x); // v.pb({x,0});
            mp[{x, i}] = 1;
            ;
        }
        vector<ll> p;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            p.pb(x);
        }
        sortv(p);
        auto it = mp.begin();
        ll indx = 0;
        while (it != mp.end())
        {
            it->second = p[indx];
            indx++;
            it++;
        }
        it = mp.begin();
        vector<ll> ans(n, 0);
        while (it != mp.end())
        {
            ans[it->first.second] = it->second;
            it++;
        }

        for (ll i = 0; i < n; i++)
        {
            cout<<ans[i]<<" ";
        }
        
        cout << endl;
    }

    return 0;
}