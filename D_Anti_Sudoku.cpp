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
void fix(vector<string> &v, ll i, ll j)
{

    char temp = v[i][j];
    ll x = temp - '0';
    if (x != 9)
    {
        x++;
    }
    else
    {
        x--;
    }
    v[i][j] = (char)(x+'0');

    return;
}
int main()
{

    tt()
    {

        vector<string> v(9);
        for (ll i = 0; i < 9; i++)
        {
            cin >> v[i];
        }
        fix(v, 0, 0);
        fix(v, 1, 3);
        fix(v, 2, 6);

        fix(v, 3, 1);
        fix(v, 4, 4);
        fix(v, 5, 7);

        fix(v, 6, 2);
        fix(v, 7, 5);
        fix(v, 8, 8);

        for (ll i = 0; i < 9; i++)
        {
            cout << v[i] << endl;
        }
    }

    return 0;
}
/*
1
154873296
386592714
729641835
863725149
975314628
412968357
631457982
598236471
247189563
*/