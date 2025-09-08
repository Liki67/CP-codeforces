#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
vector<int>ans,res;
int checK(int a,int b, int x) {
    if( a == x ){
        if(ans.empty() || res.size()>ans.size()){
            ans.clear();
            ans.assign(res.begin(),res.end());
        }
        return 0;
    }
    if(a%2 != 0 && a!=x)return INT_MAX;
    res.push_back(2);
    int take1=checK(a-(a/2),b+(a/2),x);
    res.pop_back();
    res.push_back(1);
    int take2=checK(a+(b/2),b-(b/2),x);
    res.pop_back();
    if(take1 == INT_MAX && take2== INT_MAX)return INT_MAX;
    return 1+min(take1,take2);
}
void solve(){
    int k,x;
    cin>>k>>x;
    if(pow(2,k) == x){
        cout<<0<<endl;
        cout<<endl;
    }else{
        ans.clear();res.clear();
        int a=pow(2,k),b=pow(2,k);
        cout<<checK(a,b,x)<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }cout<<endl;
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
