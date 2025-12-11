#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> e;
    vector<long long> o;
    long long mx = -1;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 0) {
            e.push_back(x);
        } else {
            o.push_back(x);
            if (x > mx) mx = x;
        }
    }

    sort(e.rbegin(), e.rend());

    int ne = e.size();
    int no = o.size();

    vector<long long> p(ne + 1, 0);
    for (int i = 0; i < ne; i++) {
        p[i + 1] = p[i] + e[i];
    }

    for (int k = 1; k <= n; k++) {
        if (no == 0) {
            cout << 0 << " ";
            continue;
        }

        int req = 1;
        
        if (k - 1 > ne) {
            req = k - ne;
        }

        if (req % 2 == 0) {
            req++;
        }

        if (req > no || req > k) {
            cout << 0 << " ";
        } else {
            int take = k - req;
            cout << mx + p[take] << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}