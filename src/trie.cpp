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
