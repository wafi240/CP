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

// const ll DFS_MAXN = 200005;
void dfs(ll node, vector<vector<ll>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (ll next : adj[node])
    {
        if (!vis[next])
            dfs(next,adj,vis);
    }
}
int main()
{
    fast
        ll n;
    cin >> n;
    vector<bool> vis(n + 1, false);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<pair<pair<ll,ll>, pair<ll,ll>>> ans;
    ll c = 0;
    ll mx=0;
    ll mxs=0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i,adj,vis);
            c++;
            if (c > 1)
            {
                ans.pb({{i-1,adj[i-1][0]},{i-1,i}});
                mx=0;
                mxs=0;
            }

        }
        else
        {
            if(adj[i].size()>mxs)
            {
                mx=i;
                mxs=adj[i].size();
            }

        }
    }

    if (c == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout<<ans.size()<<endl;
        for (ll i = 0; i < ans.size(); i++)
        {
            cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
        }
        
    }

    return 0;
}