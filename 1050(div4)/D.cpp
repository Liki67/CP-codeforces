#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool state = false;
        long long ans = 0;
        vector<long long> b, c, x;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0)
                b.push_back(a[i]);
            else
                c.push_back(a[i]);
        }
        int l = 0, r = (int)b.size() - 1;
        while (l < r) {
            if (l % 2 == 1) {
                swap(b[l], b[r]);
                l++;
                r--;
            } else {
                l++;
            }
        }
        if (b.size() % 2 == 1) {
            x.insert(x.end(), b.begin(), b.end());
            x.insert(x.end(), c.begin(), c.end());
        } else {
            for (int i = 0; i + 1 < (int)b.size(); i++) {
                x.push_back(b[i]);
            }
            x.insert(x.end(), c.begin(), c.end());
            if (!b.empty()) x.push_back(b.back());
        }

        for (int i = 0; i < (int)x.size(); i++) {
            if (x[i] % 2 != 0) {
                if (!state) {
                    state = true;
                    ans += x[i];
                }
            } else {
                if (state) {
                    ans += x[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}