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

        ll x, n;
        cin >> x >> n;

        if (n % 4 == 0)
        {
            cout << x << endl;
            continue;
        }
        ll s=n/4;
        ll y=n%4;

        ll div = (4*s)+1;
        
        
        ll odd1 = x + div;
        ll odd2 = x - 1;
        ll odd3 = x - div - 3;
        ll even1 = x - div;
        ll even2 = x + 1;
        ll even3 = x + div + 3;

        if (x % 2 != 0)
        {

            if (n  % 4 == 1)
            {
                cout << odd1 << endl;
            }
            else if (n  % 4 == 2)
            {
                cout << odd2 << endl;
            }
            else
            {
                cout << odd3 << endl;
            }
        }
        else
        {
            if (n  % 4 == 1)
            {
                cout << even1 << endl;
            }
            else if (n  % 4 == 2)
            {
                cout << even2 << endl;
            }
            else
            {
                cout << even3 << endl;
            }
        }


    }

    return 0;
}