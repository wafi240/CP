
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
vector<ll> p;
void dfs(ll node, ll &x)
{
    visited[node] = 1;
    bool leaf = true;
    for (ll ele : adj[node])
    {
        if (!visited[ele])
        {
            leaf = false;
            dfs(ele, x);
        }
    }
    if (leaf == true)
    {
        x++;
        p.push_back(node);
    }
    return;
}
int main()
{
    tt()
    {

        ll n, k;
        cin >> n >> k;

        
        
        adj.assign(n + 1, vector<ll>());
        visited.assign(n + 1, 0);
        p.clear();
        vector<ll> deg(n + 1, 0);
        for (ll i = 0; i < k; i++)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        ll start = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (deg[i] > 1)
            {
                start = i;
                break;
            }
        }

        ll d = 0;
        dfs(start, d);
        set<ll> st;
        for (ll node : p)
        {
            for (ll neighbor : adj[node])
            {
                st.insert(neighbor);
            }
        }

        cout << st.size() << " " << d / st.size() << endl;
    }

    return 0;
}