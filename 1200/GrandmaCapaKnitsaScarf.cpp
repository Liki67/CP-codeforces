#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

int solveWithChar(string s, char c){
    int l = 0, r = s.size() - 1;
    int cnt = 0;

    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else if (s[l] == c) {
            l++;
            cnt++;
        } else if (s[r] == c) {
            r--;
            cnt++;
        } else {
            return INT_MAX;
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    
    int l = 0, r = n - 1;

    while (l < r && s[l] == s[r]) {
        l++;
        r--;
    }

    if (l >= r) {
        cout << 0 << endl;
        return;
    }

    int ans = min(
        solveWithChar(s, s[l]),
        solveWithChar(s, s[r])
    );

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}