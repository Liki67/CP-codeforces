#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

bool helper(ll mid, int n, ll k, const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < n; i++) {
        ll req = 1LL * mid * a[i];
        if (req > b[i])
            k -= (req - b[i]);
        if (k < 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll low = 0, high = 1e9, ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (helper(mid, n, k, a, b)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}