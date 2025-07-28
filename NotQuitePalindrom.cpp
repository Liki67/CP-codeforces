#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = n - cnt0;

    int minGood = max(cnt0, cnt1) - n/2;
    int maxGood = cnt0/2 + cnt1/2;

    if (k >= minGood && k <= maxGood && (k - minGood) % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}