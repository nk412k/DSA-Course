#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1000);
vector<bool> vis(1000,0);     
void dsf(int node){
    vis[node]=1;
    cout<<node<<" ";
    for(auto el:adj[node]){
        if(!vis[el])
        dsf(el);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
      
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dsf(1);

}