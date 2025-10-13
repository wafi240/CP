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
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        vector<int> small(26, 0);
        vector<int> big(26, 0);
        for (ll i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                small[s[i] - 'a']++;
            }
            else
            {
                big[s[i] - 'A']++;
            }
        }
        ll count = 0;
        for (int i = 0; i < 26; i++)
        {
            count += min(small[i], big[i]);
            ll diff = abs(small[i] - big[i]);
            diff = diff / 2;
            count += min(k, diff);
            k -= min(k, diff);
            
            
        }
        cout << count << endl;
    }
    return 0;
}