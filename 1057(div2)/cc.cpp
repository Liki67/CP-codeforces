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
    sort(unpaired.begin(), unpaired.end());
    if(n == 3 ){
        if(cnt > unpaired[0]){
            cnt+=unpaired[0];cout<<cnt<<endl;return;
        }else{
            cout<<0<<endl;
        }
        return;
    }
    

    int m=unpaired.size()-1;
    int j=m;long long prev=0;
    while(j>=0){
        if(unpaired[j]>=cnt){
            j--;
        }else{
            cnt+=unpaired[j];prev=unpaired[j];break;
        }
    }j=m;
    if(prev!=0){
        while(j>=0){
        if(unpaired[j]>=cnt || unpaired[j] == prev){
            j--;
        }else{
            cnt+=unpaired[j];break;
        }
    }
    }cout<<cnt<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}