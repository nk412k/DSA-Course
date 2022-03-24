#include<bits/stdc++.h>
using namespace std;

const int N=1e4+3;
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
void update(int node,int st,int en,int idx){
    if(st==en){
        if(seg[node]==0){
            seg[node]=1;
            a[node]=1;
        }
        else{
            seg[node]=0;
            a[node]=0;
        }
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx);
    }
    else{
        update(2*node +1,mid+1,en,idx);
    }
    seg[node]=seg[2*node]+seg[2*node +1];
}
int query(int node,int st,int en,int k){
    if(st==en){
        return st;
    }
    int mid=(st+en)/2;
    if(k<seg[2*node]){
        return query(2*node,st,mid,k);
    }
    else{
        return query(2*node +1,mid+1,en,k-seg[2*node]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t==1){
            int idx;
            cin>>idx;
            update(1,0,n-1,idx);
        }
        else if (t==2){
            int k;
            cin>>k;
            cout<<query(1,0,n-1,k);
        }
    }
}