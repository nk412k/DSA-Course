#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string s){
    int l=s.size();
    vector<int> p(l,0);
    
    for(int i=1;i<l;i++){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]){
            j=p[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        p[i]=j;
    }
    return p;
}

int main(){
    string s1="na";
    vector<int> prefix=prefix_func(s1);
    string s2="apna";
    int pos=-1,i=0,j=0;
    while(i<s2.size()){
        if(s2[i]==s1[j]){
            i++;
            j++;
        }
        else{
            if(j!=0)
            j=prefix[j-1];
            else
            i++;
        }
        if(j==s1.size()){
            pos=i-s1.size();
            break;
        }

    }
    cout<<pos;
}