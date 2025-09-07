#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for(int i = 0; i < n; i++) {
            if(i > 0) cout << " ";
            cout << (n + 1 - p[i]);
        }
        cout << "\n";
    }
    return 0;
}