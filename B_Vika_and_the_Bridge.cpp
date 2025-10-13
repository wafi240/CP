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
int main()
{
    tt()
    {

        // cout << "case: " << endl;
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<vector<ll>> mat(k);
        // for (ll i = 0; i < k; i++)
        // {
        //     mat[i].push_back(0);
        // }
        for (ll i = 0; i < n; i++)
        {
            mat[v[i] - 1].push_back(i);
        }
        for (ll i = 0; i < k; i++)
        {
            mat[i].push_back(n);
        }

        // for (ll i = 0; i < k; i++)
        // {
        //     for (ll j = 0; j < mat[i].size(); j++)
        //     {
        //         cout << mat[i][j] << " ";
        //     }
        //     nl;
        // }
        // nl;

        vector<vector<ll>> v1(k);
        for (ll i = 0; i < k; i++)
        {
            v1[i].push_back(mat[i][0]);
            for (ll j = 1; j < mat[i].size(); j++)
            {
                v1[i].push_back(mat[i][j] - mat[i][j - 1] - 1);
            }
        }
        for (ll i = 0; i < k; i++)
        {
            sort(v1[i].begin(), v1[i].end());
        }

        // for (ll i = 0; i < k; i++)
        // {
        //     for (ll j = 0; j < v1[i].size(); j++)
        //     {
        //         cout << v1[i][j] << " ";
        //     }
        //     nl;
        // }
        // nl;

        ll mini = LLONG_MAX;
        for (ll i = 0; i < k; i++)
        {
            ll x = v1[i].size() - 1;
            ll maxi = v1[i][x];
            ll minx = v1[i][x - 1];
            ll oni = (maxi - 1) / 2;
            ll twoi = (maxi - 1 - oni);
            ll chosen = max({oni, twoi, minx});

            // cout << chosen << " ";
            mini = min(chosen, mini);
        }
        // nl;
        cout << mini << endl;
    }

    return 0;
}