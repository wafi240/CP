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
class ST
{
private:
    vector<ll> tree;
    ll size;

public:
    ST(ll n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }
    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = 0;
            return;
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        build(leftchild, start, mid);
        build(rightchild, mid + 1, end);
        tree[node] = tree[leftchild] + tree[rightchild];
    }
    void update(ll node, ll start, ll end, ll indx, ll value)
    {
        if (indx < start || indx > end)
            return;
        if (start == end)
        {
            tree[node] = value;
            return;
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        update(leftchild, start, mid, indx, value);
        update(rightchild, mid + 1, end, indx, value);
        tree[node] = tree[leftchild] + tree[rightchild];
    }
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (l > end || r < start)
            return 0;
        if (start >= l && end <= r)
            return tree[node];
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        return query(leftchild, start, mid, l, r) + query(rightchild, mid + 1, end, l, r);
    }
};

int main()
{
    fast
        ll n;
    cin >> n;
    ll m;
    cin >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        // adj[v].pb({u, w});
    }
    ll source, dest;
    // cin >> source >> dest;
    source = 1;
    dest = n;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> parent(n + 1, -1);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {

        ll node = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
           if (wt != dist[node]) continue;

        for (auto child : adj[node])
        {
            ll next_node = child.first;
            ll next_wt = child.second;
            if (next_wt + wt < dist[next_node])
            {
                dist[next_node] = next_wt + wt;
                parent[next_node] = node;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    // cout<<dist[dest]<<endl;



for (ll i = 1; i <=n; i++)
{
    cout<<dist[i]<< ' ';
}
cout<<endl;



    // if (dist[dest] == LLONG_MAX)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }
    // ll curr = dest;
    // vector<ll> path;
    // while (curr != -1)
    // {
    //     path.pb(curr);
    //     curr = parent[curr];
    // }
    // reverse(path.begin(), path.end());
    // for (ll i = 0; i < path.size(); i++)
    // {
    //     cout << path[i] << " ";
    // }
    // cout << endl;

    return 0;
}