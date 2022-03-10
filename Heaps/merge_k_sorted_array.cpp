#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n);    
    for(int i=0;i<n;i++){
        int s1;
        cin>>s1;
        a[i]=vector<int> (s1);
        for(int j=0;j<s1;j++){
            cin>>a[i][j];            
        }        
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> idx(n,0);
    for(int i=0;i<n;i++){
        pq.push({a[i][0],i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,int> temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        if(idx[temp.second]+1<a[temp.second].size()){
            idx[temp.second]++;
            pq.push({a[temp.second][idx[temp.second]],temp.second});
        }
    }
    for(auto el:ans){
        cout<<el<<" ";
    }
}