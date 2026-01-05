#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;
void solve() {
    int n;
    cin>>n;

    vector<pair<long long,int>>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
		a[i].second = i + 1; 
    }
    sort(a.begin(),a.end());

    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i].first*a[j].first>=2*n)break;
            if(a[i].first*a[j].first == a[i].second+a[j].second )cnt++;
        }
    }    
    cout<<cnt<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}