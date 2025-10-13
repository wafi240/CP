#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
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
const ll inv6 = 166666668; // modular inverse of 6 under mod
const ll inv3 = 333333336; // modular inverse of 3 under mod
#define _mod(a, b) ((a % b) + b) % b
#define ADD_mod(a, b) (((a) + (b)) % mod)
#define SUB_mod(a, b) (((a) - (b) + mod) % mod)
#define MUL_mod(a, b) (((a % mod) * (b % mod)) % mod)
#define POW_mod(a, b) (mod_exp(a, b, mod))
int main()
{
    fast;
    tt()
    {
        ll n;
        cin >> n;
        ll x = n;
        bool flag = false;
        if (n % 2 == 0)
        {
            flag = true;
        }
        if (n == 2)
        {
            cout << 14154 << endl;
            continue;
        }
        ll ans = MUL_mod(n, n + 1);
        ans = MUL_mod(ans, 2 * n + 1);
        ans = MUL_mod(ans, inv6);


        // cout<<ans<<endl;

        ll k = flag ? (x - 1) / 2 : x / 2;

        ll ans1 = MUL_mod(k, k + 1);
        ans1 = MUL_mod(ans1, 2 *k + 1);
        ans1 = MUL_mod(ans1, 2 );
        ans1 = MUL_mod(ans1, 2 );
        ans1 = MUL_mod(ans1, inv3);

        // cout << ans1 << endl;
        ll ans3 = 0;
        if (flag == true)
        {
            ans3 = MUL_mod(x, x - 1);
        }
        // cout<<ans3<<endl;
        ll sum = ADD_mod(ans, ans1);
        sum = ADD_mod(sum, ans3);
        sum = MUL_mod(sum, 2022);
        cout << sum << endl;
    }
    return 0;
}