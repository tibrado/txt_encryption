# txt file encryption & decryption
Encrypt and Decrypt text/.txt files 

# Functions
CRYPTION(String_to_(Encrypt/Decrypt), Key_word); 
string decrypt() -> return string decryption
string encrypt() -> return string encryption

CFILE("Path to text file", Key_word);
encrypt_file() -> Return true if file is encrypted 
decrypt_file() -> Return true if file is decrypted

# Sample:
  #include \<iostream\>
  #include "cryption.h"

  using namespace std; 

  int main() {


    CFILE A("test.txt", "LEMON"); 
    A.encrypt_file(); 

    CFILE B("test.txt", "LEMON");
    B.decrypt_file(); 

    return 0;
  }
