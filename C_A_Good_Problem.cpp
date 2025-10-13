
#include <bits/stdc++.h>
#include <numeric>   // fixed syntax
using namespace std; // fixed syntax

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

// user defined functions from GPT
string decimalToBinaryWithBitset(ll num) // Changed to ll
{
    if (num == 0)
        return "0";
    const int bits = sizeof(num) * 8;
    string binary = bitset<bits>(num).to_string();

    // Remove leading zeros
    size_t first_one = binary.find('1');
    if (first_one != string::npos)
    {
        return binary.substr(first_one);
    }
    return "0";
}

ll binaryToDecimal(const string &binaryStr)
{
    ll result = 0;
    int n = binaryStr.length();

    if (n == 0)
        return 0;

    bool isNegative = (binaryStr[0] == '-');
    int startIndex = isNegative ? 1 : 0;

    for (int i = startIndex; i < n; i++)
    {
        if (binaryStr[i] == '1')
        {
            result = result * 2 + 1; // Fixed: multiply by 2 instead of bit shift
        }
        else if (binaryStr[i] == '0')
        {
            result = result * 2;
        }
        else
        {
            return -1; // Invalid character
        }
    }

    return isNegative ? -result : result;
}
int main()
{
    tt()
    {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        if (k > n)
        {
            cout << -1 << endl;
        }
        else if (n % 2 != 0)
        {
            cout << l << endl;
        }
        else if (n == 1)
        {
            cout << l << endl;
        }
        else
        {
            if (n == 2)
            {
                cout << -1 << endl;
                continue;
            }
            string s = decimalToBinaryWithBitset(l);
            string s_ = decimalToBinaryWithBitset(l);
            string s1 = "1";
            string s2 = "1";
            for (ll i = 0; i < s.size(); i++)
            {
                s1 += '0';
            }
            for (ll i = 0; i < s_.size() - 1; i++)
            {
                s2 += '0';
            }
            ll x = binaryToDecimal(s1);
            ll x2 = binaryToDecimal(s2);
            set<ll> v;
            v.insert(l);
            if (x >= l && x <= r)
            {
                v.insert(x);
            }
            if (x2 >= l && x2 <= r)

            {
                v.insert(x2);
            }
            v.insert(r);
            // cout<<"haja "<<x2<<" "<<x<<endl;
            auto it = v.begin();
            if ((x < l || x > r) && (x2 < l || x2 > r))
            {
                cout << -1 << endl;
                continue;
            }
            else if (v.size() == 1)
            {
                cout << *it << endl;
                continue;
            }

            else if (n % 4 == 0)
            {
                if (k <= (n / 2))
                {
                    cout << *it << endl;
                }
                else
                {
                    it++;
                    cout << *it << endl;
                }
            }
            else
            {
                if (k <= (n / 2) - 2)
                {
                    cout << *it << endl;
                }
                else
                {
                    it++;
                    cout << *it << endl;
                }
            }
        }
    }

    return 0;
}
