#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    node* trie;
    Trie(){
        trie=new node();        
    }
    void insert(string s){
        node* it=trie;
        for(int i=0;i<s.size();i++){
            if(it->next[s[i]-'a']==NULL)
            it->next[s[i]-'a']=new node();
            it=it->next[s[i]-'a'];
        }
        it->end=true;
    }
    void find(string s){
        node* it=trie;
        for(int i=0;i<s.size();i++){
            if(it->next[s[i]-'a']==NULL){
                cout<<"no suggestion\n";
                insert(s);
                return;
            }
            it=it->next[s[i]-'a'];
        }
        vector<string> v;
        printall(v,it,"");
        for(auto el:v){
            cout<<s<<el<<endl;
        }
    }
    void printall(vector<string> &v,node *it,string s){
        if(it==NULL)
        return;
        if(it->end)
        v.push_back(s);
        for(int i=0;i<26;i++){
            if(it->next[i]){
                printall(v,it->next[i],s+char('a'+i));                
            }            
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Trie *root=new Trie;
    for(int i=0;i<n;i++){
        root->insert(a[i]);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        root->find(s);
    }
}