#include<bits/stdc++.h>
using namespace std;

int find_zero_subarray(int a[],int n){
    int presum[n];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        presum[i]=sum;
    }
    map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++){
        m[presum[i]]++;
    }
    map<int,int> ::iterator it;
    for(it=m.begin();it!=m.end();it++){
        int f=it->second;
        ans+=f*(f-1)/2;
        if(it->first==0)
        ans+=it->second;
    }
    return ans;
}

int main(){
    int a[]={1,-1,1,-1};
    int n=4;
    cout<<find_zero_subarray(a,n);
}