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

        int n, m, i, j;
        cin >> n >> m >> i >> j;
        if (i == 1 && j == 1)
        {
            cout << n << " " << m << " " << 1 << " " << m << endl;
        }
        else if (i == 1 && j == m)
        {
            cout << 1 << " " << 1 << " " << n << " " << m << endl;
        }
        else if (i == n && j == 1)
        {

            cout << 1 << " " << 1 << " " << 1 << " " << m << endl;
        }
        else if (i == n && j == m)
        {

            cout << 1 << " " << 1 << " " << 1 << " " << m << endl;
        }
        else
        {
            cout << 1 << " " << 1 << " " << n << " " << m << endl;
        }
    }

    return 0;
}