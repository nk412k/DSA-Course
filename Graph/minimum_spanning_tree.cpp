#include<bits/stdc++.h>
using namespace std;

const int N=10000;
vector<int> parent(N);
vector<int> siz(N);

void make_set(int i){
    parent[i]=i;
    siz[i]=1;
}
int find_set(int a){
    if(parent[a]==a)
    return a;
    return parent[a]=find_set(parent[a]);
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
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({z,x,y});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    for(auto el:edges){
        int x=el[1];
        int y=el[2];
        int z=el[0];
        int a=find_set(x);
        int b=find_set(y);
        if(a==b)
        continue;
        else{
            cout<<x<<" "<<y<<endl;
            union_set(a,b);
            cost+=z;
        }
    }
    cout<<cost;
}