#include<bits/stdc++.h>
using namespace std;

int main(){
    int inf=10000;
    vector<vector<int>> g{
        {0,5,inf,10},
        {inf,0,3,inf},
        {inf,inf,0,1},
        {inf,inf,inf,0}
    };
    int n=g.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]=min(g[i][j],(g[i][k]+g[k][j]));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]<inf)
            cout<<g[i][j]<<" ";
            else
            cout<<"inf"<<" ";
        }
        cout<<endl;
    }
}