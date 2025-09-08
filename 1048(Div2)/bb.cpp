#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long m;
    std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.rbegin(), a.rend());

    long long total_cakes = 0;

    if (m > n) {
        total_cakes += m * a[0];
        for (int i = 1; i < n; ++i) {
            total_cakes += (m - i) * a[i];
        }
    } else {
        for (int i = 0; i < m; ++i) {
            total_cakes += (m - i) * a[i];
        }
    }
    
    std::cout << total_cakes << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}