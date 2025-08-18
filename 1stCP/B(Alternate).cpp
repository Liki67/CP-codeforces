#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

int main() {

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>ans;
        for(int i=0;i<n/2;i++){
            ans.push_back(-1);
            ans.push_back(3);
        }
        if(n%2 == 0)ans.back()=2;
        else ans.push_back(-1);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }cout<<endl;
    }
    return 0;
}