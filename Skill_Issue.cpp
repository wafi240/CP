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

void dj(ll start, vector<vector<ll>> &adj, ll n, vector<ll> &dist)
{
    queue<ll> pq;

    dist[start] = 0;
    // cout << dist[start] << endl;
    pq.push(start);
    while (!pq.empty())
    {
        ll u = pq.front();
        pq.pop();
        // cout << u << " " << dist[u] << endl;
        for (auto child : adj[u])
        {
            if (dist[u] + 1 < dist[child])
            {
                dist[child] = min(dist[child], dist[u] + 1);
                pq.push(child);
            }
        }
    }
    return;
}

int main()
{
    tt
    {
        ll n, k;
        cin >> n >> k;
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> dist(n + 1, LLONG_MAX);
        vector<ll> dist2(n + 1, LLONG_MAX);

        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < k; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dj(c, adj, n, dist);
        dj(a, adj, n, dist2);

        if (dist[a] == dist[b])
        {
            if (dist[a] == LLONG_MAX && dist2[b] != LLONG_MAX)

            {
                cout << "Alice" << endl;
            }
            else
            cout << "Tie" << endl;
        }
        else if (dist[a] == LLONG_MAX)
        {

            if (dist[b] == 1)
            {
                cout << "Tie" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
        else if (dist[b] == LLONG_MAX)
        {
            cout << "Alice" << endl;
        }
        else if (dist[a] < dist[b])
        {
            cout << "Alice" << endl;
        }
        else if (dist[b] < dist[a])
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}