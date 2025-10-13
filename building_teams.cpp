// wafi is too lazy to code
#include <bits/stdc++.h>
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

vector<ll> indx;
bool bkcd = true;
bool dfs(ll node, bool bkcd)
{
    bkcd = !bkcd;

    if (bkcd == true)
    {
        if (indx[node] == 1)
        {
            return false;
        }
        indx[node] = 2;
    }
    else
    {
        if (indx[node] == 2)
        {
            return false;
        }
        indx[node] = 1;
    }
    visited[node] = 1;
    for (ll ele : adj[node])
    {
        if (!visited[ele])
        {
            if (dfs(ele, bkcd) == false)
            {
                return false;
            }
        }
        else{
            if (indx[ele] == indx[node]) return false;

        }
    }
    return true;
}


int main()
{
    ll n, k;
    cin >> n >> k;
    ll a, b;
    adj.resize(n + 1);
    visited.assign(n + 1, 0);
    indx.assign(n + 1, 0);
    for (ll i = 0; i < k; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool fixi = true;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            fixi = dfs(i, bkcd);
        }
        if (fixi == false)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (ll i = 1; i < n + 1; i++)
    {
        cout << indx[i] << " ";
    }
    nl;

    return 0;
}
//1 4 9