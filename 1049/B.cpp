#include <iostream>
#include <string>
using namespace std;

long long modString(const string &s, long long m) {
    long long res = 0;
    for (char c : s) {
        res = (res * 10 + (c - '0')) % m;
    }
    return res;
}

void solve() {
    long long x; 
    cin >> x;

    string s = to_string(x);

    for (long long i = 1; i < 1e9; i++) {
        string candidate = s + to_string(i);
        if (modString(candidate, x + i) == 0) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}