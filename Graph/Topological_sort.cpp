#include<bits/stdc++.h>
using namespace std;

#define N 1000
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for(auto el:indeg){
        if(el==0)
        q.push(el);
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto el:adj[temp]){
            indeg[el]--;
            if(indeg[el]==0)
            q.push(el);
        }
    }

}