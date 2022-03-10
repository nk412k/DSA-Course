#include<bits/stdc++.h>
using namespace std;

void kmost_frequent_element(int a[],int n,int k){
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    vector<pair<int,int>> v;
    map<int,int> ::iterator it;
    
    for(it=m.begin();it!=m.end();it++){
        v.push_back({it->first,it->second});
    }
    sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    });
    for(int i=0;i<k;i++){
        cout<<v[i].first<<"->"<<v[i].second<<endl;
    }
}
int main(){
    int a[]={1,2,2,2,3,3};
    int n=6;
    int k=2;
    kmost_frequent_element(a,n,k);
}