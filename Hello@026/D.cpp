#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<queue>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>visit(n+1,0);
    vector<vector<int>> level_parent(n + 1);
    queue<int> q;

    q.push(1);
    visit[1]=1;
    level_parent[1].push_back(-1);
    int lvl=2;
    while (!q.empty()) {
        int s=q.size();
        while(s--){
            int curr = q.front();
            q.pop(); 
            for (int neighbor : adj[curr]) {
                if(visit[neighbor])continue;
                level_parent[lvl].push_back(curr);
                visit[neighbor]=1;
                q.push(neighbor);
            }
        }lvl++;
    }
    int ans=0;
    for(int i=0;i<level_parent.size();i++) {
        if (level_parent[i].empty()) continue;
        int cnt=level_parent[i].size();
        int first=level_parent[i][0];
        bool all=true;
        for(auto p:level_parent[i]){
            if(p!=first){
                all=false;
                break;
            }
        }
        if(i>0 && all)
            ans=max(ans,cnt+1);
        else 
            ans=max(ans,cnt);
    }
    cout<<ans<<endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}