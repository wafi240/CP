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
        string s;
        cin >> s;
        int countb = 0, maxcount = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'B')
            {
                countb++;
            }
        }
        if (n == k)
        {
            cout << k - countb << endl;
            continue;
        }
        maxcount = countb;//else first count would be missed
        for (int j = k, i = 0; j < n; i++, j++)
        {
            if (s[j] == 'B')
            {
                countb++;
            }
            if (s[i] == 'B')
            {
                countb--;
            }

            maxcount = max(countb, maxcount);
        }

        if (maxcount >= k)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << k - maxcount << endl;
        }
    }
    return 0;
}