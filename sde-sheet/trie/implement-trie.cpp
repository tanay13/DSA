/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node
{
public:
    Node *links[26];
    bool flag = false;

    bool containsChar(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void createNode(char ch)
    {
        links[ch - 'a'] = new Node();
    }

    Node *nextNode(char ch)
    {
        return links[ch - 'a'];
    }
    void endWord()
    {
        flag = true;
    }

    bool checkEnd()
    {
        return flag;
    }
};

class Trie
{

private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {

        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsChar(word[i]))
            {
                node->createNode(word[i]);
            }
            node = node->nextNode(word[i]);
        }
        node->endWord();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {

        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsChar(word[i]))
            {
                node = node->nextNode(word[i]);
            }
            else
                return false;
        }
        return node->checkEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {

        Node *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (node->containsChar(prefix[i]))
            {
                node = node->nextNode(prefix[i]);
            }
            else
                return false;
        }
        return true;
    }
};