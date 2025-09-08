#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;

    long long initial_cakes = 1LL << k;

    if (x == initial_cakes) {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    vector<int> backward_ops;
    long long current_c = x;
    long long total_cakes = 1LL << (k + 1);

    while (current_c != initial_cakes) {
        if (current_c < initial_cakes) {
            backward_ops.push_back(1);
            current_c = 2 * current_c;
        } else {
            backward_ops.push_back(2);
            current_c = 2 * current_c - total_cakes;
        }
    }

    reverse(backward_ops.begin(), backward_ops.end());

    cout << backward_ops.size() << endl;
    for (size_t i = 0; i < backward_ops.size(); ++i) {
        cout << backward_ops[i] << (i == backward_ops.size() - 1 ? "" : " ");
    }
    cout << endl;
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