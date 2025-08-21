#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> check(long long n) {
    vector<long long> ans;
    if (n == 0) return ans;
    long long mod = 10;
    while (mod < n) {
        long long divisor = 1 + mod;
        if (n % divisor == 0) {
            long long a = n / divisor;
            ans.push_back(a);
        }
        mod *= 10;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> ans = check(n);
        if (ans.empty()) {
            cout << 0 << endl;
        } else {
            sort(ans.begin(), ans.end());
            for (long long a : ans) {
                cout << a << " ";
            }
            cout << endl;
        }
    }
    return 0;
}