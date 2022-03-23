#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> bit;

int query(int i){
    int ans=0;
    while(i>0){
        ans+=bit[i];
        i-=i & (-i);
    }
    return ans;
}

void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+= idx & (-idx);
    }
}

int main(){    
    cin>>n;
    bit= vector<int> (n+1);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }

    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;        
        
        if(t==1){
            int l,r;
            cin>>l>>r;
            int ans=query(r)-query(l-1);
            cout<<ans<<endl;
        }
        else if(t==2){
            int idx,val;
            cin>>idx>>val;
            update(idx,-a[idx]);
            a[idx]=val;
            update(idx,val);
        }
    }
}