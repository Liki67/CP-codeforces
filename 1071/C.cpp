#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;

long long get_max_v(long long lim, long long nn) {
    long long res = 0;
    for (int p = 31; p >= 0; p--) {
        long long bt = 1LL << p;
        if ((nn & bt) == 0) continue;
        if (res + bt <= lim) {
            res += bt;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        long long n;
        int k;
        cin >> n >> k;
        if (k % 2 == 1) {
            for (int i = 0; i < k; i++) {
                cout << n << " ";
            }
            cout << "\n";
            continue;
        }
        // even k
        vector<long long> freev;
        for (int p = 31; p >= 0; p--) {
            long long bt = 1LL << p;
            if ((n & bt) == 0) {
                freev.push_back(bt);
            }
        }
        long long m = 0;
        for (auto bt : freev) {
            long long nm = m + bt;
            if (2LL * nm > n) continue;
            long long L = nm;
            long long R = n - nm;
            long long mv = get_max_v(R, n);
            if (mv >= L) {
                m = nm;
            }
        }
        long long R = n - m;
        long long vv = get_max_v(R, n);
        long long aa = m + vv;
        long long bb = m + n - vv;
        for (int i = 0; i < k - 2; i++) {
            cout << n << " ";
        }
        cout << aa << " " << bb << "\n";
    }
    return 0;
}