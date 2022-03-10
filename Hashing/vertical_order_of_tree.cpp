#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> m;
struct node{
    int data;
    node *left,*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void vertical_order(node* root,int d){
    if(root==NULL)
    return;
    m[d].push_back(root->data);
    vertical_order(root->left,d-1);
    vertical_order(root->right,d+1);
}
int main(){
    node *root=new node(10);
    root->left=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(5);
    root->right=new node(15);
    vertical_order(root,0);
    map<int,vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++){        
        for(int j=0;j<(it->second).size();j++){
            cout<<(it->second)[j]<<" ";
        }
        cout<<endl;
    }
}