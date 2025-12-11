#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>ver(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>ver[i];
    }
    vector<vector<int>>edges(m,vector<int>(2));
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
        adj[edges[i][0]].push_back(edges[i][1]);
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
