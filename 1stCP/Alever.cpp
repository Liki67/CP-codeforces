#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        long long xa = 0, xb = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            xa ^= a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            xb ^= b[i];
        }

        if (xa != xb) {
            cout << "NO\n";
            continue;
        }

        if (n == 2) {

            if (a == b) {
                cout << "YES\n";
                continue;
            }

            vector<long long> c = a;
            c[0] = c[0] ^ c[1];
            if (c == b) cout << "YES\n";
            else cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}