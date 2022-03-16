#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=1000;
vector<vector<int>> adj[N];
vector<int> dis(N);
vector<int> parent(N); 
vector<bool> vis(N,0);
int cost=0;
void primmst(int src){
    for(int i=0;i<n;i++)
    dis[i]=10000;
    set<vector<int>> s;
    dis[src]=0;
    s.insert({0,src});
    
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        int a=x[1];
        int b=parent[a];
        int w=x[0];
        vis[a]=1;
        cost+=w;
        cout<<a<<" "<<b<<" "<<w<<endl;
        for(auto it:adj[a]){
            if(vis[it[0]])
            continue;
            if(dis[it[0]]>it[1]){
                s.erase({dis[it[0]],it[0]});
                dis[it[0]]=it[1];
                s.insert({dis[it[0]],it[0]});
                parent[it[0]]=a;
            }
        }         
    }     
}

int main(){
    
    cin>>n>>m;    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }    
    primmst(0);
    cout<<cost;
}