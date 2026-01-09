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
#include<queue>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    vector<int>diff(n);
    int maxDiff=INT_MIN;
    for(int i=0;i<n;i++){
        diff[i]=a[i]-b[i];
        maxDiff=max(maxDiff,diff[i]);
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(diff[i]==maxDiff)
            ans.push_back(i+1);
    }
    
    cout<<ans.size()<<"\n";
    for(int x:ans)cout<<x<<" ";
    cout<<"\n";
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