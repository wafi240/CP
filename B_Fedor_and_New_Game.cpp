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
string decimalToBinary(int decimalNumber, int n)
{
    // Handle the special case of 0
    if (decimalNumber == 0)
    {
        return "0";
    }
    

    string binaryString;
    bool isNegative = false;

    // Handle negative numbers
    if (decimalNumber < 0)
    {
        isNegative = true;
        decimalNumber = -decimalNumber;
    }

    // Convert to binary
    while (decimalNumber > 0)
    {
        binaryString += (decimalNumber % 2) ? '1' : '0';
        decimalNumber /= 2;
    }

    // The digits are collected in reverse order, so reverse them
    reverse(binaryString.begin(), binaryString.end());

    // Add negative sign if needed
    if (isNegative)
    {
        binaryString = "-" + binaryString;
    }
    if (binaryString.size() < n)
    {
        int x = n - binaryString.size();
        reverse(binaryString.begin(), binaryString.end());
        for (int i = 0; i < x; i++)
        {
            binaryString += '0';
        }
        reverse(binaryString.begin(), binaryString.end());
    }
    return binaryString;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    int own;
    cin >> own;
    int shit = 0;
    string owi = decimalToBinary(own, n);
    for (int i = 0; i < m; i++)
    {
        string s1 = decimalToBinary(v[i], n);
        int count = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != owi[i])
            {
                count++;
            }
            if (count > k)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            shit++;
        }
    }
    cout << shit << endl;
    return 0;
}