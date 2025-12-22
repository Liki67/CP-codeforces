#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int>a(n);
    for (int& x : a) cin >> x;
    n = unique(a.begin(), a.end()) - a.begin();
    int ans = n;
    cout<<ans;
    for (int i = 0; i + 2 < n; ++i) {
      ans -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
      ans -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
    }
    cout << ans << '\n';
   
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