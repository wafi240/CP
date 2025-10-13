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
        string s;
        cin >> s;
        string s1 = s;
        sort(s1.begin(), s1.end());
        if (s == s1)
        {
            out(0);
            continue;
        }
        int c0 = 0, c1 = 0;
        for (ll i = 0; i < s.size(); i++)
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
        if (c0 == 0 || c1 == 0)
        {
            out(0);
            continue;
        }

        ll i = 0, j = 0;
        for (ll k = 0; k < s.size(); k++)
        {
            if (s[k] == '1')
            {
                i = k;
                break;
            }
        }
        for (ll k = i; k < s.size(); k++)
        {
            if (s[k] == '0')
            {
                j = k;
                break;
            }
        }
        ll count = 0;
        if (i >= s.size() || j >= s.size())
        {
            out(0);
            continue;
        }
        while (j < s.size())
        {
            if (s[j] == '1')
            {
                j++;
            }
            else
            {
                i++;
                j++;
                count += j - i + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}