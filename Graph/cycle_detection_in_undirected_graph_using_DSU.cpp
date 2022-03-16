#include<bits/stdc++.h>
using namespace std;

const int N=1000;

vector<int> parent(N);
vector<int> siz(N);
void make_set(int v){
    parent[v]=v;
    siz[v]=1;
}
int find_set(int v){
    if(v==parent[v])
    return v;
    return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(siz[a]<siz[b]){
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
    }
}
int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edge;    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edge.push_back({x,y});
    }
    
    bool cycle=false;
    for(auto i:edge){
        int u=i[0];
        int v=i[1];
        int a=find_set(u);
        int b=find_set(v);
        if(a==b)
        cycle=true;
        else{
            union_set(u,v);
        }
    }
    if(cycle)
        cout<<"cycle is present";
    else
    cout<<"cycle is not present";
}