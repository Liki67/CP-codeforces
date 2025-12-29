#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<set>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int total_elements = 1 << n; 
    vector<int> result;
    vector<bool> used(total_elements, false);

    
    for (int k = n; k >= 0; k--) {
        
        int mask = (1 << k) - 1; 
        int step = (1 << k);     

        for (int i = mask; i < total_elements; i += step) {
            if (!used[i]) {
                used[i] = true;
                result.push_back(i);
            }
        }
    }

    for (int i = 0; i < total_elements; i++) {
        cout << result[i] << (i == total_elements - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}