
#include <bits/stdc++.h>
#include <numeric>
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
ll counter = 0;
ll ans = 0;
bool palindrome(ll x)
{
    string s = to_string(x);
    for (ll i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
void func(ll n)
{
    counter++;
    string s = to_string(n);
    string s1 = s;
    reverse(s1.begin(), s1.end());
    ll sum = stoll(s) + stoll(s1);
    if (palindrome(sum))
    {
        ans = sum;
        return;
    }
    else
    {
        func(sum);
    }
}
int main()
{

    tt()
    {
        ll n;
        counter=0;
        cin >> n;
        func(n);
        cout << counter << " " << ans << endl;
    }

    return 0;
}