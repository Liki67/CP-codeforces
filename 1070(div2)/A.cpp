#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int maxi=arr[0],cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i]>=maxi){
            maxi=arr[i];
            cnt++;
        }
    }
    cout<<n-cnt<<endl;
        

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
