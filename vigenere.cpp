#include <fstream>
#include <string>
#include <cctype> 
#include "vigenere.h"
#include "encryption.h"

using namespace std;

VigenereEncrypt :: VigenereEncrypt(string fileName, string password) : EncryptedFileWriter(fileName)
   {
      ofstream output;
      
      output.open(fileName);
      
      code = password; 
   }
   
string VigenereEncrypt :: encrypt(const string& encrypted)
   {
      string testText = encrypted;
      
      testText = EncryptedFileWriter :: encrypt(encrypted);
      
      code =  EncryptedFileWriter :: encrypt(code);
      
      //cout << testText << endl;
      
      //cout << code << endl;
      
      //string testPass = "PASSWORD";
      
      
      testPassIndex = 0;
      
      for (int i = 0; i < testText.size(); i++)
         {
            if (testText.at(i) >= 65 && testText.at(i) <= 90)
               {
                  int temp = code.at(testPassIndex) - 65;
                  testText.at(i) += temp;
                  
                  
                  
                  //cout << "text: " << testText.at(i) << endl << "Code: " << code << endl;
                  
                  //cout << "Index: " << testPassIndex << endl;
                  
                  testPassIndex++;
                  
                  if (testPassIndex == code.size())
                     { testPassIndex = 0;  }
                     
                  if (testText.at(i) > 90)
                     { testText.at(i) -= 26;}
                     
                  
               }
                 
         //cout << testText.at(i);
         }

      

      return testText;
   }

   
VigenereDecrypt :: VigenereDecrypt(string fileName, string password) : EncryptedFileReader(fileName)
   {
   
      ifstream input;
      
      input.open(fileName);
      
      code = password; 
      
      testPassIndex = 0;
   
   }
   
string VigenereDecrypt :: decrypt(const string& decrypted)
   {
      string testText = decrypted;
      
      code = EncryptedFileReader :: decrypt(code);
      
      //cout << code.size();
      
      //cout << testText << endl << decrypted << endl;;
      
      //cout << code << endl;
      
      //string testPass = "PASSWORD";
      

      
      for (int i = 0; i < testText.size(); i++)
         {
            if (testText.at(i) >= 65 && testText.at(i) <= 90)
               {
                  int temp = code.at(testPassIndex) - 97;
                  
                  //cout << temp << endl;
                  testText.at(i) -= temp;

                  //cout << testText.at(i);
                  
                  //cout << "Index: " << testPassIndex << endl;
                  
                  testPassIndex++;
                  
                  if (testPassIndex == code.size())
                     { testPassIndex = 0;  }
                     
                  if (testText.at(i) < 65)
                     { testText.at(i) += 26;}
                     
                  
               }
                 
         //cout << testText.at(i);
         }

      testText = EncryptedFileReader :: decrypt(testText);
      
      //cout << testText;

   
      return testText;
   }

/*int main()
   {
   
      //VigenereEncrypt("Output.txt","ab");
      
      VigenereEncrypt out("output.txt", "ab");
      
      string test; 
      
      string good;
      
      out << test;
      
   
      return 0;
   }*/