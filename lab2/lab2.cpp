#include <iostream>
#include <vector>
using namespace std;

// function takes in matrix, desired word, and starting x and y coordinates;
bool check(vector<vector<char> > &matrix, char *word, int x, int y)
{
    int wordLength = strlen(word);
    // if the word si longer then the matrix length then it is not in the matrix and therfore return false
    if (wordLength > matrix[0].size()  - y)
    {
        return false;
    }
    // for the lenght of the given word
    for (int i = 0; i < wordLength; i++)
    {   
        //check if any of the letters in the given word dont appear in the matrix
        if (word[i] != matrix[x][y + i])
        {
            return false;
        }
    }

    return true;
}

int main(int agrc, char *argv[])
{
    int x; // num of rows
    int y; // num of columns
    char letter;
    cin >> x;
    cin >> y;
    vector<vector<char> > letterMatrix; // vector decleration

    // sets hieght of vector aka number of rows
    letterMatrix.resize(x);

    // sets width of vector aka number of columns
    for (int i = 0; i < letterMatrix.size(); i++)
    {
        letterMatrix[i].resize(y);
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
        }
    }

    //printed out matrix
    // for (int i = 0; i < letterMatrix.size(); i++)
    // {
    //     cout << endl;
    //     // inner for loop for columns
    //     for (int j = 0; j < letterMatrix[0].size(); j++)
    //     {
    //         cout << letterMatrix[i][j] << " ";
    //     }
    // }
    // cout << endl;

//functin call of check function passing in command line arguments (last 2 are converted into integers)
    bool containsWord = check(letterMatrix, argv[1], atoi(argv[2]), atoi(argv[3]));
    if (containsWord)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}
