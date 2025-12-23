#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        total_sum += abs(a[i] - a[i + 1]);
    }

    long long max_savings = abs(a[0] - a[1]);
    max_savings = max(max_savings, (long long)abs(a[n - 1] - a[n - 2]));

    for (int i = 1; i < n - 1; i++) {
        long long current_dist = abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]);
        long long skip_dist = abs(a[i - 1] - a[i + 1]);
        max_savings = max(max_savings, current_dist - skip_dist);
    }

    cout << total_sum - max_savings << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}