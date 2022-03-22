#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7,N=100;
vector<int> power(N,0);

int main(){
    power[0]=1;
    for(int i=1;i<N;i++){
        power[i]=(power[i-1]*31)%mod;
    }
    string s="apna";
    string s1="na";
    int t=s.size(),t2=s1.size();
    vector<long long> hash(t+1,0);
    for(int i=0;i<t;i++){
        hash[i+1]=(hash[i]+ (s[i]-'a' +1)*power[i])%mod;
    }
    long long h=0;
    for(int i=0;i<t2;i++){
        h=(h+ (s1[i]-'a'+1)*power[i])%mod;
    }
    for(int i=0;i<t-t2+1;i++){
        long long curr=(hash[i+t2]-hash[i]+mod)%mod;
        if(curr==(h*power[i])%mod)
        cout<<i<<endl;
    }
}