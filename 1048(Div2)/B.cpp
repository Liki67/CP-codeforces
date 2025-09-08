#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int helper(int n, int m, vector<int>&a){
    if(n == 1)return m*a[0];
    if(m == 1)return a[n-1];
    sort(a.begin(),a.end());
    vector<int>b(a.begin(),a.end());


   int i=m%n;int sum=0;
   for(int j=0;j<m;j++) {
        sum+=a[(n-i)%n];
        a[(n-i)%n]=b[(n-i)%n];
        for(int k=0;k<n;k++){
            if(k == (n-i)%n)continue;
            else
                a[k]+=b[k];
        }i = (i - 1 + n) % n;
   }return sum;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        cout<<helper(n,m,a)<<endl;
    }
    return 0;
}
