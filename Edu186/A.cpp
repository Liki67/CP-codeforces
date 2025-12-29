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

    string s;
    cin>>s;

    string newY="2026",oldY="2025";
    if(s.find(newY) != string::npos)cout<<0<<endl;
    else if(s.find(oldY) != string::npos)cout<<1<<endl;
    else cout<<<<endl;

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