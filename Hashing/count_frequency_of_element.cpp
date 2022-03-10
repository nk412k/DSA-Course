#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> freq;
    int a[]={1,2,2,2,4,6};
    int n=6;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    map<int,int> :: iterator it;
    for(it=freq.begin();it!=freq.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}