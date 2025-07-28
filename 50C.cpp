#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int countNonZeroDigits(ll n, vector<int>& dp) {
    if(dp[n]!=-1)return dp[n];
    int count = 0;
    while (n) {

        if (n % 10 != 0) count++;
        n /= 10;
    }
    return dp[n]=count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll L, R;
        cin >> L >> R;
        int classy = 0;
        vector<int>dp(R-L+1,-1);
        for (ll i = L; i <= R; ++i) {
            if (countNonZeroDigits(i,dp) <= 3) {
                classy++;
            }
        }

        cout << classy << endl;
    }

    return 0;
}