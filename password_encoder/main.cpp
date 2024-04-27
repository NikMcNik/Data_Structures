#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
   
   
   char password[20];
   int key;
   cin >> password;
   cin >> key;

   while (key > 26){
      key -= 26;
      // cout<< "key: " << key << endl;
   }
   // cout<< "final key: " << key << endl;

   for (int i = 0; i < strlen(password); i++){
      if (password[i] != 'a' && password[i] != 'e' && password[i] != 'i' && password[i] != 'o' && password[i] != 'u'){
         
         // cout << "letter: " << password[i]<<endl;
         int code =  int(password[i]);
         // cout << "letter val: " << int(password[i])<<endl;

         code += key;
         // cout << "code + key: " << code <<endl;

         if (code > int('z')){
            int overshoot = code - int('z') ;
            // cout << "overshoot: " << overshoot <<endl;

            password[i] = int('a') + overshoot - 1;    
         } else {
            password[i] = code;
         }
         // cout << "result: " << password[i] <<endl;
      
      }
  
   }


   for (int i = strlen(password) - 1; i >= 0; i--){
      cout << password[i];
   }
   

   return 0;
}