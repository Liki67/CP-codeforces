#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>>points(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++) {
            cin>>points[i][j];
        }
    }
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];
    });
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout<<points[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}
