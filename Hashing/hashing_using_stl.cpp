#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> m;
    m[3]=7;
    m[1]=5;
    m[6]=3;
    map<int,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    unordered_map<int,int> um;
    um[3]=7;
    um[1]=5;
    um[6]=3;
    unordered_map<int,int> :: iterator it2;
    for(it2=um.begin();it2!=um.end();it2++){
        cout<<it2->first<<" "<<it2->second<<endl;
    }
}