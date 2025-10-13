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
    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    ll inx = x, iny = y;
    bool lower = false;
    while (true)
    {
        y = iny;

        if (iny < m)
        {
            // cout<<"case: 1"<<endl;
            while (y <= m)
            {
                cout << x << " " << y << endl;
                y++;
            }
        }
        if(iny>1 && iny!=m)
        {
            y=iny-1;
        }
        if (iny > 1) // jj
        {
            // cout<<"case: 2"<<endl;
            while (y >= 1)
            {
                cout << x << " " << y << endl;
                y--;
            }
        }
        if (iny == m)
        {
            iny = m;
        }
        else
        {
            iny = 1;
        }
        if (x == n)
        {
            lower = true;
        }
        if (lower == true)
        {
            x = inx - 1;
            inx--;
        }
        else if (x >= inx && x < n)
        {
            x++;
        }
        if (y == 0)
        {
            iny = 1;
        }
        else if (y >= m)
        {
            iny = m;
        }

        if (x == 0)
        {
            break;
        }
    }

    return 0;
}