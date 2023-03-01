#include <iostream>
#include <fstream>
#include "trie.hpp"

using namespace std;

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