#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;
int dfs(int node, int parent, vector<vector<int>>& adj, int& diameter) {
    int max1 = 0, max2 = 0;
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        int height = 1 + dfs(neighbor, node, adj, diameter);
        if (height > max1) {
            max2 = max1;
            max1 = height;
        } else if (height > max2) {
            max2 = height;
        }
    }
    diameter = max(diameter, 1 + max1 + max2);
    return max1;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int diameter=0;
    dfs(1, -1, adj, diameter);
    if(diameter<=2){
        cout<<0<<endl;
    }else{
        cout<<diameter-3<<endl; 
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
