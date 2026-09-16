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
const ll DFS_MAXN = 200005;
vector<ll> v1;
vector<ll> v2;
void dfs1(ll node, vector<vector<ll>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (ll next : adj[node])
    {
        if (!vis[next])
            dfs1(next, adj, vis);
    }
    v1.pb(node);
}
void dfs2(ll node, vector<vector<ll>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    v2.pb(node);
    for (ll next : adj[node])
    {
        if (!vis[next])
            dfs2(next, adj, vis);
    }
}
int main()
{
    fast
        ll n,
        k;
    cin >> n >> k;
    vector<vector<ll>> g(n);
    vector<vector<ll>> r(n);
    for (ll i = 0; i < k; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        r[v].pb(u);
    }
    vector<bool> vis(n);
    vector<bool> vis2(n);
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs1(i, g, vis);
        }
    }
    reverse(all(v1));

vector<vector<ll>>SCC;
    for (auto u : v1)
    {
        if (!vis2[u])
        {
            v2.clear();
            dfs2(u, r, vis2);

            
            SCC.pb(v2);
        }
    }
    // vector<ll> IN(n + 1, 0);
    // vector<ll> OUT(n + 1, 0);
    // for (ll u = 0; u <= n; u++)
    // {
    //     for (auto v : g[u])
    //     {
    //         if (SCC[u] !=SCC[v])
    //         {
    //             IN[SCC[u]]++;
    //             OUT[SCC[v]]++;
    //         }
    //     }
    // }
    // ll tot_in = accumulate(all(IN), 0LL);
    // ll tot_out = accumulate(all(OUT), 0LL);
    // ll ans = max(tot_in, tot_out);
    // if (scc == 1)
    //     ans = 0;
    // cout << ans << endl;

// reverse(all(SCC));
    
    cout << SCC.size() << endl;
    for (ll i = 0; i < SCC.size(); i++)
    {
        cout<<SCC[i].size()<<" ";
        for (ll j = 0; j < SCC[i].size(); j++)
        {
            cout << SCC[i][j] << " ";
        }
        nl;
    }

    return 0;
}