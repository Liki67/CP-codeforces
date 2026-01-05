#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;
void solve() {
    int n,k;
    cin>>n>>k;
    int floor=n/2;
    k--;
    cout<<(k+(n%2)*k/floor)%n+1<<endl;
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