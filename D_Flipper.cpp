#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<long long> &a, int start, int end) {
    for (int i = start; i < end; i++) {
        cout << a[i] << " ";
    }
}

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // find index of maximum element
    int mx = max_element(a.begin(), a.end()) - a.begin();

    // case 1: max is at index 0
    if (mx == 0) {
        mx = max_element(a.begin() + 1, a.end()) - a.begin();

        print(a, mx, n);

        if (mx == n - 1) {
            print(a, 0, mx);
        } else {
            cout << a[mx - 1] << " ";
            print(a, 0, mx - 1);
        }

        cout << "\n";
        return;
    }

    // case 2: max is at last index
    if (mx == n - 1) {
        int cur = -1;

        for (int i = mx; i > 0; i--) {
            if (a[i] > a[0]) {
                cout << a[i] << " ";
                cur = i - 1;
            } else {
                cur = i;
                break;
            }
        }

        if (cur == -1 && mx - 1 != 0) {
            cout << a[0] << " ";
        } else {
            print(a, 0, cur + 1);
        }

        cout << "\n";
        return;
    }

    // case 3: max is in middle
    int cur = -1;

    // print suffix starting from max
    print(a, mx, n);

    // include element before max
    cout << a[mx - 1] << " ";

    for (int i = mx - 2; i > 0; i--) {
        if (a[i] > a[0]) {
            cout << a[i] << " ";
            cur = i - 1;
        } else {
            cur = i;
            break;
        }
    }

    if (cur == -1 && mx - 1 != 0) {
        cout << a[0] << " ";
    } else {
        print(a, 0, cur + 1);
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}