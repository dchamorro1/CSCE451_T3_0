#include "trie.h"

Trie::Trie() {
    this->root = new Node();
}

int Trie::index(char* letter) {
    return *letter - 'a';
}

void Trie::add_word(string key) {
    assert(key.length() == 5);
    _add(this->root,key,0);
}

void Trie::_add(Node* node, string word, int index) {
    // Only do stuff if not at the end of the word
    if(index != word.length()) { 
        int letter_index = Trie::index(&word[index]);
        // if the next node is missing for the letter, add it
        if(node->children[letter_index] == nullptr) { 
            Node* new_node = new Node();
            node->children[letter_index] = new_node;
        }
        // If at the end of the word
        if(index == word.length() - 1) { 
            letter_index = Trie::index(&word[index]);
            // Set leaf to true
            node->children[letter_index]->end_of_word= true; 
            // Add word to the leaf
            node->children[letter_index]->letter = word;
        }
        letter_index = Trie::index(&word[index]);
        this->_add(node->children[letter_index],word,index+1);
    }
    return;
}

vector<string> Trie::find_wild(string wild) {
    vector<string> results;
    _wild(this->root, wild, 0, results);
    return results;
}

void Trie::_wild(Node* node, string wild, size_t index, vector<string> &potential_words) {
    // Not how wordle.out works.
    // reimplemented
    if(node == nullptr) {
        return;
    }
    if(index == wild.size()) {
        if(node->end_of_word) { // add only if end of the wildcard and the node is a leaf
            potential_words.push_back(node->letter);
        }
        return;
    }
    if(wild[index] == '*') { // check all the children if it is a wild card
        for(auto child : node->children) {
            _wild(child, wild, index+1, potential_words);
        }

    } else {
        size_t node_i = Trie::index(&wild[index]);
        if(0 <= node_i && node_i < 26) { // only check child if its a-z
            Node* child = node->children[node_i];
            _wild(child,wild,index+1,potential_words);
        }
    }
}