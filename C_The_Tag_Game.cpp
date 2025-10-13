

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

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
ll maxi = 0;
vector<vector<ll>> adj;
vector<ll> visited;
vector<ll> visited1;

ll dfs(ll node, ll x)
{
    visited1[node] = 1;ll curr;
    for (ll ele : adj[node])
    {
        if (!visited[ele])
        {
             curr = ele;
        }
        else
        {
            curr = node;
        }
    }
    return curr;
}

ll dfs2(ll node, ll x)
{
    visited[node] = 1;ll curr;
    for (ll ele : adj[node])
    {
        if (visited1[ele])
        {
             curr = ele;
        }
        else
        {
            curr = node;
        }
    }
    return curr;
}
int main()
{

    ll n, x;
    cin >> n >> x;
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while (v[node] !)
    {
        /* code */
    }

    return 0;
}