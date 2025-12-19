#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s = a[0];

    for (int i = 1; i < n; i++) {
        string front = a[i] + s;
        string back = s + a[i];
        
        if (front < back) {
            s = front;
        } else {
            s = back;
        }
    }
    
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}