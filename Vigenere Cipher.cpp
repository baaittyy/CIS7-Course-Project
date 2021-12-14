// Course Project
#include <iostream>
#include <string>
using namespace std;

// Generates the Key til it matches the message
string keygen(string str, string key){
  int x = str.size();
  int i = 0;

  while (key.size() != str.size()){
    key.push_back(key[i]);
    ++i;
    if (x==1){
      i = 0;
    }
  }
  return key;
}

// Encrypts the message
string encryptText(string str, string key){
  string encrypt_text;
  for (int i = 0; i < str.size(); ++i){
    char  x = (str[i] + key[i]) %26;
    x += 'A';

    encrypt_text.push_back(x);
  }
  return encrypt_text;
}

// Decrypts the message
string decryptText(string encrypt_text, string key){
  string decrypt_text;
  for (int i=0; i < encrypt_text.size(); ++i){
    char x = (encrypt_text[i] - key[i] + 26) %26;
    x += 'A';
    decrypt_text.push_back(x);
  }
  return decrypt_text;
}

// Driver
int main() {
    bool run=true;
    while (run) {
        string str, keyword;
        int option;
        cout << "Please enter your option:" << endl << endl << "1. Encrypt Text" << endl << "2. Decrypt Text" << endl << "3. Exit" << endl;
        cin >> option;
        cin.ignore();

        while (option !=1 && option !=2 && option !=3) { //if invalid option
            cout << "Invalid option. Please reselect:" << endl << endl << "1. Encrypt Text" << endl << "2. Decrypt Text" << endl << "3. Exit" << endl;
            cin >> option;
            cin.ignore();
        }

        if (option==1) {

            cout << "Please enter text to be encrypted" << endl;
            cin >> str;
            cin.ignore();
            cout << "Please enter the keyword to be used" << endl;
            cin >> keyword;

            string key = keygen(str, keyword);
            string encrypt_text = encryptText(str, key);
            cout << "Your encrypted message is: " << encrypt_text << endl;

        } else if (option==2 ){

            cout << "Please enter text to be decrypted" << endl;
            cin >> str;
            cin.ignore();
            cout << "Please enter the keyword to be used" << endl;
            cin >> keyword;
            cin.ignore();

            string key = keygen(str, keyword);
            cout << "Your decrypted message is: " << decryptText(str, key) << endl;

        } else {
            run=false;
        }

    }

    return 0;
}
