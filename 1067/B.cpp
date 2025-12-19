#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(2*n);
    unordered_map<int,int>ump;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
        ump[arr[i]]++;
    }
    int odd=0,even=0,oe=0;
    for(auto it:ump){
        if(it.second %2 ==1){
            odd++;
        }else if(it.second %4 ) {
            oe++;
        }
        else{
            even++;
        }
    }
    int ans= odd+2*oe+2*even;
    if((even&1)&& odd ==0)ans-=2;
    cout<<ans<<endl;

    
    
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
