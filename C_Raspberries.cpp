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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        int multi = 1;
        int obo = INT_MAX;
        int odd = 0, even = 0;
        bool divi = false;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            int y=v[i];
            multi = (multi * y);
            int x = v[i] % k;
            if (x != 0)
            {

                obo = min(obo, k - x);
            }
            else
            {

                divi = true;
            }
            if (v[i] % 2 != 0)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        if (divi)
        {

            cout << 0 << endl;
            continue;
        }
        // if (multi % k == 0)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // this is due to the overflow of int
        if (k == 4)
        {
            int ans = obo;
            if (even >= 2)
            {
                ans = 0;
            }
            else if (even == 1 && odd > 0)
            {
                ans = min(obo, 1);
            }
            else if (odd > 1)

            {
                ans = min(obo, 2);
            }
            cout << ans << endl;
        }
        else

            cout << obo << endl;
    }

    return 0;
}