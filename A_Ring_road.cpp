
#include <bits/stdc++.h>
#include <numeric>   // fixed syntax
using namespace std; // fixed syntax

#define ll long long
const long long mod = 1e9 + 7;
#define YES puts("YES")
#define NO puts("NO")
#define in(x) cin >> x
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define ot(x) cout << x << " ";
#define out(x) cout << x << endl;
#define nl cout << endl;
#define vi(n) vector<int> v(n);
#define vi1(n) vector<int> v1(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v1(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n + 1, {0, 0});
    vector<pair<ll, ll>> p(n + 1, {0, 0});
    ll fi = 0, li = 0;

    map<pair<ll, ll>, ll> mp;
    for (ll i = 0; i < n; i++)
    {

        ll a, b, c;
        cin >> a >> b >> c;

        mp[make_pair(a, b)] = c;
        mp[make_pair(b, a)] = 0;
        if (i == 0)
        {
            fi = a;
            li = b;
        }

        if (v[a].first == 0)
        {
            v[a].first = b;
        }
        else
        {
            v[a].second = b;
        }

        if (v[b].first == 0)
        {
            v[b].first = a;
        }
        else
        {
            v[b].second = a;
        }
    }
    vector<ll> d;
    d.push_back(fi);
    d.push_back(li);
    while (d.size() < n)
    {
        ll ele = d[d.size() - 1];
        ll pre = d[d.size() - 2];
        ll e1 = v[ele].first;
        ll e2 = v[ele].second;
        if (pre == e1)
        {
            d.push_back(e2);
        }
        else
        {
            d.push_back(e1);
        }
    }
    vector<ll> d_;
    d_.push_back(li);
    d_.push_back(fi);
    while (d_.size() < n)
    {
        ll ele = d_[d_.size() - 1];
        ll pre = d_[d_.size() - 2];
        ll e1 = v[ele].first;
        ll e2 = v[ele].second;
        if (pre == e1)
        {
            d_.push_back(e2);
        }
        else
        {
            d_.push_back(e1);
        }
    }

    ll sum = 0;
    for (ll i = 0; i < n ; i++)
    {
        ll x = mp[{d[i], d[(i + 1) % n]}];
        if (x != 0)
        {
            sum += x;
        }
    }
    ll sum_ = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x = mp[{d_[i], d_[(i + 1) % n]}];
        if (x != 0)
        {
            sum_ += x;
        }
    }
    cout << min(sum, sum_) << endl;
    return 0;
}