#include <iostream>
using namespace std;

void bar(int& m,int* n){
    m = *n;
}

int main(){
    int a = 10;
    int& b = a;
    int c = 30;
    b = 20;
    bar(a, &c);
    cout << a << "\t" << b << "\t" << c << endl;
}