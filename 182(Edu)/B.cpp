#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++)
        cin>>p[i];
    int minzero=INT_MAX,maxzero=INT_MIN,minmis=INT_MAX,maxmis=INT_MIN;
    int cnt_zero=0,misplace=0;
    for(int i=0;i<n;i++){
        if(p[i]==0){
            minzero=min(minzero,i);
            maxzero=max(maxzero,i);
            cnt_zero++;
        }
        else if( p[i] != i+1){
            minmis=min(minmis,i);
            maxmis=max(maxmis,i);
            misplace++;
        }
    }
    if(cnt_zero>1 && misplace>=1){
        minzero=min(minzero,minmis);
        maxzero=max(maxzero,maxmis);
        cout<<maxzero-minzero+1<<endl;
    }else if(cnt_zero==1 && misplace==0){
        cout<<0<<endl;
    }
    else if(misplace >= 1 && cnt_zero==1){
        cout<<maxmis-minmis+1<<endl;
    }else{
        minzero=min(minzero,minmis);
        maxzero=max(maxzero,maxmis);
        cout<<maxzero-minzero+1<<endl;
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
