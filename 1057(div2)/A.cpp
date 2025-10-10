#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    sort(b.begin(),b.end());
    int cnt=1;
    for(int i=1;i<n;i++){
        if(b[i]>b[i-1])cnt++;
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
