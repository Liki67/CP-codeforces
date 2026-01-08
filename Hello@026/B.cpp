#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

void solve() {
    
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];maxi=max(maxi,a[i]);
    }

    vector<int>consist(maxi+1,0);

    for(int r=0;r<n;r++){
        consist[a[r]]++;
    }

    int deletions=n-k+1;
    for(int i=0;i<=maxi;i++){
        if(consist[i] >1 &&deletions>=consist[i]){
            deletions-=consist[i]-1;
            consist[i]=1;
        }else if(consist[i] ==0){
            cout<<i<<endl;return;
        }
    }
    
    for(int i=maxi;i>=0;i--){
        if(deletions>0){
            deletions--;
        }if(deletions==0){
            if(consist[i]>1)
                cout<<i+1<<endl;
            else
                cout<<i<<endl;
            return;
        }
    }

    
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