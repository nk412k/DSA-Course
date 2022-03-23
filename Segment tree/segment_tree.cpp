#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
vector<int> seg(4*N);
vector<int> a(N);

void build(int node,int l,int r){
    if(l==r){
        seg[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node +1,mid+1,r);
    seg[node]=seg[2*node]+seg[2*node +1];
}

int main(){
    int n;
    cin>>n;    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);

    for(int i=1;i<=2*n-1;i++){
        cout<<seg[i]<<" ";
    }
}