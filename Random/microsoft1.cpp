#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
void solve(int n, vector<int> & arr){
    vector<int>left(n,0),right(n,0);
    for(int i=n-2;i>=0;i--) {
        if(arr[i]<=arr[i+1])
            right[i]=1+right[i+1];
    }
    for(int i=1;i<n;i++) {
        if(arr[i]<=arr[i-1]){
            left[i]=1+left[i-1];
        }
    }int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,left[i]+right[i]);
    }cout<<ans<<endl;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        solve(n,arr);
    }
    return 0;
}
