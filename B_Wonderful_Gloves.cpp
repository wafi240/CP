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
        vector<int> l(n);
        vector<int> r(n);
        vector<int> leftovers(n);
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
        }
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (l[i] > r[i])
            {
                sum += l[i];
                leftovers[i] = r[i];
            }
            else
            {
                sum += r[i];
                leftovers[i] = l[i];
            }
        }
        sort(leftovers.begin(), leftovers.end());
        reverse(leftovers.begin(), leftovers.end());
        for (int i = 0; i < k - 1; i++)
        {
            sum += leftovers[i];
        }
        sum++;
        cout << sum << endl;
    }
    return 0;
}
