#include <iostream>

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

    // While loop that does calles Trie::find_wild
    do {
        cout << "key: " << endl;
        string word;
        cin >> word;
        // Trie.find_wild(candidate_words) // how does word go to it
        // Trie.reset()
        auto begin = candidate_words.begin();
        auto end = candidate_words.end();
        while(true) {
            if(begin == end) {
                break;
            }
            cout << *begin << endl;
            begin++;
        }

    }
}