class Trie {
public:
    struct node{
        bool is_end;
        node *son[26];
        node(){
            is_end=false;
            for(int i=0;i<26;i++) son[i]=NULL;
        }
    }*root;

    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        auto p=root;
        for(auto ch:word){
            int u=ch-'a';
            if(!p->son[u]) p->son[u]=new node();
            p=p->son[u];
        }
        p->is_end=true;
    }
    
    bool search(string word) {
        auto p=root;
        for(auto ch:word){
            int u=ch-'a';
            if(!p->son[u]) return false;
            p=p->son[u];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        auto p=root;
        for(auto ch:prefix){
            int u=ch-'a';
            if(!p->son[u]) return false;
            p=p->son[u];
        }
        return true;
    }
};









