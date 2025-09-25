#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);set<int>s;
    int miss=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i] == k)miss++;
        s.insert(a[i]);
    }int cnt=0;
    for(int i=0;i<k;i++){
        if(s.find(i)==s.end()){
            cnt++;
        }
    }
    cout<<max(miss,cnt)<<endl;
    
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
