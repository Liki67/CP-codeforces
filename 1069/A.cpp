#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void solve(){
    int n;
    cin>>n;
    unordered_set<int>ump;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(!ump.count(x)){
            ump.insert(x);
        }      
    }
    int k=ump.size();
    while(true) {
        if(ump.count(k)){
            cout<<k<<endl;
            return;
        }k++;
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
