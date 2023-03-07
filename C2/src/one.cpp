#include <iostream>
#include <string>
#include <map>

using namespace std;


const map<char, string> CIPHER = {
  {'a', "AAAAA"}, {'b', "AAAAB"}, {'c', "AAABA"}, {'d', "AAABB"}, {'e', "AABAA"},
  {'f', "AABAB"}, {'g', "AABBA"}, {'h', "AABBB"}, {'i', "ABAAA"}, {'j', "ABAAB"},
  {'k', "ABABA"}, {'l', "ABABB"}, {'m', "ABBAA"}, {'n', "ABBAB"}, {'o', "ABBBA"},
  {'p', "ABBBB"}, {'q', "BAAAA"}, {'r', "BAAAB"}, {'s', "BAABA"}, {'t', "BAABB"},
  {'u', "BABAA"}, {'v', "BABAB"}, {'w', "BABBA"}, {'x', "BABBB"}, {'y', "BBAAA"},
  {'z', "BBAAB"}
};

string encodeBaconCipher(const string& plaintext) {
  string ciphertext;
  for (char c : plaintext) {
    if (isalpha(c)) {
      ciphertext += CIPHER.at(tolower(c));
    }
  }
  return ciphertext;
}

string decodeV(const string& ciphertext, const string& key) {
  string plaintext;
  for (size_t i = 0; i < ciphertext.length(); i++) {
    char c = ciphertext[i];
    char k = key[i % key.length()];
    plaintext += static_cast<char>((c - k + 26) % 26 + 'A');
  }
  return plaintext;
}

bool checkPassword(const string& password) {
  const string encryptedPassword = "BBAAAABBAABBAAAAAABABABAAABAAAABABBBAAABBABBABABBBAABBAAAABAABAAB";

  string decryptedPassword = "";
  for (size_t i = 0; i < encryptedPassword.length(); i += 5) {
    string code = encryptedPassword.substr(i, 5);
    for (const auto& [c, bacon] : CIPHER) {
      if (bacon == code) {
        decryptedPassword += c;
        break;
      }
    }
  }

  string decodedV = decodeV(decryptedPassword, "dinosaur");
  return decodedV == password;
}

int main() {
  string key;
  cout << "Enter the password to win the game: ";
  getline(cin, key);

  if (checkPassword(key)) {
    cout << "Congratulations, you have passed this level\n";
  } else {
    cout << "Unfortunately that was incorrect\n";
  }

  return 0;
}