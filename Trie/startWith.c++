#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Node
{
public:
    unordered_map<char, Node *> children;
    bool endofWord;

    Node()
    {
        endofWord = false;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endofWord = true;
    }
    bool search(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                return false; // character not found
            }
            temp = temp->children[key[i]];
        }
        return temp->endofWord; // return true if end of word is reached
    }
    bool startWith(string prefix){
        Node* temp=root;

        for(int i=0;i<prefix.size();i++){
            if(temp->children[prefix[i]]){
                temp = temp->children[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<string> words = {"mango","apple","app","women"};
    Trie trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    cout<<trie.startWith("app")<<endl; // Output: 1 (true)
    
    return 0;
}