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

vector<vector<ll>> adj;
vector<ll> visited;
ll counter = 0;
ll x = 0;
ll p = 0;
vector<ll> v;
void dfs(ll node, ll lim, ll x)
{
    if (v[node - 1] == 1)
    {
        x++;
    }
    else
    {
        x = 0;
    }
    if (x > lim)
    {
        return;
    }
    visited[node] = 1;
    bool leaf = true;
    for (ll u : adj[node])
    {
        if (!visited[u])
        {
            leaf = false;
            dfs(u, lim, x);
        }
    }
    if(leaf)counter++;
}
// n node
// m path
int main()
{
    ll n, k;
    cin >> n >> k;
    v.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    adj.resize(n + 1);
    visited.assign(n + 1, 0);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, k, 0);
    cout << counter << endl;

    return 0;
}