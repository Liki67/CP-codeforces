
#include<vector>
#include<iostream>
#include <unordered_map>
#include <random>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int RD = uniform_int_distribution<int>(0, (1 << 30))(rng);
bool solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    unordered_map<int, int> cnt;

    for (int x : A) {
        int r = x % k;
        int key = (min(r, k - r) ^RD);
        cnt[key]++;
    }

    for (int x : B) {
        int r = x % k;
        int key = (min(r, k - r)^RD);
        cnt[key]--;
    }

    for (auto &p : cnt) {
        if (p.second != 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}