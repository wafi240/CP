#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
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
        ll n, k;
        cin >> n >> k;
        if (n == 1)
        {
        }
        vector<vector<int>> v1(n, vector<int>(n, 0));
        vector<vector<int>> v2(n, vector<int>(n, 0));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> v1[i][j];
            }
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < n; j++)
        //     {
        //         cout << v1[i][j] << " ";
        //     }
        // }
        if (n == 1)
        {
            YES;
            continue;
        }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (v1[i][j] != v1[n - 1 - i][n - 1 - j])
                {
                    count++;
                    v1[n - 1 - i][n - 1 - j] = v1[i][j];
                }
            }
        }
        ll c0 = 0, c1 = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (v1[i][j] == 0)
                {
                    c0++;
                }
                else
                {
                    c1++;
                }
            }
        }

        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < n; j++)
        //     {
        //         cout << v1[i][j] << " ";
        //     }
        // }

        // cout << count << endl;

        if (count == k)
        {
            YES;
        }
        else if (count < k)
        {
            ll diff = k - count;
            // cout << diff << endl;
            if (diff % 2 == 0)
            {

                YES;
            }
            else if ((n * n) <= diff && diff % (n * n) == 0)
            {
                YES;
            }
            else if (c0 > 0 && diff % c0 == 0)
            {
                YES;
            }
            else if (c1 > 0 && diff % c1 == 0)
            {
                YES;
            }
            else if (n % 2 == 1) // central point
            {
                YES;
            }
            else
            {
                NO;
            }
        }

        else
        {
            NO;
        }
    }
    return 0;
}