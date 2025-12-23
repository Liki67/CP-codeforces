#include<iostream>
#include<vector>
#include<string>
using namespace std;
int helper(int n,vector<int>& a,vector<int>& b,int sumA,int sumB,int k){
    if(k == 0){
        return min(sumA,sumB);
    }
    if(n < 0){
        return INT_MIN;
    }
    int take=helper(n-1,a,b,sumA+a[n],sumB+b[n],k-1);
    int notTake=helper(n-1,a,b,sumA,sumB,k);
    return max(take,notTake);

}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int k;
    cin>>k;
    cout<<helper(n-1,a,b,0,0,k);


    

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
