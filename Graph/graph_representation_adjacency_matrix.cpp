#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int> (n+1,0));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x][y]=1;
        adj[y][x]=1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}