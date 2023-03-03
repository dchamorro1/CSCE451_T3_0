#include <iostream>
#include <fstream>
#include "trie.h"
#include "words.h"

using namespace std;

int main() {
    cout << "Welcome to the worldle solver" << endl;
    cout << "This is meant to help you beat the game wordle" << endl;
    cout << "If you give us a \'key\' we can give you all the possible options" << endl;
    cout << "For example if you konw the word is in the format:" << endl;
    cout << "a _ _ e t" << endl;
    cout << "then, enter the key \'a**et\', and all possible options will be returned" << endl;
    cout << "\n\n\n\n" << endl;

    // Add Words to Trie
    Trie trie;
    for(int i = 0; i < 2317; i++) {
        trie.add_word(WORDS[i]);
    }

    // While loop that does calles Trie::find_wild
    vector<string> potential_words;
    do {
        cout << "key: ";
        string word;
        cin >> word;

        trie.find_wild(word, potential_words);
        trie.root->reset();

        // print out the words
        auto begin = potential_words.begin();
        auto end = potential_words.end();
        while(true) {
            if(begin == end) {
                break;
            }
            word = *begin;
            cout << word << endl;
            begin++;
        }
    } while(true);
}

        // replace * with . to work with grep
        // string cmd = "grep \"^" + word + "$\" ../wordle-answers-alphabetical.txt";
        // system(cmd.c_str());
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
