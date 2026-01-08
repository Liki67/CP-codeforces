#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

void solve() {
    
    int n;
    cin>>n;
    vector<int>a(n);
    bool allZ=true,allO=true;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i] == 1)
            allZ=false;
        else
            allO=false;
    }
    bool corner=false;
    if(a[0]||a[n-1])corner=true;
    if(allZ){
        cout<<"Bob\n";
    }else if(allO){
        cout<<"Alice\n";
    }
    else if(corner)
        cout<<"Alice\n";
    else {
        cout<<"Bob\n";
    }
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