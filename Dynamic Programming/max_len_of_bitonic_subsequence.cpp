#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> inc(n+1,1);
    vector<int> dec(n+1,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
            inc[i]=max(inc[i],1+inc[j]);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j])
            dec[i]=max(dec[i],1+dec[j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,inc[i]+dec[i]-1);
    }
    cout<<ans;
}