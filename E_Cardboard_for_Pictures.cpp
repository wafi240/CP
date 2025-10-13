
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

double solveQuadratic(double a, double b, double c)
{
    double discriminant = b * b - 4 * a * c;

    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);
    // cout << x1 << " " << x2 << endl;
    return max(x1, x2);
}
int main()
{
    tt()
    {
        ll n, A;
        cin >> n >> A;
        vector<ll> v(n);
        ll ar = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            ar += (v[i] * v[i]);
        }
        double sum = accumulate(v.begin(), v.end(), 0);
        long long x = solveQuadratic(4 * n, 4 * sum, ar - A);
        ll ch = 4 * (n * x * x) + 4 * x * sum;
        if (ch >= ar - A)
            cout << x << endl;
        else
        {
            cout << x + 1 << endl;
        }
    }

    return 0;
}