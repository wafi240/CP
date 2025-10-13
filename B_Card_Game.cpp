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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int count = 0;
        int c1 = 0, c2 = 0;
        if (a1 > b1)
            c1++;
        if (a1 < b1)
            c2++;
        if (a2 < b2)
            c2++;
        if (a2 > b2)
            c1++;

        if (c1 > c2)
        {
            count++;
        }
        c1 = 0;
        c2 = 0;
        if (a1 > b2)
            c1++;
        if (a1 < b2)
            c2++;
        if (a2 < b1)
            c2++;
        if (a2 > b1)
            c1++;
        if (c1 > c2)
        {
            count++;
        }

        cout << 2*count << endl;
    }

    return 0;
}