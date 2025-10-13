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
        ll c1 = 0, c0 = 0;
        string s;
        cin >> s;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }

        ll maxi = max(c1, c0);
        ll mini = min(c1, c0);
        ll extra = abs(c1 - c0) / 2;
        
        if (extra > k)
        {
            NO;
            continue;
        }
        maxi-=extra*2;
        k-=extra;
        while (k > 0)
        {

            if (maxi >= 2 && mini >= 2)
            {
                maxi -= 2;
                mini -= 2;
                k -= 2;
            }
            else
            {
                break;
            }
        }
        if (k)
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
