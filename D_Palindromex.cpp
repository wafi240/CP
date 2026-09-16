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
ll ispd(vector<ll> &v, ll i1, ll i2)
{
    map<ll, ll> ck;
    ll num = 0;
    ck[v[i1]]++;
    if (v[i1] == num)
    {
        num++;
    }
    ck[v[i1 + 1]]++;
    if (v[i1 + 1] == num)
    {
        num++;
    }
    ll j = 0;
    while (i1 - j >= 0 && i2 + j < v.size() && v[i1 - j] == v[i2 + j])
    {

        if (v[i1 - j] == num)
        {
            ck[num]++;
            ll dd = v[i1 - j];
            while (ck[dd] > 0)
            {
                dd++;
            }
            num = dd;
        }
        else

        {
            ck[v[i1 - j]]++;
        }
        j++;
    }
    // ot("f\n");
    return num;
}
ll is2(ll i, ll n, map<ll, ll> &ck, vector<ll> &v)
{

    ck[v[i]]++;
    ll num = 1;
    if (i > 0 && i < v.size() - 1)
    {
        ll j = 0;
        bool f = true;
        while (i - j >= 0 && i + j < v.size() && v[i - j] == v[i + j])
        {

            if (v[i - j] == num)
            {
                ck[num]++;
                ll dd = v[i - j];
                while (ck[dd] > 0)
                {
                    dd++;
                }
                num = dd;
            }
            else

            {
                ck[v[i - j]]++;
            }
            j++;
        }
    }
    return num;
}
int main()
{
    fast

        tt
    {
        ll n;
        cin >> n;
        vector<ll> v(2 * n);
        vector<vector<ll>> z(n);
        for (ll i = 0; i < v.size(); i++)
        {
            cin >> v[i];
            z[v[i]].pb(i);
        }
        // vector<ll>ck(n+2,false);

        
        ll ans = -1;

        for (ll i = 0; i < n; i++)
        {
            if (abs(z[i][0] - z[i][1]) <= 2)
            {
                ll s =ispd(v,z[i][0],z[i][1]);
                ans=max(ans,s);
                // ot(i);
            }
        }

        map<ll, ll> ck2;
        ll s = is2(z[0][0], 2 * n, ck2, v);

        ans = max(ans, s);
        // ot(ans);
        map<ll, ll> ck3;
        s = is2(z[0][1], 2 * n, ck3, v);

        ans = max(ans, s);

        if (ans == -1)
        {
            ot(n);
        }
        else
        {
            ot(ans);
        }
    }

    return 0;
}