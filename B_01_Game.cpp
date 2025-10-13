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
        int count = 0;
        int i = 0, j = 1;
        vector<int> v(s.size());
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '1')
            {
                v[i] = 1;
            }
            else
            {
                v[i] = 0;
            }
        }

        while (true)
        {
            if (v.size() == 0 || (i >= v.size() - 1))
            {
                break;
            }
            if (v[i] != v[i + 1])
            {
                count++;
                int indx = i;
                v.erase(v.begin() + i + 1);
                v.erase(v.begin() + i);
                i = max(0, indx - 1);
            }
            else
            {
                i++;
            }
        }
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
// cout<<"count: "<<count<<endl;
        if (count % 2 == 0)
        {
            cout << "NET" << endl;
        }
        else
        {
            cout << "DA" << endl;
        }
    }

    return 0;
}