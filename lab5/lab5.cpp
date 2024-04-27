#include <iostream>
using namespace std;

int a[100];

void com(int n, int t){
    if (n < 1){
        

            cout << a[n] << endl;
            int i = 1;
            
        
    }
    if (n >= 1){
        for (int i = 0; i < 10 ; i++){
            a[i] = i;
        cout << a[i] << endl;
        }
            com(n-1,t);
        
    }
}

int main(int argc, char* argv[]){

    int n;
    int t = atoi(argv[1]);
    cin >> n;
    cout << endl;
    com(n,t);
    return 0;
}