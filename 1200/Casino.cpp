#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>

using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<long long>>a(m,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[j][i];
        }
    }
    for(int i=0;i<m;i++){
        sort(a[i].begin(),a[i].end());
    }
    long long ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans-=(a[i][j]*(n-j-1));
            ans+=(a[i][j]*j);
        }
    }
    cout<<ans<<endl;
   
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