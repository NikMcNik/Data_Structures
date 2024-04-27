#include <iostream>
#include <vector>
#include "colormod.h"
using namespace std;

void markPMatrix(vector<vector<bool> > &Pmatrix , int rowNum, int columnNum, int wordLength, int x, int y){
    for (int i = 0; i < wordLength; i++){
        Pmatrix[rowNum + y*i][columnNum + x*i] = true;
    }
}

bool findWordInDirection(vector<vector<char> > &matrix,char *word, int rowNum, int columnNum, int x, int y, int wordLength){
    //check if out of bounds
    if (y > 0 && rowNum + y* (wordLength - 1) > matrix.size()){
        return false;
    }
    if ( y < 0 && rowNum + y* (wordLength - 1) < 0){
        return false;
    }
    if ( x > 0 && columnNum + x * (wordLength -1) > matrix[0].size()){
        return false; 
    }
     if ( x < 0 && columnNum + x * (wordLength -1) < 0){
        return false; 
    }


    for (int i = 1; i < wordLength; i++){
        if(matrix[rowNum + y*i][columnNum + x*i] != word[i]){
            return false;
        }
    }
    return true;
}

void directionalSearch(vector<vector<char> > &matrix, vector<vector<bool> > &Pmatrix , char *word, int rowNum, int columnNum){
   
    int wordlength = strlen(word);
     //up
    if (findWordInDirection(matrix, word, rowNum, columnNum, 0, -1,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, 0 ,-1);
    }
    //right
    if (findWordInDirection(matrix, word, rowNum, columnNum, 1, 0,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, 1 ,0);
    }
    //left
    if (findWordInDirection(matrix, word, rowNum, columnNum, -1, 0,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, -1 ,0);
    }
    //down
    if (findWordInDirection(matrix, word, rowNum, columnNum, 0, 1,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, 0 ,1);
    }
    //up right
   if (findWordInDirection(matrix, word, rowNum, columnNum, 1, -1,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, 1 ,-1);
    }
    // up left
    if (findWordInDirection(matrix, word, rowNum, columnNum, -1, -1,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, -1 ,-1);
    }
    //down right
    if (findWordInDirection(matrix, word, rowNum, columnNum, 1, 1,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, 1 ,1);
    }
    //down left
    if (findWordInDirection(matrix, word, rowNum, columnNum, -1, 1,wordlength)){
        markPMatrix(Pmatrix, rowNum, columnNum, wordlength, -1 ,1);
    }
    }
           

void findAndMark(vector<vector<char> > &matrix, vector<vector<bool> > &Pmatrix , char *word){
    for (int i = 0; i < matrix.size(); i++)
    {
        // iner loop for columns
        for (int j = 0; j < matrix[0].size(); j++)
        {   
            if (word[0] == matrix[i][j]){
                  directionalSearch(matrix, Pmatrix, word, i ,j);  
            }
        }
    }
}

int main(int argc, char *argv[]){
    Color::Setting red(Color::FG_RED);
    Color::Setting def(Color::FG_DEFAULT);
    int x; //number of rows
    int y; // number of columns
    char letter;
    cin >> x;
    cin >> y;

    vector<vector<char> > letterMatrix; // vector decleration
    vector<vector<bool> > positionMatrix; // vector decleration 
    // sets hieght of vector aka number of rows
    letterMatrix.resize(x);
    positionMatrix.resize(x);
    // sets width of vector aka number of columns
    for (int i = 0; i < letterMatrix.size(); i++)
    {
        letterMatrix[i].resize(y);
        positionMatrix[i].resize(y);
    }

    // populates vector with character values
    // outer loop for rows
    for (int i = 0; i < letterMatrix.size(); i++)
    {
        // iner loop for columns
        for (int j = 0; j < letterMatrix[0].size(); j++)
        {
            // gets letter from input
            cin >> letter;
            // set letter into row and column position
            letterMatrix[i][j] = letter;
            positionMatrix[i][j] = false;
        }
    }

    for (int i = 1 ; i < argc; i++ ){
        findAndMark(letterMatrix,positionMatrix,argv[i] );
    }
    //printed out matrix
    for (int i = 0; i < letterMatrix.size(); i++)
    {
        cout << endl;
        // inner for loop for columns
        for (int j = 0; j < letterMatrix[0].size(); j++)
        {   
            if (positionMatrix[i][j]){
                cout << red << letterMatrix[i][j] << def << " ";
            } else {
                cout <<  letterMatrix[i][j] << " ";
            }
            

        }
    }
    cout << endl;


    // //printed out position matrix
    // for (int i = 0; i < positionMatrix.size(); i++)
    // {
    //     cout << endl;
    //     // inner for loop for columns
    //     for (int j = 0; j < positionMatrix[0].size(); j++)
    //     {
    //         cout << positionMatrix[i][j] << " ";
            
    //     }
    // }
    // cout << endl;

}