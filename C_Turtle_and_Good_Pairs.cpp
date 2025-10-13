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

        vector<pair<int, int>> freq(26, {0, 0}); // {character index, count}

        for (ll i = 0; i < n; i++)
        {
            int x = s[i] - 'a';
            freq[x].first = x;
            freq[x].second++;
        }

        // Remove characters with zero frequency
        vector<pair<int, int>> v;
        for (auto &p : freq)
        {
            if (p.second > 0)
            {
                v.push_back(p);
            }
        }

        string s1 = "";
        ll i = 0;
        ll j = v.size() - 1;
        while (i < j)
        {
            ll x = v[i].second;
            ll y = v[j].second;
            char a = v[i].first + 'a';
            char b = v[j].first + 'a';

            if (x == y)
            {
                while (x--)
                {
                    s1 += a;
                    s1 += b;
                }
                i++;
                j--;
            }
            else if (x > y)
            {
                v[i].second = x - y;
                while (y--)
                {
                    s1 += a;
                    s1 += b;
                }
                j--;
            }
            else
            {
                v[j].second = y - x;
                while (x--)
                {
                    s1 += a;
                    s1 += b;
                }
                i++;
            }
        }

        // Handle remaining character if any
        if (i == j && v[i].second > 0)
        {
            char a = v[i].first + 'a';
            int x = v[i].second;
            while (x--)
            {
                s1 += a;
            }
        }

        // Ensure the length matches the original string

        cout << s1 << endl;
    }
    return 0;
}