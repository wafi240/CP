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
    fast tt
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> p;
        vector<ll> pn;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] >= 0)
            {
                p.pb(v[i]);
            }
            else
            {
                pn.pb(v[i]);
            }
        }
        if (pn.size() == 0)
        {
            no;
            continue;
        }
        if (p.size() == 0)
        {
            yes;
            for (ll i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
            continue;
        }
        sortv(p);
        sortrv(p);
        sortv(pn);
        ll mx = p[0] - pn[0];
        ll i = 0, j = 0;
        ll sum = 0;
        vector<ll> ans;
        ans.pb(p[i]);
        sum += p[i];
        i++;
        while (i < p.size() && j < pn.size())
        {
            if (sum + p[i] >= mx)
            {
                ans.pb(pn[j]);
                j++;
                sum += ans[ans.size() - 1];
            }
            else
            {
                ans.pb(p[i]);
                i++;
                sum += ans[ans.size() - 1];
            }
        }

        while (i < p.size())
        {
            ans.pb(p[i]);
            i++;
        }
        while (j < pn.size())
        {
            ans.pb(pn[j]);
            j++;
        }
        ll s = accumulate(all(ans), 0LL);
        if (s >= mx)
        {
            no;
            continue;
        }
        yes;
        for (ll i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}