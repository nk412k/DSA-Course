#include<bits/stdc++.h>
using namespace std;

struct triplet{
    int x,y,gcd;
};

triplet extented_euclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
    }
    triplet smallans=extented_euclid(b,a%b);
    triplet ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x -(a/b)*smallans.y;
}

int multi_modulo(int a,int m){
    triplet ans=extented_euclid(a,m);
    return ans.x;
}

int main(){
    int a,m;
    cin>>a>>m;
    cout<<multi_modulo(a,m);
}