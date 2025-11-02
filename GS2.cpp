#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
vector<int>helper(int n, vector<string>&arr){
    vector<int>ans;
    vector<bool>visit(n,false);int cntQ=0;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        if(visit[i])continue;
        if(arr[i][0]=='Q'){ // Assuming arr[i] is like "Q123" where 123 is the index
            visit[i]=true;
            int idx=stoi(arr[i].substr(1)); // Corrected: stoi needs a string, and we need to extract the number part
            int minSkill=INT_MAX;
            for(int j=0;j<n;j++){
                if(visit[j])continue; // Corrected: check visit[j] not visit[i]
                if(j == idx )continue;
                pq.push({stoi(arr[j].substr(1)),j}); // Corrected: stoi needs a string, and we need to extract the number part
            }

        }
    
    }
        
}
void solve(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    helper(n,arr);
    
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
