#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    int cur_min = 1, cur_max = n;

    while (l <= r) {
        if (a[l] == cur_min) {
            l++;
            cur_min++;
        } else if (a[l] == cur_max) {
            l++;
            cur_max--;
        } else if (a[r] == cur_min) {
            r--;
            cur_min++;
        } else if (a[r] == cur_max) {
            r--;
            cur_max--;
        } else {
            cout << l << " " << r << endl;
            return;
        }
    }

    cout << -1 << endl;
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
