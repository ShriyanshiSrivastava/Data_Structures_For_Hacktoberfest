// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    // isTerminal is true if the node represents
    // end of a word
    bool isTerminal;
    Node *child[26];
    // trie node
    Node()
    {
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

// If not present, add key into trie
// If the key is prefix of trie node, just
// marks leaf node
void add(string word, Node *trie)
{
    int n = word.size();
    //Every character of the input key is inserted as an individual Trie node.
    for (int i = 0; i < n; i++)
    {
        if (trie->child[word[i] - 'A'] == NULL)
        {
            trie->child[word[i] - 'A'] = new Node();
        }
        trie = trie->child[word[i] - 'A'];
    }
    // mark last node as leaf
    trie->isTerminal = true;
}

// Returns true if key presents in trie, else
// false
bool search(string word, Node *trie)
{
    int n = word.size();
    //we only compare the characters and move down
    for (int i = 0; i < n; i++)
    {
        if (trie->child[word[i] - 'A'] == NULL)
            return false;
        trie = trie->child[word[i] - 'A'];
    }
    // if isTerminal field of the last node is true, then the key exists in the trie. 
    // If search terminates without examining all the characters of the key, 
    // then key is not present in the trie.
    return trie->isTerminal;
}

int main()
{
    // Input keys
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");

    Node *root = new Node();
    // Construct trie
    for (int i = 0; i < dict.size(); i++)
    {
        add(dict[i], root);
    }

    // Search for different keys
    cout << search("ARE", root) << endl;
    cout << search("NO", root) << endl;
    cout << search("NEWS", root) << endl;
    cout << search("WIN", root) << endl;
    cout << search("ABC", root) << endl;
    cout << search("AER", root) << endl;
    cout << search("XYZ", root) << endl;

    return 0;
}