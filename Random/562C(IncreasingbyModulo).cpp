#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

bool canMakeNonDecreasing(int x, const vector<int>& a, int n, int m) {
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int ai = a[i];

        // Check if we can reach or surpass `prev` with x operations
        if ((ai + x) % m < ai) {
            // Wrap-around occurred
            if (prev <= (ai + x) % m || prev <= ai) {
                // Either we can wrap past prev or already ≥ prev
                continue;
            } else {
                return false;
            }
        } else {
            // No wrap-around
            if (ai >= prev) {
                prev = ai;
            } else if (ai + x >= prev) {
                // We can increment to reach prev
                prev = prev;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int low = 0, high = m - 1, ans = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canMakeNonDecreasing(mid, a, n, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}