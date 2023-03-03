#include "trie.h"

Trie::Trie() {
    this->root;
}

int Trie::index(char* letter) {
    return *letter - 'a';
}

void Trie::add_word(string key) {
    assert(key.length() == 5);
    _add(this->root,key,0);
}

void Trie::_add(Node* node, string word, int index) {
    if(index != word.length()) {
        int letter_index = Trie::index(&word[index]);
        if(node->children[letter_index] == nullptr) {
            Node* new_node = new Node();
            node->children[letter_index] = new_node;
        }
    }

    if(index == word.length() - 1) {
        int letter_index = Trie::index(&word[index]);
        node->children[letter_index]->some_flag2 = true;
        node->children[letter_index]->letter = word;
    }
    int letter_index = Trie::index(&word[index]);
    this->_add(node->children[letter_index],word,index+1);
    return;
}
