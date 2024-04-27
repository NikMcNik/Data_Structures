#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * next;

};

class LinkedList{
    private:
        Node* head;
    public: 
        LinkedList(){
            head = NULL; 
        };
        void append(int v){
            Node * temp = new Node;
            temp->val = v;
            temp->next = NULL;

            if (head == NULL){
                head = temp;
            } else{
                Node* temp2 = head;
                while (temp2->next != NULL){
                    temp2 = temp2->next;
                }
                temp2->next = temp;

            }

        }
        void display(){
            Node * temp = head;
            while (temp != NULL){
                cout << temp->val << endl;
                temp = temp->next;
            }


       } 

};

int main(){
    LinkedList obj;
    obj.append(10);
    obj.append(20);
    obj.append(30);
    obj.display();
    return 0;

}
