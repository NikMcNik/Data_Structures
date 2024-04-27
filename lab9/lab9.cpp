#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long hashcode(string s){
    int n = s.length();

    long hashResult = 0;
    for(int i = 0; i < n; i++ ){
        hashResult += s[i]* pow(31, (n - 1 - i));
        
    }
    return hashResult;
}


int main(int argc, char* argv[]){
    const int maxIndex = 10007;
    int collisions[maxIndex] = {};
    int totalInputs = 0;
    string s;

    fstream input(argv[1]);
    //check if input is near end of file
    while(!input.eof()){
        input >> s;
        totalInputs++;
        long hash = hashcode(s);
        collisions[hash % maxIndex]++;
         
        //if at the end of file end loop

        if(!input) break;
    }
    //closes file;
    input.close();
    int numOfCollisions = 0;
    for( int i = 0; i < maxIndex; i++){
        if (collisions[i] > 1){
            numOfCollisions += collisions[i] - 1;
        }
    }
    cout << "Total Input is " << totalInputs << endl;
    cout << "Collision # is " << numOfCollisions << endl;
    return 0;
}