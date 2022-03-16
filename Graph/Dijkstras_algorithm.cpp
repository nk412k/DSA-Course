#include<bits/stdc++.h>
using namespace std;

int main(){    
    int n,m;
    cin>>n>>m;
    const int inf=10000;
    vector<vector<pair<int,int>>> edge(n+1);   
    vector<int> dis(n+1,inf);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edge[x].push_back({y,w});
        edge[y].push_back({x,w});
    }
    int src;
    cin>>src;
    set<pair<int,int>> s;
    dis[src]=0;
    s.insert({0,src});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        for(auto i:edge[x.second]){
            if(dis[i.first]>dis[x.second]+i.second){
                s.erase({dis[i.first],i.first});
                dis[i.first]=dis[x.second]+i.second;
                s.insert({dis[i.first],i.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i]<inf)
        cout<<dis[i]<<" ";
        else
        cout<<-1<<" ";
    }
}