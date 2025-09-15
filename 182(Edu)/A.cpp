#include <iostream>
#include <vector>
#include <numeric>

long long get_sum(const std::vector<int>& a, int start, int end) {
    long long current_sum = 0;
    for (int i = start; i <= end; ++i) {
        current_sum += a[i];
    }
    return current_sum;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int l = 1; l <= n - 2; ++l) {
        for (int r = l + 1; r <= n - 1; ++r) {
            long long sum1 = get_sum(a, 0, l - 1);
            long long sum2 = get_sum(a, l, r - 1);
            long long sum3 = get_sum(a, r, n - 1);

            int s1 = sum1 % 3;
            int s2 = sum2 % 3;
            int s3 = sum3 % 3;

            bool all_same = (s1 == s2 && s2 == s3);
            bool all_different = (s1 != s2 && s2 != s3 && s1 != s3);

            if (all_same || all_different) {
                std::cout << l << " " << r << std::endl;
                return;
            }
        }
    }

    std::cout << 0 << " " << 0 << std::endl;
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