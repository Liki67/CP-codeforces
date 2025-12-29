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
    for(int i=0;i<n;i++)cin>>a[i];

    int r=n-1,l=n-2;
    while(a[r] == a[l]) {
        l--;r--;
    }
    int ignore=0;
    if(a[l] >-a[r])ignore=r;
    else ignore=l;

    l=0,r=1;
    long long sum=0;
    while(r<n){
        if(l==ignore){
            sum-=a[r];
            r++;
        }else if(r==ignore){
            sum+=a[l];
            l=r;
            r++;
        }else if(a[l]>){
            sum+=a[l];
            l=r;
            r++;
        }else{
            sum-=a[r];
            r++;
        }
    }cout<<sum<<endl;
    
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