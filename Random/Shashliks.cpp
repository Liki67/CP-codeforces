#include <iostream>
#include <algorithm>
using namespace std;

int findShashlikhs(int k, int a, int b, int x, int y) {
    int cnt = 0;
    if (x < y) {
        cnt = max((k - a + x) / x, 0);
        k -= cnt * x;
        cnt += max((k - b + y) / y, 0);
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        int cnt = max(
            findShashlikhs(k, a, b, x, y),
            findShashlikhs(k, b, a, y, x)
        );
        cout << cnt << endl;
    }
    return 0;
}