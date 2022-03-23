#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
vector<pair<int,int>> seg(4*N);
vector<int> a(N);
void build(int node,int st,int en){
    if(st==en){
        seg[node].first=a[st];
        seg[node].second=1;
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node +1,mid+1,en);
    if(seg[2*node].first < seg[2*node +1].first){
        seg[node].first=seg[2*node].first;
        seg[node].second=seg[2*node].second;
    }
    else if(seg[2*node].first > seg[2*node +1].first){
        seg[node].first=seg[2*node +1].first;
        seg[node].second=seg[2*node +1].second;
    }
    else{
        seg[node].first=seg[2*node].first;
        seg[node].second=seg[2*node +1].second +seg[2*node].second;
    }
}
pair<int,int> query(int node,int st,int en,int l,int r){
    if(st>r || en<l){
        return {INT_MAX,-1};
    }
    if(l<=st && en<=r){
        return seg[node];
    }
    int mid=(st+en)/2;
    pair<int,int> q1=query(2*node,st,mid,l,r);
    pair<int,int> q2=query(2*node+1,mid+1,en,l,r);
    pair<int,int> q;
    if(q1.first<q2.first){
        q=q1;         
    }
    else if(q1.first>q2.first){
        q=q2;       
    }
    else{
        q.first=q1.first;
        q.second=q1.second+q2.second;
    }
    return q;
}

void update(int node,int st,int en,int idx,int val){
    if(st==en){
        seg[node].first=val; 
        seg[node].second=1;       
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid)
        update(2*node,st,mid,idx,val);
    else    
        update(2*node+1,mid+1,en,idx,val);
    if(seg[2*node].first < seg[2*node +1].first){
        seg[node].first=seg[2*node].first;
        seg[node].second=seg[2*node].second;
    }
    else if(seg[2*node].first > seg[2*node +1].first){
        seg[node].first=seg[2*node +1].first;
        seg[node].second=seg[2*node +1].second;
    }
    else{
        seg[node].first=seg[2*node].first;
        seg[node].second=seg[2*node +1].second +seg[2*node].second;
    }    
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
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;
            pair<int,int> ans=query(1,0,n-1,l,r-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
        if(t==2){
            int idx,val;
            cin>>idx>>val;
            a[idx]=val;
            update(1,0,n-1,idx,val);            
        }
    }
}