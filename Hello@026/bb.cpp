#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> present(n + 2, false);
        for(int x : a) {
            if(x <= n + 1) {
                present[x] = true;
            }
        }
        int mex = 0;
        while(present[mex]) {
            mex++;
        }
        cout << min(k - 1, mex) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}