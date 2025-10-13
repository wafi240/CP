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
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return (n & (n - 1)) == 0;
}

string toBinaryString(unsigned num)
{
    return bitset<32>(num).to_string();
}
string checked(string &s)
{
    bool one = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1' && one == false)
        {
            one = true;
        }
        else if (one == true && s[i] == '1')
        {
            s[i] = '0';
        }
    }
    return s;
}
int binaryToDecimal(const string &binaryStr)
{
    int decimal = 0;
    int length = binaryStr.length();

    for (int i = 0; i < length; i++)
    {
        if (binaryStr[i] == '1')
        {
            decimal += pow(2, length - 1 - i);
        }
    }

    return decimal;
}
int main()
{
    ll n;
    cin >> n;
    if (isPowerOfTwo(n))
    {
        cout << 1 << endl;
        return 0;
    }
    int count = 0;
    while (n >= 1)
    {
        int x = n;
        if (n == 1)
        {
            count++;
            break;
        }
        if (isPowerOfTwo(n))
        {
            count++;
            break;
        }
        string s = toBinaryString(n);
        s = checked(s);

        n = x - binaryToDecimal(s);
        count++;
    }
    cout << count << endl;
    return 0;
}