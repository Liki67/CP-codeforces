#include<iostream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    ll cur_max = 0;
    ll cur_min = 0;

    for (int i = 0; i < n; i++) {
        ll red_max = cur_max - a[i];
        ll red_min = cur_min - a[i];

        ll blue_max = b[i] - cur_min;
        ll blue_min = b[i] - cur_max;

        cur_max = max(red_max, blue_max);
        cur_min = min(red_min, blue_min);
    }

    cout << cur_max << endl;
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
