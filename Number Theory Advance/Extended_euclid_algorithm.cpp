#include<bits/stdc++.h>
using namespace std;

struct triplet{
    int gcd;
    int x;
    int y;
};
triplet extendedeuclid(int a ,int b){
    if(b==0){
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
    }
    triplet smallans=extendedeuclid(b,a%b);
    triplet ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x - (a/b)*smallans.y;
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    triplet ans=extendedeuclid(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y;
}