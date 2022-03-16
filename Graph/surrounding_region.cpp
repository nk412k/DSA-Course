#include<bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &g,int i,int j){
    
    g[i][j]='*';
    int x[]={0,0,1,-1};
    int y[]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int a=i+x[i];
        int b=j+y[i];
        if(a>=0 && a<g.size() && b>=0 && b<g[0].size() && g[a][b]=='O')
        change(g,a,b);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(g[i][j]=='O')
                change(g,i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='O')
            g[i][j]='X';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='*')
                g[i][j]='O';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}