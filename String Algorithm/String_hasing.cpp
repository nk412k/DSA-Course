#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7,N=1000;
vector<int> power(N,0);
int calculate_hash(string s){
    int ans=1;
    for(int i=0;i<s.size();i++){
        ans=(ans+ (s[i]-'a' + 1)*power[i])%mod;
    }
    return ans;
}
int main(){
    power[0]=1;
    for(int i=1;i<N;i++){
        power[i]=power[i-1]*31;
    }
    vector<string> a={"aa","ab","aa","b","cc","aa"};
    vector<int> hashes;
    for(auto el:a){
        hashes.push_back(calculate_hash(el));
    }
    int c=0;
    sort(hashes.begin(),hashes.end());
    for(int i=0;i<hashes.size();i++){
        //cout<<hashes[i]<<endl;
        if(i==0 || hashes[i]!=hashes[i-1])
            c++;
    }
    cout<<c;
}