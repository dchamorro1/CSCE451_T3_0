#include <iostream>
#include <fstream>
#include "trie.hpp"

using namespace std;

class Trie {
    public:

    TrieNode root;

        vector<string> find_wild(string word) {
        vector<string> res;
        _find_wild(&root, word, 0, res);
        return res;
    }

    void _find_wild(TrieNode* curr, string word, size_t index, vector<string> &res) {
        if(curr->end_of_word) {
            // add word
        } else {
            char c = word.at(index);
            if(c == '*') {
                // add all the words, in trie note
            } else {
                // go to next code
            }
        }
    }


    void find_wild(string wild){
        string myString;
        Trie *myTrie;



        _wild(myTrie, myString, wild, 0);

    }

    int index(Trie *this, char *letter)
    {
        return *letter + -97;
    }

    bool validate(Node *node){
        bool reached_end;
        bool bVar1;
        char *character;
        long lVar2;
        long in_FS_OFFSET;
        unordered_set<char> begin;
        unordered_set<char> end;
        long canary;

        begin = unordered_set<char>::begin();
        end = unordered_set<char>::end();

        do{
            reached_end begin | end;
            if(reached_end){
                bVar1 = true;

                while(lVar2 == -1){
                    bVar1 = false;
                    
                    if (canary != 0x28){
                        return 1;
                    }
                    return bVar1;
                }

                character = (char *)param_1->letter;
                lVar2 = index(this, character);

                if(lVar2 == -1){
                    bVar1 = false;
                }
                else{
                    param_1 = param_1->children[lVar2];
                }
            }
        } while (true)
    }

    void _wild(Node **nodes, string *query_word, long index, vector<string> *potential_words){
        bool cVar3;
        bool cVar4;
        int char_index;
        char *letter;
        char character;

        long offset;

        Node *letter_node;
        long maybe_canary;
        bool add_word;
        Node *node_list;

        maybe_canary = offset + 40;

        if(*nodes->some_flag == true){
            cVar3 = validate(*nodes);

            if(cVar3){
                add_word = true;

                if(add_word){
                    potential_words->push_back(*query_word);
                }else{
                    letter = (char *)*nodes->letter;
                    char_index = index(this, letter);

                    if(*letter == '!'){
                        letter_node._0._4_ = 2;
                    }else{
                        letter_node._0._4_ = 1;
                    }

                    letter = (char *)*nodes->letter;

                    if(*letter == '!'){
                        letter = (char *)*nodes->letter;
                        potential_words.insert(this, letter, *nodes);
                        node_list = *nodes;

                        letter = (char *)*nodes->letter;

                        char_index = index(this, letter);

                        if(node_list->alphabet[char_index] != nullptr){
                            node_list = *nodes;
                            letter = (char *)*nodes->letter;
                            char_index = index(this, letter);
                            node_list = node_list->alphabet[char_index];

                            node_list = *nodes;
                            letter = (char *)*nodes->letter;

                            char_index = index(this, letter);

                            potential_words.insert(this, letter, node_list->alphabet[char_index]);
    

                        }
                    }
                    letter = (char *)*nodes->letter;
                    char_index = isalpha((int)*letter)

                    if(char_index == 0){
                        for(int i = 0; i < 26; i++){
                            unique = *nodes->alphabet[i];

                            if((unique == nullptr) || (unique->some_flag == false)){
                                add_word = false;
                            }else{
                                character = (char)i + 'a';
                                cVar4 = unique.contains(character);

                                if(cVar4){
                                    add_word = false;
                                }
                                add_word = true;
                            }
                            if(add_word){
                                _wild(unique, query_word, index + 4, potential_words);
                            }
                        }
                    }
                    else{
                        node_list = *nodes;
                        letter = (char *)*nodes->letter;
                        char_index = index(this, letter);
                        unique = node_list->alphabet[char_index];

                        for (int i = 0; i < 26; i++){
                            if((*nodes)->alphabet[i] == nullptr){
                                add_word = false;
                            }else{
                                letter = (char *)*nodes->letter;
                                char_index = index(this, letter);
                                if (i == char_index){
                                    add_word = true;
                                }
                            }
                            if(add_word){
                                *nodes->alphabet[i].some_flag = true;
                                potential_words.insert(this, letter, *nodes->alphabet[i]);
                            }
                        }
                        if ((stack != nullptr) && (stack->some_flag == true)){
                            _wild(stack, query_word, index + 4, potential_words);
                        }
                    }
                }
                if(maybe_canary != 0x28){
                    return 1;
                }
                return;
            }
            else{
                add_word = false;
            }
        }

int main() {
    FILE* fp = fopen("wordle-answers-alphabetical.txt", "r");
    cout << "Welcome to the worldle solver" << endl;
    cout << "This is meant to help you beat the game wordle" << endl;
    cout << "If you give us a \'key\' we can give you all the possible options" << endl;
    cout << "For example if you konw the word is in the format:" << endl;
    cout << "a _ _ e t" << endl;
    cout << "then, enter the key \'a**et\', and all possible options will be returned" << endl;
    cout << "\n\n\n\n" << endl;

    // Add Words to Trie
    // TODO: embed file into binary
    Trie trie;

    ifstream words_file("../wordle-answers-alphabetical.txt"); 
    string word;
    while(getline(words_file,word)) {
        trie.Insert(word);
    }


    // While loop that does calles Trie::find_wild
    do {
        cout << "key: ";
        string word;
        cin >> word;
        // replace * with . to work with grep
        for(int i = 0; i < word.size(); i++) {
            if(word.at(i) == '*') {
                word[i] = '.';
            }
        }
        string cmd = "grep \"^" + word + "$\" ../wordle-answers-alphabetical.txt";
        system(cmd.c_str());
        // Trie.find_wild(candidate_words) // how does word go to it
        // Trie.reset()
        // auto begin = candidate_words.begin();
        // auto end = candidate_words.end();
        // while(true) {
        //     if(begin == end) {
        //         break;
        //     }
        //     cout << *begin << endl;
        //     begin++;
        // }
        
    } while(true);
}