#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[20][4][2];
string S;

long long solve(int pos, int count, bool tight) {
    if (pos == S.length()) {
        return 1;
    }

    if (dp[pos][count][tight] != -1) {
        return dp[pos][count][tight];
    }

    long long ans = 0;
    int upper_bound = tight ? (S[pos] - '0') : 9;

    for (int digit = 0; digit <= upper_bound; ++digit) {
        if (count + (digit != 0) > 3) {
            continue;
        }
        bool new_tight = tight && (digit == upper_bound);
        ans += solve(pos + 1, count + (digit != 0), new_tight);
    }

    return dp[pos][count][tight] = ans;
}

long long countClassy(long long n) {
    S = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        
        long long ans = countClassy(r) - countClassy(l - 1);
        cout << ans << "\n";
    }

    return 0;
}