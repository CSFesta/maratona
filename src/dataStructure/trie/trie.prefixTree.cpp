#include "../template.h"

struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
};

struct Trie {
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

/*
Criar Nodo: Trie nome-variavel
inserir: nome-variavel.insert(string)
verificar se existe uma string: nome-variavel.search(string)
verificar se existe um prefixo/inicio da string: nome-variavel.startWith(string)
*/