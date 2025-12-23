#include<iostream>
#include<vector>
#include<string>
using namespace std;

int helper(int n, vector<int>& a, vector<int>& b, int sumA, int sumB, int k, vector<vector<int>>& dp) {
    if (k == 0) return min(sumA, sumB);
    if (n < 0) return INT_MIN;

    if (dp[n][k] != -1) return dp[n][k];

    int take = helper(n - 1, a, b, sumA + a[n], sumB + b[n], k - 1, dp);
    int notTake = helper(n - 1, a, b, sumA, sumB, k, dp);

    return dp[n][k] = max(take, notTake);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int k;
    cin >> k;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    cout << helper(n - 1, a, b, 0, 0, k, dp) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}