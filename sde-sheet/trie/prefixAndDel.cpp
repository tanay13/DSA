#include <bits/stdc++.h>

class Node
{
public:
    Node *links[26];
    int ew = 0;
    int cp = 0;

    void create(char c)
    {
        links[c - 'a'] = new Node();
    }

    Node *next(char c)
    {
        return links[c - 'a'];
    }

    bool contains(char c)
    {
        if (links[c - 'a'] == NULL)
            return false;
        return true;
    }
};

class Trie
{

public:
    Node *n;

    Trie()
    {
        // Write your code here.
        n = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *root = n;

        for (int i = 0; i < word.size(); i++)
        {

            if (!root->contains(word[i]))
            {
                root->create(word[i]);
            }
            root = root->next(word[i]);
            root->cp = root->cp + 1;
        }
        root->ew = root->ew + 1;
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *root = n;
        for (int i = 0; i < word.size(); i++)
        {
            if (!root->contains(word[i]))
                return 0;
            root = root->next(word[i]);
        }
        return root->ew;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *root = n;
        for (int i = 0; i < word.size(); i++)
        {
            if (!root->contains(word[i]))
                return 0;
            root = root->next(word[i]);
        }
        return root->cp;
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *root = n;
        for (int i = 0; i < word.size(); i++)
        {
            if (!root->contains(word[i]))
                return;
            root = root->next(word[i]);
            root->cp = root->cp - 1;
        }
        root->ew = root->ew - 1;
        return;
    }
};
