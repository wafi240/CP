#include <bits/stdc++.h>
using namespace std;
#define ll long long

void countAndReplaceSubstring(string &mainStr, const string &subStr, ll p)
{
    if (subStr.empty())
        return;

    ll pos = 0;
    while ((pos = mainStr.find(subStr, pos)) != string::npos)
    {
        mainStr.replace(pos, subStr.length(), to_string(p));
        pos += 1; 
    }
}

int main()
{
    ll n;
    cin >> n;
    map<string, int> mp;

    for (ll i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        mp[s1] = i;
    }

    string s;
    cin >> s;

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        countAndReplaceSubstring(s, it->first, it->second);
    }

    ll sum = 0;
    ll power = 1;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        ll digit = s[i] - '0';
        sum += digit * power;
        power *= n;
    }

    cout << sum << endl;
    return 0;
}