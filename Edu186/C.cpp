#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<cmath>
#include<map>


using namespace std;
long long count_valid_shifts(int n, const vector<int>& X, const vector<int>& Y) {
    long long valid_count = 0;
    for (int s = 0; s < n; ++s) {
        bool possible = true;
        for (int m = 0; m < n; ++m) {
            if (X[m] >= Y[(m + s) % n]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            valid_count++;
        }
    }
    return valid_count;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    long long S1 = count_valid_shifts(n, a, b);
    long long S2 = count_valid_shifts(n, b, c);

    cout << (long long)n * S1 * S2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}