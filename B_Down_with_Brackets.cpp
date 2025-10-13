#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define YES puts("YES")
#define NO puts("NO")
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
        string s;
        cin >> s;
        stack<char> st;
        for (ll i = 1; i < s.size() - 1; i++)
        {
            char x=s[i];
            if (!st.empty())
            {

                if (x == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(x);
                }
            }
            else
            {
                st.push(x);
            }
        }

        if (st.empty())
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}