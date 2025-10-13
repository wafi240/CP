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

vector<vector<ll>> adj;
vector<ll> visited;
map<pair<ll, ll>, ll> v;
ll maxi = 0;

void dfs(ll node, ll pre, ll sum)
{
    ll s = sum + v[{pre, node}];
    maxi = max(maxi, s);
    visited[node] = 1;
    for (ll ele : adj[node])
    {
        if (!visited[ele])
        {
            dfs(ele, node, s);
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    adj.resize(n);
    visited.resize(n, 0);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        v[{a, b}] = c;
        v[{b, a}] = c;
    }

    visited[0] = 1;
    dfs(0, 0, 0);  
    

    cout << maxi << endl;
    return 0;
}
