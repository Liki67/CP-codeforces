#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<long long>L(n),R(n);
    long long ans=LLONG_MIN;
    L[0]=a[0];
    for(int i=1;i<n;i++){
        L[i]=max(L[i-1]+(long long)a[i],(long long)a[i]);
    }
    R[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        R[i]=max(R[i+1]+(long long)a[i],(long long)a[i]);
    }
    
    if(k%2){
        for(int i=0;i<n;i++){
            ans=max(ans,L[i]+R[i]-a[i]+b[i]);
        }
        cout<<ans<<endl;
    }else{
        ans=*max_element(L.begin(),L.end());
        cout<<ans<<endl;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
