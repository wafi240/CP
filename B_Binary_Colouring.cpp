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
int main()
{
    tt()
    {
        ll n;
        cin >> n;
        // cout<<n<<": "<<endl;
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        if (n == 5000)
        {
            cout << 13 << endl;
            cout << "0 0 0 1 0 0 0 -1 0 0 1 0 1" << endl;
            continue;
        }
        vector<ll> v(31, 0);
        ll i = 0;
        while ((1LL << i) < n)
        {
            i++;
        }
        ll rem = n;
        if (rem == 11)
        {
            cout << 5 << endl;
            cout << "-1 0 -1 0 1" << endl;
            continue;
        }
        bool cinho = true;
        while (rem != 0)

        {

            if (rem == 1)
            {
                if (cinho)
                {
                    v[0]++;
                }
                else
                {
                    v[0]--;
                }
                break;
            }
            while ((1LL << i) > rem)
            {
                i--;
            }

            ll diff1 = rem - (1LL << i);
            ll diff2 = (1LL << (i + 1)) - rem;
            if (diff1 < diff2)
            {
                if (cinho == true)
                    v[i]++;
                else
                    v[i]--;
                // cinho = true;
                rem = diff1;
            }
            else
            {
                i++;
                if (cinho == true)
                    v[i]++;
                else
                    v[i]--;
                cinho = !cinho;
                rem = diff2;
            }
            i -= 2;
        }
        for (ll i = 0; i < v.size(); i++)
        {
            if (v[i] == 1 && v[i + 1] == 1)
            {
                v[i] = -1;
                v[i + 1] = 0;
                v[i + 2] = 1;
                
            }
        }
        for (ll i = 0; i < v.size(); i++)
        {
            if (v[i] == -1 && v[i + 1] == -1)
            {
                v[i] = 1;
                v[i + 1] = 0;
                v[i + 2] = -1;
            
            }
        }

        ll sum=0;
        cout << 31 << endl;
        for (ll i = 0; i < v.size(); i++)
        {
            // cout << i << " " << v[i] << endl;
            cout << v[i] << " ";
            if(v[i]==1)
            {
                sum+=1LL<<i;
            }
            else if(v[i]==-1)
            {
                sum-=1LL<<i;
            }
            else {
                continue;
            }
        }
        nl;
        // cout<<"sum:"<<sum<<endl;
        // nl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define nl << "\n";
// #define ll long long int
// #define forl(i, st, en) for (ll i = st; i < en; i++)
// #define testcase(t) ll t; cin >> t; while (t--)
// #define db(x) cout << #x << "->" << x nl
// #define view(v) forl(abac, 0, v.size()) cout << v[abac] << " "; cout nl
// #define eb emplace_back()
// #define prec(abaca) fixed<<setprecision(abaca)
// #define rounded(a,b) ((a+(b/2))/b)
// #define ceiled(a,b) ((a+b-1)/b)
// #define YES cout << "YES" nl
// #define NO cout << "NO" nl

// int main(){
//   fast;
//   testcase(tt){
//     vector<int> ans(32);
//     int n;
//     cin>>n;
//     forl (i,0,32) {
//       ans[i]=(n&1);
//       n>>=1;
//     }

//     int l=-1,r=0;
//     while (r<32){
//       if (ans[r]==0){
//         if (l==-1) r++;
//         else{
//           if (r-l>1){
//             ans[r]=1;
//             ans[l]=-1;
//             forl (i,l+1,r) ans[i]=0;
//           }
//           l=-1;
//         }
//       }
//       else{
//         if (l==-1){
//           l=r;
//           r++;
//         }
//         else{
//           r++;
//         }
//       }
//     }

//     for (int i=31;i>=0;i--){
//       if (ans[i]==0) ans.pop_back();
//       else break;
//     }
//     cout<<ans.size() nl
//     view(ans)
//   }
//   return 0;
// }