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
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int l = *min_element(v.begin(), v.end());
        int r = *max_element(v.begin(), v.end());

        int maxi = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            maxi = max(maxi, v[n - 1] - v[i]);
        }
        for (int i = 1; i < v.size(); i++)
        {
            maxi = max(maxi, v[i] - v[0]);
        }
        //cases like r,r1,l1,l;
        for (int i = 1; i < n; i++)
        {
            maxi = max(v[i - 1] - v[i], maxi);
        }

        cout << max(maxi, v[n - 1]- v[0]) << endl;
    }

    return 0;
}
