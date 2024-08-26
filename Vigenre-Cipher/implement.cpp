/*
This code is an implementation of the Vigenere Cipher.
The Vigenere Cipher is a method of encrypting alphabetic
text by using a simple form of polyalphabetic substitution.
A polyalphabetic cipher is any cipher based on substitution,
using multiple substitution alphabets. The encryption of
the plain text is done using the encryption key, which is a
string of alphabets. The key is repeated to match the length
of the plain text. The encryption is done by shifting the alphabets
of the plain text by the alphabets of the key. The decryption is
done by shifting the alphabets of the cipher text by the alphabets
of the key in the opposite direction. The code is implemented in C++.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string plain_text, key, cipher_text, decrypted_text;
  cout << "Enter the plain text: ";
  getline(cin, plain_text);
  cout << "Enter the key: ";
  cin >> key;

  int key_track = 0;

  transform(key.begin(), key.end(), key.begin(), ::tolower);

  for (int i = 0; i < plain_text.size(); i++)
  {
    if (plain_text[i] == ' ')
    {
      continue;
    }
    if (key_track == key.size())
      key_track = 0;
    char c = (plain_text[i] + key[key_track++] - 2 * 'a') % 26 + 'a';
    cipher_text += c;
  }

  transform(cipher_text.begin(), cipher_text.end(), cipher_text.begin(), ::toupper);
  transform(key.begin(), key.end(), key.begin(), ::toupper);
  cout << "The key is: " << key << endl;
  cout << "The plain text is: " << plain_text << endl;
  cout << "The cipher text is: " << cipher_text << endl;

  return 0;
}
