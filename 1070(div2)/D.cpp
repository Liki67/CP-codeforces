#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>ver(n+1,0);
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>ver[i];
        sum+=ver[i];
    }
    vector<vector<int>>edges(m,vector<int>(2));
    vector<vector<int>>radj(n+1);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
        radj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<long long>fib(sum+1,0);
    fib[0]=1,fib[1]=1;
    for(int i=2;i<=sum;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    long long ans=0;
    long long mod=998244353;
    for(int i=1;i<=n;i++){
        int cnt=0;
        if(fib[ver[i]]!=0){
            for(int j=0;j<radj[i].size();j++){
                if(fib[ver[radj[i][j]]]!=0){
                    cnt++;
                }
                
            }
        }
        ans=(ans+(cnt*(cnt-1)/2)%mod)%mod;
        
    }
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
