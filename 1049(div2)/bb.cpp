#include <iostream>

void solve() {
    long long x;
    std::cin >> x;
    long long y = 2 * x;
    std::cout << y << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}