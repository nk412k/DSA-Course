#include<bits/stdc++.h>
using namespace std;

int main(){
    int ladder;
    cin>>ladder;
    map<int,int> lad;
    for(int i=0;i<ladder;i++){
        int x,y;
        cin>>x>>y;
        lad[x]=y;
    }
    int snake;
    cin>>snake;
    map<int,int> snak;
    for(int i=0;i<snake;i++){
        int x,y;
        cin>>x>>y;
        snak[x]=y;
    }
    int moves=0;
    queue<int> q;
    q.push(1);
    bool flag=false;
    vector<bool> vis(101,0);
    while(!q.empty() && !flag){
        int sz=q.size();
        while(sz--){
            int t=q.front();
            q.pop();
            vis[t]=1;
            for(int d=1;d<=6;d++){
                if(t+d==100){
                    flag=true;
                }
                else if(t+d<=100 && lad[t+d] && !vis[d+t]){
                    vis[lad[d+t]]=1;
                    if(lad[d+t]==100)
                    flag=true;
                    q.push(lad[d+t]);
                }
                else if(t+d<=100 && snak[t+d] && !vis[d+t]){
                    vis[snak[d+t]]=1;
                    if(snak[d+t]==100)
                    flag=1;
                    q.push(snak[d+t]);
                }
                else if(d+t<=100 && !lad[d+t] && !snak[d+t] && !vis[d+t]){
                    vis[d+t]=1;                    
                    q.push(d+t);
                }
            }
        }
        moves++;    

    }
    if(flag)
    cout<<moves;
    else
    cout<<"cannot reached";
}