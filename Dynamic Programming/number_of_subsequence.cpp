#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int e=1,a=0,ab=0,abc=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a')
        a+=e;
        else if(s[i]=='b')
        ab+=a;
        else if(s[i]=='c')
        abc+=ab;
        else if(s[i]=='?'){
            abc=3*abc + ab;
            ab=3*ab +a;
            a=3*a + e;
            e=3*e;
        }
    }
    cout<<abc;
}
