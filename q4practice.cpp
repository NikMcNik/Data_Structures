#include <iostream>
using namespace std;

class A{
    public:
    void foo(){
    cout << "From A" << endl;
    }
};
class B:public A{
    public:
    void foo(){
    cout << "From B" << endl;
    }
};
int main(){
    A* p;
    B obj;
    p = &obj;
    p->foo();
}