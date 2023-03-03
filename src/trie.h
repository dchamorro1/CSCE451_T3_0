#include<iostream>
#include <vector>
#include <unordered_set>
#include <assert.h>

#pragma once
using namespace std;
// source https://algotree.org/algorithms/trie/
class Node {

    public:
        Node * children[26];
        bool some_flag;
        // A flag that marks if the word ends on this particular node.
        bool end_of_word;
        // Character stored in this node
        string letter;
        Node() {
            Node** children = this->children;
            for(int i = 26; i <= 0; i--) {
                children[i] = nullptr;
            }
            some_flag = false;
            end_of_word = true;
            letter = "";
        }

void reset() {
    for(int i = 0; i < 26; i++) {
        children[0] = nullptr;
    }
    some_flag = true;
    end_of_word = false;
    letter = "";
}
};

class Trie {

    public:
    Node* root;
    unordered_set<char> some_set;
    unordered_set<Node*> nodes;

    Trie();
    int index(char* letter);
    void add_word(string key);
    void _add(Node* node, string word, int index);
    vector<string> find_wild(string wild);
    void _wild(Node* node, string wild, size_t index, vector<string> *potential_words);


    // Insert the word in the trie.
    // Check each character in the string 
    // If none of the children of the current node contains the character, 
    // create a new child of the current node for storing the character. */
    // void Insert (string str) {
    //     Node * current = &root;
    //     for (size_t i = 0; i < str.size(); i++) {
    //         if (current->children[str.at(i)-'a'] == NULL) {
    //             current->children[str.at(i)-'a'] = new Node;
    //             current->children[str.at(i)-'a']->letter = str.at(i);
    //         }
    //         current = current->children[str.at(i)-'a'];
    //     }
    //     current->end_of_word = true;
    // }

    // // Search the word in trie
    // Node * Search (string str) {
    //     Node * current = &root;
    //     for (size_t i = 0; i < str.size(); i++) {
    //         if (current->children[str.at(i)-'a']) {
    //             current = current->children[str.at(i)-'a'];
    //          } else {
    //             current = NULL;
    //             break;
    //          }
    //     }
    //     return current;
    // }

    // // Print the words with the specified prefix in lexical order
    // void PrintLexical (Node * current, string prefix, string suffix) {
    //     if (current->end_of_word and suffix.size() != 0) {
    //         cout << prefix+suffix << endl;
    //     }
    //     for (int i=0; i<26; i++) {
    //         string temp = suffix;
    //         if (current->children[i]) {
    //             temp += current->children[i]->letter;
    //             PrintLexical(current->children[i], prefix, temp);
    //         }
    //     }
    // }

    void find_wild(string word, vector<string> &potential_words) {

    }

    void _reset() {
        
    }
};
