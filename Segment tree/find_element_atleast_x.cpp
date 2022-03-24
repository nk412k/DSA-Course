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
    seg[node]=max(seg[2*node],seg[2*node +1]);
}
int query(int node,int st,int en,int l,int r){
    if(st>r || en<l){
        return INT_MIN;
    }
    if(l<=st && en<=r){
        return seg[node];
    }
    int mid=(st+en)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,en,l,r);
    return max(q1,q2);
}

void update(int node,int st,int en,int idx,int val){
    if(st==en){
        seg[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid)
        update(2*node,st,mid,idx,val);
    else    
        update(2*node+1,mid+1,en,idx,val);
    seg[node]=max(seg[2*node],seg[2*node+1]);    
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    
    
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int idx,val;
            cin>>idx>>val;
            a[idx]=val;
            update(1,0,n-1,idx,val);
        }
        if(t==2){            
            int x;
            cin>>x;
            int st=0,en=n-1;
            int ans=n;
            while(st<=en){
                int mid=(st+en)/2;
                
                if(x>query(1,0,n-1,st,mid)){
                    st=mid+1;
                }
                else{
                    en=mid-1;
                    ans=min(ans,mid);
                }
            }
            if(ans==n)
            cout<<-1<<endl;
            else
            cout<<ans<<endl;
        }
    }
}