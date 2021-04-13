#ifndef __Vigenere_H
#define __Vigenere_H
#include <iostream>
#include "encryption.h"

using namespace std;

//class EncryptedFileWriter : public ofstream{};

class VigenereEncrypt : public EncryptedFileWriter
{
   private:
      string outFile;
      string code;
      int testPassIndex;

   public:
      string encrypt(const string& str); 
      VigenereEncrypt(string fileName, string password); 
   
};

class VigenereDecrypt : public EncryptedFileReader
   {
      private:
         string outFile;
         string code;
         int testPassIndex;
   
      public:
         string decrypt(const string& str);
         VigenereDecrypt(string fileName, string password);
   
   };

#endif