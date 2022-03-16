#include<bits/stdc++.h>
using namespace std;

bool iscycle(int i,vector<vector<int>> adj,vector<bool> vis,vector<int> stack){
    stack[i]=1;
    if(!vis[i]){
        vis[i]=1;
        for(auto el:adj[i]){
        if(stack[el]==1)
            return true;
                 
        if(!vis[el] && iscycle(el,adj,vis,stack))
            return true;
    }
        
    }
    stack[i]=0;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> vis(n,0);
    bool cycle=false;
    vector<int> stack(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i] && iscycle(i,adj,vis,stack))
            cycle=true;
    }
    if(cycle)
    cout<<"cycle is present";
    else
    cout<<"cycle is not present";
}