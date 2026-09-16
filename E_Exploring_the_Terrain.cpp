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

ll func(vector<vector<ll>> &v, ll i, ll j, ll n, ll m, vector<vector<ll>> &vis)
{
    ll sum = 0;
    if (!vis[(i + n - 1) % n][(j + m - 1) % m])
    {
        sum += v[(i + n - 1) % n][(j + m - 1) % m];
        vis[(i + n - 1) % n][(j + m - 1) % m] = true;
    }
    if (!vis[(i + n - 1) % n][(j + 1 + m - 1) % m])
    {
        sum += v[(i + n - 1) % n][(j + 1 + m - 1) % m];
        vis[(i + n - 1) % n][(j + 1 + m - 1) % m] = true;
    }
    if (!vis[(i + n - 1) % n][(j - 1 + m - 1) % m])
    {
        sum += v[(i + n - 1) % n][(j - 1 + m - 1) % m];
        vis[(i + n - 1) % n][(j - 1 + m - 1) % m] = true;
    }
    if (!vis[(i + 1 + n - 1) % n][(j + m - 1) % m])
    {
        sum += v[(i + 1 + n - 1) % n][(j + m - 1) % m];
        vis[(i + 1 + n - 1) % n][(j + m - 1) % m] = true;
    }
    if (!vis[(i - 1 + n - 1) % n][(j + m - 1) % m])
    {
        sum += v[(i - 1 + n - 1) % n][(j + m - 1) % m];
        vis[(i - 1 + n - 1) % n][(j + m - 1) % m] = true;
    }
    return sum;
}
pair<ll, ll> func2(vector<vector<ll>> &v, ll i1, ll j1, ll i2, ll j2, ll n, ll m, vector<vector<ll>> &vis)
{
    ll sum = 0;
    vector<ll> vx = {0, 0, 0, 1, 1, 1, -1, -1, -1};
    vector<ll> vy = {0, 1, -1, 0, 1, -1, 0, 1, -1};
    ll s1 = 0;
    ll s2 = 0;
    for (ll i = 0; i < 9; i++)
    {
        ll x = (i1 + vx[i] + n - 1) % n;
        ll y = (j1 + vy[i] + m - 1) % m;

        if (!vis[x][y])
        {
            if (abs(i2 - x) > 1 && abs(j2 - y) > 1)

                s1 += v[x][y];
            vis[x][y] = true;
        }
    }
    for (ll i = 0; i < 9; i++)
    {
        ll x = (i2 + vx[i] + n - 1) % n;
        ll y = (j2 + vy[i] + m - 1) % m;

        if (!vis[x][y])
        {
            if (abs(i1 - x) > 1 && abs(j1 - y) > 1)

                s2 += v[x][y];
            vis[x][y] = true;
        }
    }
    return {s1, s2};
}
int main()
{
    fast
        ll n,
        m, t;
    cin >> n >> m >> t;
    vector<vector<ll>> v(n, vector<ll>(m));
    vector<vector<ll>> vis(n, vector<ll>(m, false));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<pair<ll, ll>> a(t);
    vector<pair<ll, ll>> b(t);
    for (ll i = 0; i < t; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (ll i = 0; i < t; i++)
    {
        cin >> b[i].first >> b[i].second;
    }
    ll s1 = 0;
    ll s2 = 0;
    for (ll i = 0; i < t; i++)
    {

        ll x1 = a[i].first;
        ll y1 = a[i].second;
        ll x2 = b[i].first;
        ll y2 = b[i].second;
        if (vis[x1][y1] && vis[x2][y2])
        {
            continue;
        }
        else if (vis[x1][y1])
        {
            s2 += func(v, x1, y1, n, m, vis);
        }
        else if (vis[x2][y2])
        {
            s1 += func(v, x2, y2, n,m,vis);
        }
        else
        {
            auto [x, y] = func2(v, x1, y1, x2, y2, n, m, vis);
            s1 += x;
            s2 += y;
        }
    }
    cout << s1 << " " << s2 << endl;

    return 0;
}