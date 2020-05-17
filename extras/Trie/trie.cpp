#include<bits/stdc++.h>
using namespace std;
class Trie {
    
    struct TrieNode{
       
        char val;
        int count;
        int endsHere;
        TrieNode *child[26];
       
    };
    
    TrieNode *root;
    
    TrieNode* createNode(int index){
        
        TrieNode* newnode = new TrieNode;
        newnode->val = 'a' + index;
        newnode->count = newnode->endsHere = 0;
        
        for(int i = 0; i<26; i++)
            newnode->child[i] = NULL;
        
        return newnode;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = createNode('/'-'a');
    }
    
   
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode* curr = root;
        int index;
        
        for(int i = 0; word[i] != '\0'; i++){
            
            index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = createNode(index);
            
            curr->child[index]->count += 1;
            
            curr = curr->child[index];
            
            
        }
        
        curr->endsHere += 1;
       
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode* curr = root;
        int index;
        
        for(int i = 0; word[i] != '\0'; i++){
            
            index = word[i] - 'a';
            if(curr->child[index] == NULL)
                return false;
            
            curr = curr->child[index];
        }
        
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;
        int index;
        
        for(int i = 0; prefix[i] != '\0'; i++){
            
            index = prefix[i] - 'a';
            if(curr->child[index] == NULL)
                return false;
            
            curr = curr->child[index];
        }
        
        return true;
    }
};
int main() {

    Trie *trie = new Trie();
    trie->insert("apple");
    cout<<trie->search("apple")<<endl;   // returns true
    cout<<trie->search("app")<<endl;     // returns false
    cout<<trie->startsWith("app")<<endl; // returns true
    trie->insert("app");   
    cout<<trie->search("app")<<endl;   
    return 0;
}