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
        int n, m;
        cin >> n >> m;
        vector<int> p(m * n);
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                p.push_back(v[i][j]);
            }
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            sort(v[i].begin(), v[i].end());
        }
        // check permutation
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {

                if (v[i][j] + 1 == v[i][j + 1])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == false)
        {
            cout << -1 << endl;
            continue;
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp.insert({v[i][0], i + 1});
        }
        auto it = mp.begin();
        int x = it->first;
        it++;

        while (it != mp.end())
        {
            int dif = it->first - x;
            x = it->first;
            it++;
        }

        it = mp.begin();
        while (it != mp.end())
        {
            cout << it->second << " ";
            it++;
        }
        nl;
    }
    return 0;
}