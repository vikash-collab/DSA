#include<iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char val){
            this->value = val;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

//insertion
void insertWord(TrieNode* root, string word){
    // cout<<"Recieved word: "<< word <<" for insertion "<<endl;
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        // present
        child = root->children[index];
    }
    else{
        // absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    //recursion
    insertWord(child, word.substr(1)); // substr(1) => before(love) ,then now send (ove)
}

bool searchWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        // present or found
        child = root->children[index];
    }
    else{
        // not found
        return false;
    }

    //Bakki recursion    
    bool recursionKaAns = searchWord(child, word.substr(1));
    return recursionKaAns;
}

void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    // 1 case mera
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        //present
        child = root->children[index];
    }
    else{
        //not present
        return;
    }
    
    // bakki recursion tera
    deleteWord(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "cdm");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "bat");
    insertWord(root, "car");
    insertWord(root, "cat");
    insertWord(root, "lov");

    cout<<"Insertion Done"<<endl;
    bool found = searchWord(root, "loved");
    if(found){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }
    
 
    deleteWord(root, "loved");

    if(searchWord(root, "loved")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }


    return 0;
}