#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// Trie node class
class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

// Trie class
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (curr->children[index] == nullptr)
                return false;
            curr = curr->children[index];
        }
        return (curr != nullptr && curr->isEndOfWord);
    }

    // Delete a word from the trie
    bool deleteWord(TrieNode *curr, string word, int depth)
    {
        if (curr == nullptr)
            return false;

        // Base case
        if (depth == word.length())
        {
            if (curr->isEndOfWord)
                curr->isEndOfWord = false;
            return (isEmpty(curr));
        }

        // Recursive case
        int index = word[depth] - 'a';
        if (deleteWord(curr->children[index], word, depth + 1))
        {
            delete curr->children[index];
            curr->children[index] = nullptr;
            return (isEmpty(curr) && !curr->isEndOfWord);
        }
        return false;
    }

    // Helper function to check if a node has any children
    bool isEmpty(TrieNode *node)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i] != nullptr)
                return false;
        }
        return true;
    }
};

int main()
{
    Trie trie;

    // Insert words into the trie
    trie.insert("adam");
    trie.insert("barbara");
    trie.insert("charles");

    // Search for a word in the trie
    if (trie.search("barbara"))
        cout << "Found barbara in the trie!" << endl;

    // Delete a word from the trie
    trie.deleteWord(trie.root, "barbara", 0);
    if (!trie.search("barbara"))
        cout << "Successfully deleted barbara from the trie!" << endl;

    if (trie.search("barbara"))
        cout << "Found barbara in the trie!" << endl;
    else
        cout << "barbara not found!" << endl;
    return 0;
}
