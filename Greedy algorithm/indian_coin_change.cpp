#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={2000,500,200,100,50,20,10,5,2,1};
    int m=432;
    int c=0;
    for(int i=0;i<10;i++){
        c+=m/a[i];
        m-= (m/a[i])*a[i];
    }
    cout<<c<<endl;
}