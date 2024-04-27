#include <iostream>
#include <cstring>
using namespace std;

int main(){
    //intitalizes char array
    char input[50];
    // stores what letter user want to delete from the array
    int userIndex;   
    //gets user input and populates array
    for (int i = 0 ; i < 5; i ++){
        cout << "Enter a character: " << endl;
        cin >> input[i];
    }
    //get users nletter they want to delete
    cout << "Enter a integer between 0 and 4: " << endl;
    cin >> userIndex;
    //shift the array items one to the left
    for (int i = userIndex; i < 4; i++){
        input[i] = input[i + 1];
    }  
    //print out the remaining letters
    for (int i = 0; i < 4 ; i++){
        cout << input[i] << " ";
    } 
}