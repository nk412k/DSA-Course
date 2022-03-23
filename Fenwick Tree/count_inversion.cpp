#include<bits/stdc++.h>
using namespace std;

vector<int> bit;
int n;
int getsum(int idx){
    int ans=0;
    while(idx>0){
        ans+=bit[idx];
        idx-=idx &(-idx);
    }
    return ans;
}
void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
}
int main(){
    cin>>n;
    vector<int> a(n);
    bit=vector<int> (n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];       
    }
    vector<int> temp=a;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++){
        a[i]=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin()+1;
    }
    int c=0;
    for(int i=n-1;i>=0;i--){
        c+=getsum(a[i]-1);
        update(1,a[i]);
    }
    cout<<c;
}
