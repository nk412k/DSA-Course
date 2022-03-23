#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
vector<int> seg(4*N);
vector<int> a(N);
void build(int node,int st,int en){
    if(st==en){
        seg[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node +1,mid+1,en);
    seg[node]=seg[2*node] + seg[2*node +1];
}
int query(int node,int st,int en,int l,int r){
    if(st>r || en<l){
        return 0;
    }
    if(l<=st && en<=r){
        return seg[node];
    }
    int mid=(st+en)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,en,l,r);
    return q1+q2;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=query(1,0,n-1,l,r);
        cout<<ans<<endl;
    }
}