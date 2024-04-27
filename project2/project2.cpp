#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//structure of SNN's and names
struct SSNCatalog
{
    string SSN;
    string firstName;
    string lastName;


};



//main
int main(int argc, char* argv[]){
    //clock
    clock_t start, end;
    double duration;

    start = clock();
    //declares structure array
    int arraySize = 1000;
    SSNCatalog *SSNList = new SSNCatalog[arraySize];
    int insertIndex = 0;
    //declares cattalog variables;
    string SSN;
    string firstName;
    string lastName;
    string leadingChar;
    int insertCount = 0;
    int deleteCount = 0;
    int getCount = 0;
    

    //keeps track of how many inputs gotten from file
    int numInputs = 0;

    //reads file name form command line
    fstream input(argv[1]);
    
    cout << endl;
    //check if input is near end of file
    while(!input.eof()){
        input >> leadingChar;
        input >> SSN;
        input >> firstName;
        input >> lastName;
        
        if (leadingChar == "i"){
            bool existInArray = false;
            for(int j = 0 ; j < insertIndex ; j++ ){

                if ((SSNList[j].SSN.compare(SSN)) == 0){
                    existInArray = true;
                    break;
                }     
            }
            if ( existInArray){
                continue;
            }
            if (insertIndex > arraySize){
                //make new array that double the size
                //insert info from old array into new one
                arraySize = arraySize * 2;
                SSNCatalog *NewSSNList = new SSNCatalog[arraySize];
                for(int j = 0 ; j < insertIndex ; j++ ){
                    
                    NewSSNList[j] = SSNList[j];
                  
                }
                delete[]SSNList;
                SSNList = NewSSNList;
                
            }

            SSNList[insertIndex].SSN = SSN;
            SSNList[insertIndex].firstName = firstName;
            SSNList[insertIndex].lastName = lastName;
            insertIndex++;
            insertCount++;
        } 
        if (leadingChar == "d"){

            int deleteIndex = -1;
            for(int j = 0 ; j < insertIndex ; j++ ){
                if ((SSNList[j].SSN.compare(SSN)) == 0){
                    deleteIndex = j;

                    break;
                }
                
            }
            if (deleteIndex != -1){
                for (int j = deleteIndex + 1; j < insertIndex ; j++ ){
                    SSNList[j - 1] =  SSNList[j];
                    
                }
                insertIndex--;
                deleteCount++;

                if (insertIndex < arraySize/4){
                //make new array that double the size
                //insert info from old array into new one
                arraySize = arraySize/2;
                SSNCatalog *NewSSNList = new SSNCatalog[arraySize];
                for(int j = 0 ; j < insertIndex ; j++ ){
                    
                    NewSSNList[j] = SSNList[j];
                  
                }
                delete[]SSNList;
                SSNList = NewSSNList;
                
            }
            }
        }
    
        if (leadingChar == "r"){

            //check if name and ssn are in array
            //if yes then add to counter
            for(int j = 0 ; j < insertIndex ; j++ ){
                if ((SSNList[j].SSN.compare(SSN)) == 0){
                    getCount++;
                    break;
                }     
            }
        }

        
        //if at the end of file end loop
        if(!input) break;
    }
    //closes file;
    input.close();
    
    
    //prints results
    cout << "The Number of Valid Insertation :" << insertCount << endl;
    cout << "The Number of Valid Deletion :" << deleteCount << endl;
    cout << "The Number of Valid Retrieval :" << getCount << endl;
    cout << "Item numbers in the array :" << insertIndex << endl;
    cout << "Array Size is :" << arraySize << endl;
    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;

    cout<<"Time elaspsed :"<< duration <<endl;

    return 0;
}