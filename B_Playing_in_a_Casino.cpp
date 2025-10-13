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
        ll p, n;
        cin >> p >> n;
        vector<vector<int>>
            v(n, vector<int>(p, 0));

        for (ll i = 0; i < p; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> v[j][i];
                // cout<<v[j][i]<<" ";
            }
        }

        if (p == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            sort(v[i].begin(), v[i].end());
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < p; j++)
        //     {
        //         cout << v[i][j] << " ";
        //     }
        //     nl;
        // }

        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            ll count = 0;
            ll j = p - 1;
            ll k = p - 2;
            while (k >= 0)
            {
                count += (v[i][j] - v[i][k]);
                k--;
                // cout << count << "-cont\n";
            }
            // cout << count << "-cont\n";
            j--;
            sum+=count;
            while (j > 0)
            {
                ll diff = v[i][j + 1] - v[i][j];
                // cout << diff << "-diff\n";
                count = count - (diff);
                count=count-(diff*j);
                // cout << count << "-cont\n";
                sum += count;
                // cout << sum << "-sum\n";
                j--;
            }
            // nl;
        }
        cout << sum << endl;
    }

    return 0;
}