#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

bool helper(ll mid, vector<ll>& a, int n, ll h) {
    ll hits = 0;
    for (int i = 0; i < n - 1; i++) {
        hits += min(mid, a[i + 1] - a[i]);
    }
    hits += mid;
    return hits >= h;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll low = 1, high = 1e18, ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (helper(mid, a, n, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}