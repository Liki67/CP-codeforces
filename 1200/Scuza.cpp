#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<climits>
#include<set>
#include<map>
using namespace std;
bool check(vector<long long>&prefix,int k,int mid){
    if(prefix[mid]<=k)return true;
    return false;
}

void solve(){
    int n,q;
    cin>>n>>q;

    vector<int>a(n+1),k(q+1);

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=q;i++)cin>>k[i];

    vector<long long>prefix(n+1),prefixMax(n+1);
    prefix[0]=0;
    prefixMax[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+(long long)a[i];
        prefixMax[i]=max(prefixMax[i-1],(long long)a[i]);
    }
    
    for(int i=1;i<=q;i++){
        int ind=upper_bound(prefixMax.begin(),prefixMax.end(),k[i])-prefixMax.begin();
        long long ans=prefix[ind-1];
        cout<<ans<<" ";
    }
    cout<<endl;

    
    
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
