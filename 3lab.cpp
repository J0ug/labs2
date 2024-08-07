//trie-tree
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    // Хранит указатели на дочерние вершины для каждого алфавитного символа
    TrieNode* children[26];
    // Флаг, указывающий, является ли вершина конечной (целым словом)
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    // Вставляет слово в префиксное дерево
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    //Вывод дереева
    void printTrie(TrieNode* node, string prefix) {
        if (node == nullptr) {
            return;
        }
        if (node->isEndOfWord) {
            cout << prefix << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char c = 'a' + i;
                printTrie(node->children[i], prefix + c);
            }
        }
    }
    //Вспомогательная функция для подсчета различных букв
    int countDL(string word) {
        set<char> dLetters(word.begin(), word.end());
        return dLetters.size();
    }
    //Основная фнукция которая решает задачц
    void MaxDL(TrieNode* node, string prefix) {
        static int maxDLetters = 0;
        static vector<string> wordsMaxDL;
        if (node == nullptr) {
            return;
        }
        if (node->isEndOfWord) {
            int difLet = countDL(prefix);
            if (difLet > maxDLetters) {
                maxDLetters = difLet;
                wordsMaxDL.clear();
                wordsMaxDL.push_back(prefix);
            } else if (difLet == maxDLetters) {
                wordsMaxDL.push_back(prefix);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char c = 'a' + i;
                MaxDL(node->children[i], prefix + c);
            }
        }
        if (prefix == "") {
            cout << "Слова с наибольшим количеством различных букв (" << maxDLetters << "):" << endl;
            for (string word : wordsMaxDL) {
                cout << word << endl;
            }
        }
    }
};
int main() {
    Trie trie;
    trie.insert("trie");
    trie.insert("tree");
    trie.insert("auto");
    trie.insert("milk");
    //trie.insert("cream");
    trie.insert("erte");
    //trie.insert("horse");
    trie.MaxDL(trie.root, "");
}
