#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

bool findPossi(int n, int mid, string &s, int x, int y, int hx, int hy) {
    vector<int> px(n+1,0), py(n+1,0);
    for(int i=0;i<n;i++){
        px[i+1]=px[i];
        py[i+1]=py[i];
        if(s[i]=='U') py[i+1]++;
        else if(s[i]=='D') py[i+1]--;
        else if(s[i]=='L') px[i+1]--;
        else px[i+1]++;
    }
    for(int i=0;i+mid<=n;i++){
        int nx = px[i] + (px[n]-px[i+mid]);
        int ny = py[i] + (py[n]-py[i+mid]);
        int dist = abs(x-nx)+abs(y-ny);
        if(dist <= mid && (dist%2==mid%2)) return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string s(n,' ');
    cin>>s;
    int x,y;
    cin>>x>>y;
    int ans=-1;
    if(n< abs(x)+abs(y))cout<<"-1";
    else{
        int hx=0,hy=0;
        for(int i=0;i<n;i++){
            if(s[i]=='U')hy+=1;
            else if(s[i]=='D')hy-=1;
            else if(s[i]=='L')hx-=1;
            else hx+=1;
        }
        int l=0,r=n;
        while(l<=r){
            int m=(l+r)/2;
            if(findPossi(n,m,s,x,y,hx,hy)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }cout<<ans<<endl;
    }

    return 0;
}
