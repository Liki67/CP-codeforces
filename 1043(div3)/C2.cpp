#include<iostream>
#include<string>
#include<cmath>
using namespace std;

long long check(int n,int k) {
    long long totcost=0;
    while(n>0){
            long long cost,num;
            for(int i=0;i<n;i++){
                if(pow(3,i)> n)
                    break;
                num=pow(3,i);
                cost=pow(3,i+1)+i*(pow(3,i-1));
           }
           n-=num;
           totcost+=cost;
    }return totcost;         
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        int k;cin>>k;
        long long ans=check(n,k);
        cout<<ans<<endl;
    }
    return 0;
}