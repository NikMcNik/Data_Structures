#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "DLL.h"
using namespace std;

int main(int argc, char *argv[])
{
    // clock
    clock_t start, end;
    double duration;
    start = clock();

    string ssn;
    string name;
    string firstName;
    string lastName;
    string leadingChar;
    DLL mylist;
    int counter = 0;
    int dCounter = 0;
    int searchCounter = 0;

    // reads file name form command line
    fstream input(argv[1]);
    while (!input.eof())
    {
        input >> leadingChar;
        input >> ssn;
        input >> firstName;
        input >> lastName;
        name = firstName + lastName;

        if (leadingChar == "i")
        {
            mylist.insert(ssn, name, counter);
        }
        if (leadingChar == "d")
        {
            mylist.remove(ssn, dCounter);
        }
        if (leadingChar == "r")
        {
            if (mylist.search(ssn) != -1)
            {
                searchCounter++;
            }
        }
        // if at the end of file end loop
        if (!input)
            break;
    }
    // closes file;
    input.close();

    // prints results
    cout << "The Number of Valid Insertation :" << counter << endl;
    cout << "The Number of Valid Deletion :" << dCounter << endl;
    cout << "The Number of Valid Retrieval :" << searchCounter << endl;
    cout << "Item numbers in the List :" << counter - dCounter << endl;
    end = clock();
    duration = (end - start) / (double)CLOCKS_PER_SEC;

    cout << "Time elaspsed :" << duration << endl;
    return 0;
}