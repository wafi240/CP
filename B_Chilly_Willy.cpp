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
#define vi1(n) vector<int> v(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
int numberLengthString(long long num)
{
    string numStr = to_string(abs(num));
    return numStr.length();
}
int main()
{
    ll n;
    cin >> n;
    if (n < 3)
    {
        cout << -1 << endl;
    }
    else
    {
        ll x = 210;
        ll low = 1;
        ll high = 1e18;
        ll ans = 1;
        while (low<=high)
        {
            ll mid = low + (high - low) / 2;
            if (numberLengthString(x * mid) >= n)
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << x * ans << endl;
    }

    return 0;
}