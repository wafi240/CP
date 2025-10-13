
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

void dfs(ll v)
{
    visited[v] = 1;
    for (ll u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
    return;
}
// n node
// m path
int main()
{
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, 0);

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> v;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            v.push_back(i);
            dfs(i);
        }
    }
    cout << v.size()-1<< endl;
    for (ll i = 1; i < v.size(); i++)
    {

        cout << v[i] << " " << v[i - 1] << endl;
    }

    return 0;
}