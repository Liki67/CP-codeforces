#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;
char nonRepeating(string s) {
    int i=0;
    unordered_map<char,int>ump;
    for(auto c:s){
        ump[c]++;
    }
    for(auto it:ump){
        if(it.second == 1)
            return it.first;
    }return -1;
}
int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;
    char c=nonRepeating(s);
    cout<<c;
    return 0;
}