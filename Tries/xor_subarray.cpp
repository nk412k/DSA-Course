#include<bits/stdc++.h>
using namespace std;

struct Trienode{
    Trienode *next[2];
    Trienode(){
        next[0]=NULL;
        next[1]=NULL;
    }
};
Trienode* buildtrie(vector<int> a){
    Trienode *root=new Trienode();
    for(auto el:a){
        Trienode *it=root;
        for(int i=31;i>=0;i--){
            int bit=(el>>i)&1;
            if(it->next[bit]==NULL)
            it->next[bit]=new Trienode();
            it=it->next[bit];
        }
    }
    return root;
}

int xorsub(vector<int> a,Trienode *root){
    int res=0;
    for(auto el:a){
        Trienode *it=root;
        int curr=0;
        for(int i=31;i>=0;i--){
            int bit=(el>>i)&1? 0:1;
            if(it->next[bit]){
                curr<<=1;
                curr|=1;
                it=it->next[bit];
            }
            else{
                curr<<=1;
                it=it->next[bit xor 1];
            }                        
        }
        res=max(res,curr);
    }
    return res;
}
int main(){
    vector<int> a={3,10,5,15,2};
    Trienode* root=buildtrie(a);
    cout<<xorsub(a,root);
}