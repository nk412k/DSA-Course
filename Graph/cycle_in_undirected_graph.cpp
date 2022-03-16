#include<bits/stdc++.h>
using namespace std;

bool iscycle(int i,vector<vector<int>> &adj,vector<bool> &vis,int p){
    vis[i]=1;
    for(auto el:adj[i]){
        if(el!=p){
            if(vis[el])
            return true;
            if(!vis[el] && iscycle(el,adj,vis,i))
            return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i] && iscycle(i,adj,vis,-1)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"cycle present";
    }
    else 
    cout<<"cycle not present";
}