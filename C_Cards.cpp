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

struct SegTree
{
    ll n;
    vector<ll> tree, lazy;

    SegTree(ll n)
    {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(ll node, ll l, ll r, vector<ll> &a)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void push(ll node)
    {
        if (lazy[node] != 0)
        {
            tree[node * 2] += lazy[node];
            tree[node * 2 + 1] += lazy[node];

            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];

            lazy[node] = 0;
        }
    }

    void update(ll node, ll l, ll r, ll ql, ll qr, ll val)
    {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr)
        {
            tree[node] += val;
            lazy[node] += val;
            return;
        }

        push(node);

        ll mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || r < ql)
            return LLONG_MIN;

        if (ql <= l && r <= qr)
            return tree[node];

        push(node);

        ll mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    void build(vector<ll> &a)
    {
        build(1, 0, n - 1, a);
    }

    void update(ll l, ll r, ll val)
    {
        update(1, 0, n - 1, l, r, val);
    }

    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    fast

    ll n;
    cin >> n;

    vector<ll> v(n + 1, 0);

    for (ll i = 1; i <= n; i++)
        cin >> v[i];

    SegTree st(n + 1);
    st.build(v);

    map<ll, ll> mp;
ll prev=0;
    for (ll i = 1; i <= n; i++)
    {
        ll x = mp[v[i]];
if(x>prev)
{
    prev=x+1;
}
        ll ans = st.query(prev , i);

        ll y = mp[ans];

        if (y < x + 1)
            y = i;

        cout << ans << " " << y << endl;

        mp[v[i]] = i;
    }

    return 0;
}