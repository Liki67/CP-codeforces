#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    a = abs(a); b = abs(b);  // Ensure non-negative for safety
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool check(const vector<int>& p, const vector<int>& q, int n) {
    for (int i = 1; i < n; i++) {
        if (gcd(p[i-1], q[i-1]) <= 3 && gcd(p[i], q[i]) <= 3) {
            return false;
        }
    }
    return true;
}

void perm(vector<int> p, int n) {
    vector<int> q = p;
    while (next_permutation(q.begin(), q.end())) {
        if (check(p, q, n)) {
            for (int i = 0; i < n; i++) cout << q[i] << " ";
            cout << "\n";
            return;
        }
    }
    // If none found, output -1 (assuming this is required; adjust if not)
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        perm(p, n);
    }
    return 0;
}