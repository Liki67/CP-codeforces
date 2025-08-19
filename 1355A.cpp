#include<iostream>
using namespace std;

pair<int,int> minmax_digits(long long x) {
    int mn = 9, mx = 0;
    while (x > 0) {
        int d = x % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        x /= 10;
    }
    return {mn, mx};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        long long a; 
        long long k;
        cin >> a >> k;

        // We perform K-1 updates
        for (long long i = 1; i < k; ++i) {
            auto [mn, mx] = minmax_digits(a);
            if (mn == 0) break;          // sequence stops changing
            a += 1LL * mn * mx;
        }
        cout << a << '\n';
    }
    return 0;
}