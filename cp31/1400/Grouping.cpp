#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int cnt=0;
    int s=INT_MAX,t=INT_MAX;
    
    for(int k=0;k<n;k++) {
        if(s>t)swap(s,t);
        if(arr[k] <= s){
            s=arr[k];
        }
        else if(arr[k] <= t){
            t=arr[k];
            
        }else{
            s=arr[k];
            cnt++;
        }
    }cout<<cnt<<endl;


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
