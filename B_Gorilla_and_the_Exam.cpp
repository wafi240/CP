// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const long long mod = 1e9 + 7;
// #define YES puts("YES")
// #define NO puts("NO")
// #define in(x) cin >> x
// #define in2(x, y) cin >> x >> y;
// #define in3(x, y, z) cin >> x >> y >> z;
// #define ot(x) cout << x << " ";
// #define out(x) cout << x << endl;
// #define nl cout << endl;
// #define vi(n) vector<int> v(n);
// #define vi1(n) vector<int> v1(n);
// #define vl(n) vector<ll> v(n);
// #define vl1(n) vector<ll> v1(n);
// #define tt()  \
//     int t;    \
//     cin >> t; \
//     while (t--)
// #define rep1(a, n) for (int i = a; i < (n); ++i)
// #define rep2(i, a, b) for (int i = a; i <= b; ++i)
// #define rep3(a, m) for (int j = a; j < (m); ++j)
// // int main()
// // {
// //     tt()
// //     {
// //         int n, k;
// //         cin >> n >> k;

// //         map<int, int> mp;
// //         for (int i = 0; i < n; i++)
// //         {
// //             int x;
// //             cin >> x;
// //             mp[x]++;
// //         }
// //         int count = 0;
// //         auto it = mp.begin();
// //         auto itt = mp.end();
// //         itt--;
// //         while (it->first < itt->first)
// //         {

// //             int x = k;

// //             while (x != 0)
// //             {
// //                 int d = itt->second;
// //                 itt->second -= min(x, d);
// //                 x -= min(x, d);
// //                 if (itt->second == 0 && x == 0)
// //                 {
// //                     itt--;
// //                     break;
// //                 }
// //                 else if (itt->second == 0 && x > 0)
// //                 {
// //                     itt--;
// //                 }
// //                 else if (itt->second > 0 && x == 0)
// //                 {
// //                     break;
// //                 }

// //                 if (it->first == itt->first)
// //                 {
// //                     break;
// //                 }
// //             }
// //             it++;
// //             count++;
// //         }
// //         if (it->second != 0)
// //         {
// //             count++;
// //         }
// //         cout << "ans: "<<count << endl;
// //     }
// //     return 0;
// // }

// int main()
// {
//     tt()
//     {
//         int n, k;
//         cin >> n >> k;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> v[i];
//         }
//         int count=0;
//         sort(v.begin(), v.end());
//         reverse(v.begin(), v.end());

//         int x = v[n - 1];
//         auto l = v.end();
//         while (l > v.begin())
//         {
//             l = find(v.begin(), v.end(), x);
//             l--;
//             l -= k;
//             x = *l;
//             count++;
//         }
//         if(l==v.begin())count++;
//         cout<<count<<endl;
//     }
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> counts;
        for (auto& [val, cnt] : freq) {
            counts.push_back(cnt);
        }

        sort(counts.begin(), counts.end());

        int distinct = counts.size();
        for (int i = 0; i < counts.size(); ++i) {
            if (k >= counts[i]) {
                k -= counts[i];
                distinct--;
            } else {
                break;
            }
        }

        cout << distinct << endl;
    }
    return 0;
}
