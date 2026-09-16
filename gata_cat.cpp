#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/prantor/Coding/CP/debug.hpp"
#else
#define debug(...)
#define error(...)
#endif
#define int long long
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
const int mod = 1e9 + 7; // 998244353;
#define all(x) (x).begin(), (x).end()
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  for (int ii = 1; ii <= t; ii++) {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (!s.empty() and s.count(x))
        s.erase(x);
      else
        s.insert(x);
    }
    n = size(s);
    // E
    if (n <= 1)
      return cout << "E", 0;
    // T

    // F
    if (n % 2 == 0)
      return cout << "F", 0;
    // S
    if (n % 2) {
      if ((n + 1) % 4 == 0)
        return cout << "S", 0;
      else {
        return cout << "F", 0;
      }
    }
  }
}