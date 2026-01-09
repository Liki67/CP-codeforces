#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    long long current_sum = 0;
    bool found = false;    

    set<long long> seen_sums;
    seen_sums.insert(0); 

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        
        if (i % 2 == 0) current_sum += x;
        else current_sum -= x;

        if (!found && seen_sums.count(current_sum)) {
            found = true;
        }
        seen_sums.insert(current_sum);
    }

    if (found) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}