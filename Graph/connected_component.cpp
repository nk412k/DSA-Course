#include<bits/stdc++.h>
using namespace std;

int get_comp(int idx,vector<vector<int>> &adj,vector<bool> &vis){
    if(vis[idx])
    return 0;
    vis[idx]=1;
    int ans=1;
    for(auto i:adj[idx]){
        if(!vis[i]){
            ans+=get_comp(i,adj,vis);            
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n,0);
    vector<int> component;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            component.push_back(get_comp(i,adj,vis));
        }
    }
    for(auto el:component){
        cout<<el<<" ";
    }
}