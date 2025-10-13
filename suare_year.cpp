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
        int x;
        cin >> x;
        vector<int> v;
        int i = 0;
        while ((i * i) <= x)
        {
            v.push_back(i);
            i++;
        }
        int j = v.size() - 1;
        i = 0;
        bool flag = false;
        while (i <= j)
        {
            int sum = v[i] + v[j];
            sum=sum*sum;
            if (sum == x)
            {

                flag = true;
                break;
            }
            else if (sum > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        if (flag)
        {
            cout << i << " " << j << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}