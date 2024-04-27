#include <iostream>
using namespace std;

int main()
{
    int x; // num of rows
    int y; // num of columns
    char letter;
    cin >> x;
    cin >> y;
    string array[x][y]; // array delceration

    // loop that fills array with charcaters;

    // outer for loop for rows
    for (int i = 0; i < x; i++)
    {
        // inner for loop for columns
        for (int j = 0; j < y; j++)
        {
            cin >> letter;
            // inputs value into row and column positions
            array[i][j] = letter;
        }
    }

    for (int i = 0; i < x; i++)
    {
        cout << endl;
        // inner for loop for columns
        for (int j = 0; j < y; j++)
        {
            cout << array[i][j] << " ";
        }
    }
}