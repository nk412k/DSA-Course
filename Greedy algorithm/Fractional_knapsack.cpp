#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> x,pair<int,int> y){
    double r1=(double) x.first / x.second;
    double r2=(double) y.first / y.second;
    return r1>r2;
}
int main(){
    int n,w;
    cin>>n;
    vector<pair<int,int>> v;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compare);
    int val=0;
    cin>>w;
    for(int i=0;i<n;i++){
        if(v[i].second<=w){
            val+=v[i].first;
            w-=v[i].second;
            continue;
        }        
        double vw=(double) v[i].first/v[i].second;
        val+=vw*w;
        w=0;
        break;
    }
    cout<<val;
}