#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(1000);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n,0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();
        for(auto el:adj[temp]){
            if(!vis[el]){
                q.push(el);
                vis[el]=1;
            }
        }
    }
}