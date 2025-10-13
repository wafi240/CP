#include <bits/stdc++.h>
using namespace std;

bool dp[26][26][26][26];

int main() {
    memset(dp, 0, sizeof(dp));

    for (int a = 0; a <= 25; a++) {
        for (int b = 0; b <= 25; b++) {
            for (int c = 0; c <= 25; c++) {
                for (int d = 0; d <= 25; d++) {
                    bool win = false;

                    if (a > 0) {
                        if (d == 0) {
                            win = true;
                        } else {
                            if (dp[a - 1][b][c][d - 1]) {
                                win = true;
                            }
                        }
                    }

                    if (!win && b > 0) {
                        if (c == 0) {
                            win = true;
                        } else {
                            if (dp[a][b - 1][c - 1][d]) {
                                win = true;
                            }
                        }
                    }

                    if (!win && c > 0) {
                        if (b == 0) {
                            win = true;
                        } else {
                            if (dp[a][b - 1][c - 1][d]) {
                                win = true;
                            }
                        }
                    }

                    if (!win && d > 0) {
                        if (a == 0) {
                            win = true;
                        } else {
                            if (dp[a - 1][b][c][d - 1]) {
                                win = true;
                            }
                        }
                    }

                    dp[a][b][c][d] = win;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int r0 = (n + 3) / 4;
        int r1 = (n + 2) / 4;
        int r2 = (n + 1) / 4;
        int r3 = n / 4;

        if (dp[r0][r1][r2][r3]) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }

    return 0;
}