#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//structure of SNN's and names
struct SSNCatalog
{
    string SSN;
    string firstName;
    string lastName;
    string leadingChar;
    string SSNAndName;


};
//main
int main(int argc, char* argv[]){
    //declares structure array
    struct SSNCatalog SSNList[1000];
    int i = 0;
    //declares cattalog variables;
    string SSN;
    string firstName;
    string lastName;
    string leadingChar;
    //users ssn search
    string userSSN;
    string SSNAndName;
    //keeps track of how many inputs gotten from file
    int numInputs = 0;

    //reads file name form command line
    fstream input(argv[1]);
    //check if input is near end of file
    while(!input.eof()){
        input >> leadingChar;
        input >> SSN;
        input >> firstName;
        input >> lastName;
        
        if (i < 13){
            //concats the ssn and first and last name values
            SSNList[i].SSNAndName = SSN + " " + firstName + " " + lastName;
            i++;
            numInputs++;
        }
        //if at the end of file end loop
        if(!input) break;
    }
    //closes file;
    input.close();
    
    //gets users ssn value
    cout << "Enter an SSN: " << endl;
    cin >> userSSN;
    //checks if ssn is in the array
    for (i = 0; i < numInputs; i++){
        if (userSSN.compare(SSNList[i].SSNAndName.substr(0,9)) == 0){
            cout << "Found at location " << i << endl;
        }
    }

    

    return 0;
}