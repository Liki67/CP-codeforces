#include<iostream>
#include<vector>
#include<string>
using namespace std;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<bool> used(n + 1, false);
    vector<int> zeros;
    vector<int> missing;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == 0) {
            zeros.push_back(i); 
        } else {
            used[p[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            missing.push_back(i);
        }
    }
    
    sort(missing.rbegin(), missing.rend());
    
    for (int i = 0; i < zeros.size(); i++) {
        p[zeros[i]] = missing[i];
    }
    
    int l = n + 1, r = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    
    if (l > r) {
        cout << 0 << "\n";
        return;
    }
    
    bool valid = true;
    for (int i = 1; i < l; i++) {
        if (p[i] != i) {
            valid = false;
            break;
        }
    }
    for (int i = r + 1; i <= n; i++) {
        if (p[i] != i) {
            valid = false;
            break;
        }
    }
    vector<int> subsegment(p.begin() + l, p.begin() + r + 1);
    sort(subsegment.begin(), subsegment.end());
    for (int i = 0; i < subsegment.size(); i++) {
        if (subsegment[i] != l + i) {
            valid = false;
            break;
        }
    }
    
    if (valid) {
        cout << r - l + 1 << "\n";
    } else {
        
        cout << n << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}