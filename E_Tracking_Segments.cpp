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
    void build(ll node, ll start, ll end) // node=currently where?
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
        {
            return;
        }
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
        {
            return 0;
        }
        if (start >= l && end <= r)
        {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        return query(leftchild, start, mid, l, r) + query(rightchild, mid + 1, end, l, r);
    }
};
int main()
{
    fast

        tt
    {

        ll n, k;
        cin >> n >> k;

        vector<pair<ll, ll>> segs;
        for (ll i = 0; i < k; i++)
        {
            ll l, r;
            cin >> l >> r;
            segs.pb({l, r});
        }

        ll q;
        cin >> q;
        vector<ll> Q;
        for (ll i = 0; i < q; i++)
        {
            ll x;
            cin >> x;
            Q.pb(x);
        }
        ll lo = 0, hi = Q.size() - 1;
        ll ans = -1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ST st(n);
            st.build(1, 1, n);
            for (ll i = 0; i <= mid; i++)
            {
                st.update(1, 1, n, Q[i], 1);
            }
            bool f = false;
            for (ll i = 0; i < segs.size(); i++)
            {
                ll ones = st.query(1, 1, n, segs[i].first, segs[i].second);
                ll range_size = (segs[i].second - segs[i].first + 1);
                if (ones > (range_size - ones)) 
                {
                    f = true;
                    break;
                }
            }
            if (f)
            {
                hi = mid - 1;
                ans = mid+1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        ot(ans);
    }

    return 0;
}