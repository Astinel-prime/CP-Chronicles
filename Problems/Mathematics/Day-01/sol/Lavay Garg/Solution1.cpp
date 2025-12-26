#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int diff = abs(a - b);
        int N = 2 * diff;
        if (diff == 0 || max({a, b, c}) > N) {
            cout << -1 << '\n';
            continue;
        }

        if (c > N / 2) {
            cout << c - N / 2 << '\n';
        } else {
            cout << c + N / 2 << '\n';
        }
    }
}
