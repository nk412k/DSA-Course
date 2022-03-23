#include<bits/stdc++.h>
using namespace std;
vector<int> bit;
int n;
int query(int idx){
    int ans=0;
    while(idx>0){
        ans+=bit[idx];
        idx-= idx&(-idx);
    }
}

void update(int idx,int val){
    
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx &(-idx);
    }
}
int main(){
    
    cin>>n;
    bit=vector<int> (n+10,0);
    while(n--){
        int l,r,val;
        cin>>l>>r>>val;        
        update(l,val);
        update(r+1,-val);
    }
    int q;
    cin>>q;
    while(q--){
        int w;
        cin>>w;
        cout<<query(w);
    }
}