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

        set<int> s;    // For O(1) duplicate checks
        vector<int> v; // Maintains insertion order
        vector<int> v1(n + 1, 1);
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
            // Insert only if not already present
            if (s.size() != len)
            { // .second is true if insertion happened
                v.push_back(x);
            }
            v1[x] = 0;
            len = s.size();
        }
        for (int i = 0; i < v.size(); i++)

        {
            cout << v[i] << " ";
        
        }
        for (int i = 1; i < v1.size(); i++)
        {
            if (v1[i] != 0)
            {
                cout << i << " ";
            }
        }

        nl;
    }
    return 0;
}
