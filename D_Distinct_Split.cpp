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
        vector<int> v1(n + 1, 0);
        vector<int> v2(n + 1, 0);
        unordered_set<char> s1;
        unordered_set<char> s2;
        for (int i = 0; i < n; i++)
        {
            s1.insert(s[i]);
            v1[i + 1]=s1.size();
        }

        for (int i = n-1; i>= 0; i--)
        {
            s2.insert(s[i]);
            v2[i + 1]=s2.size();
        }
        int maxi = 0;

        // for (int i = 0; i < n; i++)
        // {
        //     cout<<v1[i]<<" ";
        // }nl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<v2[i]<<" ";
        // }
        // nl;
        v2.push_back(0);
        for (int i = 0; i < n + 1; i++)
        {
            maxi = max(v1[i] + v2[i+1], maxi);
            // cout << maxi << " ";
        }
        cout << maxi << endl;
    }

    return 0;
}