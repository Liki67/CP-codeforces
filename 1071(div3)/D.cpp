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

    int total_elements = 1 << n; // This is 2^n
    vector<int> result;
    vector<bool> used(total_elements, false);

    // We iterate from k = n down to 0. 
    // k represents the number of trailing '1's we are looking for.
    for (int k = n; k >= 0; k--) {
        
        int mask = (1 << k) - 1; // Creates a binary number with k ones (e.g., k=3 -> 111)
        int step = (1 << k);     // How much to jump to keep those trailing bits the same

        // Start from the smallest number that fits the mask
        for (int i = mask; i < total_elements; i += step) {
            if (!used[i]) {
                used[i] = true;
                result.push_back(i);
            }
        }
    }

    // Print the resulting permutation
    for (int i = 0; i < total_elements; i++) {
        cout << result[i] << (i == total_elements - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Speed up input and output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}