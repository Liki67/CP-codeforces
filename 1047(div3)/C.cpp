#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long ans = -1;

        if (b % 2 != 0) {
            if (a % 2 != 0) {
                ans = a * b + 1;
            } else {
                ans = -1;
            }
        } else {
            if (a % 2 == 0) {
                long long s1 = a + b;
                long long s2 = a * (b / 2) + 2;
                ans = max(s1, s2);
            } else {
                if (b % 4 == 0) {
                    long long s1 = a * 2 + b / 2;
                    long long s2 = a * (b / 2) + 2;
                    ans = max(s1, s2);
                } else {
                    ans = -1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}