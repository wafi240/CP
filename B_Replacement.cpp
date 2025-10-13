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
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '0')
            {
                v[i] = 0;
            }
            else
            {
                v[i] = 1;
            }
        }
        vector<int> v2(n - 1);
        for (
            int i = 0;
            i < n - 1; i++)
        {
            if (s2[i] == '0')
            {
                v2[i] = 0;
            }
            else
            {
                v2[i] = 1;
            }
        }
        int j = 0;
        bool flag = true;
        int i = 0, indx = 0;
        while (j < v2.size() && flag == true)
        {
            i = indx;
            while (i < v.size() - 1)
            {
                if (v[i] != v[i + 1])
                {
                    break;
                }

                i++;
            }
            if (i >= v.size() - 1)
            {
                flag = false;
                break;
            }
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            v.insert(v.begin() + i, v2[j]);
            indx = max(0, i - 1);
            j++;
            // for (int k = 0; k < v.size(); k++)
            // {
            //     cout << v[k] << " ";
            // }
            // nl;
        }
        if (flag)
        {
            YES;
        }
        else
        {
            NO;
        }
    }

    return 0;
}