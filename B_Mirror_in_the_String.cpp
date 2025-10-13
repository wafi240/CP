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
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << s << s << endl;
            continue;
        }
        int i = 1;
        string s1 = "";
        s1 += s[0];
        while (i < s.size())
        {
            if (s[i] == s1[s1.size() - 1] && i > 1)
            {

                s1 += s[i];
            }
            else if (s[i] < s[i - 1])
            {
                s1 += s[i];
            }
            else
            {
                break;
            }
            i++;
        }
        cout << s1;
        reverse(s1.begin(), s1.end());
        cout << s1 << endl;
    }

    return 0;
}