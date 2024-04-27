#include <iostream>
#include <cstring>
using namespace std;

int i = 0;
int s =0;
int size = 0;
char tempVal;

void reverse(char* p){
    //runs through the whole set of charcater to see how many there are to calculate size
    while (*(p+s) != '\0'){
         s++;
        size = s; 
       
    }
    //for half the array swap the current to the corrispodign value that mnay spaces form the end of the array
   for( i = 0; i < size /2; i++)
  {
        tempVal = (*(p+i));
        *(p+i) = *(p + (size - 1) - i);
        *(p + (size - 1) - i) = tempVal; 
        
    }
}
