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
        ll n, k;
        cin >> n >> k;
        if (n == 1 && k == 1)
        {
            cout << 1 << endl
                 << 1 << endl;
        }
        else if (k == 1 || k == n)
        {

            cout << -1 << endl;
        }
        else if ((n % 2 != 0 && (n + 1) / 2 == k) || (n % 2 == 0 && (n) / 2 == k))
        {
            cout << n << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            nl;
        }

        else if ((n - k + 1) % 2 == 0)
        {
            cout << 3 << endl;

            cout << 1 << " " << k << " " << k + 1 << endl;
        }
        else if ((n - k + 1) % 2 != 0)
        {
            cout << 3 << endl;

            cout << 1 << " " << k-1 << " " << k + 2 << endl;
        }
    }
    return 0;
}