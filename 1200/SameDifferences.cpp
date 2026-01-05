#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<map>
#include<unordered_map>


using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=0;
    unordered_map<int,int> freq;

    for(int i=1;i<=n;i++){
        cnt+=freq[a[i]-i];
        freq[a[i]-i]++;
    }
    cout<<cnt<<endl;
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}