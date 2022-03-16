#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool flag=true;
void color(int i,int curr){
    if(col[i]!=-1 && col[i]!=curr){
            flag=false;
            return;
    }
    col[i]=curr;
    if(vis[i])
    return;
    vis[i]=1;
    for(auto el:adj[i]){        
        color(el,curr xor 1);    
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
    vis=vector<bool> (n,0);
    col=vector<int> (n,-1);    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            color(i,0);
        }
    }
    if(flag){
        cout<<"graph is bipartite";
    }
    else
    cout<<"graph is not bipartite";
}