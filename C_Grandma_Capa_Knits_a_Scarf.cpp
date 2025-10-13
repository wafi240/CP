// wafi is too lazy to code
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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> v(26, 0);
        ll mini = LLONG_MAX;
        for (ll i = 0; i < n; i++)
        {

            v[s[i] - 'a']++;
        }

        for (ll i = 0; i < 26; i++)
        {
            if (v[i] == 0)
            {
                continue;
            }
            ll count = 0;
            char c = 'a' + i;
            ll i1 = 0, j = n - 1;
            while (i1 < j)
            {
                if (s[i1] != s[j] && s[i1] != c && s[j] != c)
                {
                    count = n + 1;
                    break;
                }
                if (s[i1] == s[j])
                {
                    i1++;
                    j--;
                }
                else if (s[i1] == c && s[j] != c)
                {
                    count++;
                    i1++;
                }
                else if (s[j] == c && s[i1] != c)
                {
                    count++;
                    j--;
                }
            }
            mini = min(mini, count);
        }
        if (mini >= n)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mini << endl;
        }
    }

    return 0;
}