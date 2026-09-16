// wafi the laura, is problem pe ham laura hi tha

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

struct Point {
    double x, y;

    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}

    double dist(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    fast

    int t;
    cin >> t;
    while (t--) {
        Point O(0, 0), P, A, B;

        cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;

        double OA = O.dist(A);
        double OB = O.dist(B);
        double PA = P.dist(A);
        double PB = P.dist(B);
        double AB = A.dist(B);

        double ans1 = max(OA, PA);
        double ans2 = max(OB, PB);
        double ans3 = max({min(OA, OB), min(PA, PB), AB / 2.0});

        double ans = min({ans1, ans2, ans3});

        cout << fixed << setprecision(10) << ans << '\n';
    }
}