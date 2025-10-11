#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_set<long long> s;
    long long cnt = 0; // sum of all pairs
    for (int i = 0; i < n; i++) {
        if (s.count(a[i])) {
            s.erase(a[i]);
            cnt += 2 * a[i]; // add both sticks
        } else {
            s.insert(a[i]);
        }
    }

    if (cnt == 0) {
        cout << 0 << endl;
        return;
    }
    // Convert unpaired sticks to vector and sort
    vector<long long> unpaired(s.begin(), s.end());
    
    

    long long m=unpaired.size();
    long long ans=0;

    for (int x : unpaired) {
            if (cnt > x) {
                ans = max(ans, cnt + x);
            }
        }
    for(int j=1;j<(int)unpaired.size();j++){
        if(unpaired[j-1]+cnt>unpaired[j]){
            ans=max(ans,cnt+unpaired[j-1]+unpaired[j]);
        }
        }
    for(auto it:s){
        if(cnt/2-it>0){
            ans=max(ans,cnt+it);
        }
    }
    cout<<ans<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}