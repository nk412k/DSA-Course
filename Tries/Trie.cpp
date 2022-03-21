#include<bits/stdc++.h>
using namespace std;

class Tries{
    public:
    class node{
        public:
            bool end;
            node* next[26];
            node(){
                for(int i=0;i<26;i++){
                    next[i]=NULL;                    
                }
                end=false;
            }
    };
    node* tries;
    Tries(){
        tries=new node();
    }
    void insert(string s){
        node* it=tries;
        for(int i=0;i<s.size();i++){
            if(it->next[s[i]-'a']==NULL)
            it->next[s[i]-'a']=new node;
            it=it->next[s[i]-'a'];
        }
        it->end=true;
    }
    bool search(string s){
        node* it=tries;
        for(int i=0;i<s.size();i++){
            if(it->next[s[i]-'a']==NULL){                
                return 0;
            }
            it=it->next[s[i]-'a'];
        }
        return it->end;
    }
};
int main(){
    vector<string> a={"ram","mohit","piyush"};
    Tries *root=new Tries;
    for(auto el:a){
        root->insert(el);
    }
    if(root->search("mohit"))
    cout<<"mohit is present in the tries"<<endl;
    else
    cout<<"Not present"<<endl;
    if(root->search("sam"))
    cout<<"sam is present in the tries"<<endl;
    else
    cout<<"Not present";
}