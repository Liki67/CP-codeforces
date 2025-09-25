#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int neg=0,zeros=0;
    for(int i=0;i<n;i++){
        if(a[i] == -1)neg++;
        else if(a[i] == 0)zeros++;
    }
    neg=neg%2;
    if(neg != 0 && zeros != 0)cout<<neg*2+zeros<<endl;
    else if( neg == 0)cout<<zeros<<endl;
    else cout<<neg*2<<endl;

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
