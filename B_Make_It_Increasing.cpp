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
        int count = 0, cnt = 0;

        bool fixi = false;

        for (int i = n - 2; i >= 0; i--)
        {
            if (v[i + 1] <= v[i])
            {
                while (v[i] >= v[i + 1])
                {
                    if (v[i] == 0 && v[i] >= v[i + 1])
                    {
                        fixi = true;
                        break;
                    }
                    v[i] = v[i] / 2;
                    count++;
                    // cout << v[i] << " " << count << endl;
                }
            }
            if (fixi)
            {
                break;
            }
        }
        if (fixi)
        {
            count = -1;
        }
        cout << count << endl;
    }

    return 0;
}
