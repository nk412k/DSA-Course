#include<bits/stdc++.h>
using namespace std;

int mod=1e6+4;
int power(int a,int n){
    if(n==0)
    return 1;
    
    int p=(power(a,n/2))%mod;
    if(p&1)
    return (((p*p)%mod)*a)%mod;
    else
    return (p*p)%mod;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<power(a,n);
}