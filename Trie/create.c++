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
};
int main()
{
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }
    cout << "Searching for 'the': " << (trie.search("the") ? "Found" : "Not Found") << endl;
    return 0;
}