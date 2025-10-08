#include<iostream>
#include<vector>
#include<string>
using namespace std;
int get(vector<int>&a){
    if(a.empty())return 0;
    int pos=a.size()/2,val=0;
    for(int i=0;i<a.size();i++){
        val+=abs(a[pos]-a[i])-abs(pos-i);
    }
    cout<<val<<a[0]<<endl;
    return val;
}
void solve(){
    int n;cin>>n;
    vector<int>a,b;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c == 'a')a.push_back(i);
        else b.push_back(i);
    }
    cout<<min(get(a),get(b))<<endl;

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
