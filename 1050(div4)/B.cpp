#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<int>a(n),b(m);;
        for(int i=0;i<n;i++)
            cin>>a[i];  
        for(int j=0;j<m;j++)
            cin>>b[j];
        int ans=n+m;
        cout<<ans<<endl;
    }
    return 0;
}
