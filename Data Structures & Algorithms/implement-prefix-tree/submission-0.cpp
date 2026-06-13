struct TrieNode{
   unordered_map<char,TrieNode*>mp;
   bool isend=false;
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root=new TrieNode();
    }
    void insert(string word) {
        TrieNode *cur=root;
        for(int i=0;i<word.size();i++){
            if(!cur->mp.count(word[i])){
                cur->mp[word[i]]=new TrieNode();
            }
            cur=cur->mp[word[i]];
        }
        cur->isend=true;
    }
    
    bool search(string word) {
        TrieNode *cur=root;
        for(int i=0;i<word.size();i++){
            if(!cur->mp.count(word[i])){
                return false;
            }
            cur=cur->mp[word[i]];
        }
        return cur->isend;
    }
    bool startsWith(string prefix) {
        TrieNode *cur=root;
        for(int i=0;i<prefix.size();i++){
            if(!cur->mp.count(prefix[i])){
                return false;
            }
            cur=cur->mp[prefix[i]];
        }
        return true;
    }
};