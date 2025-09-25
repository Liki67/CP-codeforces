#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long>a(n);
    for(long long i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int maxi=0;
    for(long long i=0;i<n;i+=2){
        maxi=max(maxi,(int)(a[i+1]-a[i]));
    }cout<<maxi<<endl;
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
