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
// int main()
// {
//     tt()
//     {
//         ll n;
//         cin >> n;
//         vector<ll> v(n);
//         int lowi;
//         for (ll i = 0; i < n; i++)
//         {
//             ll x;
//             cin >> x;
//             v[i] = abs(x);
//         }
//         lowi = v[0];
//         if (n == 1)
//         {
//             YES;
//             continue;
//         }
//         sort(v.begin(), v.end());

//         ll m = (n + 1) / 2;
//         ll j = v[m];

//         if (lowi >= j)
//         {
//             NO;
//         }
//         else
//         {
//             YES;
//         }
//     }

//     return 0;
// }
int main()
{

    tt()
    {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        int x;
        if (p == 1)
        {
            if (n * q == m)
            {
                YES;
            }
            else
            {
                NO;
            }
            continue;
        }
        if (n % p == 0)
        {
            x = (n) / p;
        }
        else
        {
            x = (n + 1) / p;
        }
        if (x * q < m)
        {
            NO;
        }
        else
        {
            YES;
        }
    }
    return 0;
}