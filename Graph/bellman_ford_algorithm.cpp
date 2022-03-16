#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph.push_back({x,y,w});
    }
    const int inf=1000;
    vector<int> d(n,inf);
    int src;
    cin>>src;
    d[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto x:graph){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            d[v]=min(d[v],w+d[u]);
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]<inf)
        cout<<d[i]<<" ";
        else
        cout<<-1<<" ";
    }

}