#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> odds;
    long long tot_sum = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        tot_sum += a;
        if (a % 2 != 0) {
            odds.push_back(a);
        }
    }
    if (odds.empty()) {
        cout << 0 << endl;
        return;
    } 
    int lose = odds.size() / 2;
    nth_element(odds.begin(), odds.begin() + lose, odds.end());
    long long loss = 0;
    for (int i = 0; i < lose; ++i) {
        loss += odds[i];
    }
    cout << tot_sum - loss << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}