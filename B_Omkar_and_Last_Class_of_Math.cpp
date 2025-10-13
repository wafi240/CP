// wafi is too lazy to code
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
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main()
{
    fastIO();

    tt()
    {
        ll n;
        cin >> n;
        ll mini = LLONG_MAX;
        ll indx1 = 1;
        ll indx2 = n - 1;

        if (n % 2 == 0)
        {
            indx1 = n / 2;
            indx2 = n / 2;
        }

        else
        {

            for (ll i = 2; i * i <= n; i++)
            {

                if (n % i == 0)
                {
                    ll x = n / i;
                    indx1 = x;
                    indx2 = n - x;
                    break;
                }
            }
        }
        cout << indx1 << " " << indx2 << endl;
    }
    return 0;
}