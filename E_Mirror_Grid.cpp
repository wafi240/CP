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
ll func(char a, char b, char c, char d)
{
    ll c0 = 0;
    ll c1 = 0;
    if (a == '1')
    {
        c1++;
    }
    else
    {
        c0++;
    }
    if (b == '1')
    {
        c1++;
    }
    else
    {
        c0++;
    }
    if (c == '1')
    {
        c1++;
    }
    else
    {
        c0++;
    }
    if (d == '1')
    {
        c1++;
    }
    else
    {
        c0++;
    }
    return min(c0, c1);
}
int main()
{

    tt()
    {
        // cout << "new case......" << endl;
        ll n;
        cin >> n;
        char arr[n][n];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < n; j++)
        //     {
        //         cout<<arr[i][j]<<" ";
        //     }
        //     nl;
        // }nl;
        ll x = n / 2;
        ll y = n / 2;
        if (n % 2 != 0)
        {
            y++;
        }
        // cout << x << " " << y << endl;
        ll count = 0;
        for (ll i = 0; i < x; i++)
        {
            for (ll j = 0; j < y; j++)
            {
                // cout << i << " " << j << endl;
                // cout << j << " " << n - i - 1 << endl;
                // cout << n - i - 1 << " " << n - j - 1 << endl;
                // cout << n - j - 1 << " " << i << endl;

                ll c = func(arr[i][j], arr[j][n - i - 1], arr[n - i - 1][n - j - 1], arr[n - j - 1][i]);
                count += c;
            }
        }
        cout << count << endl;
    }

    return 0;
}