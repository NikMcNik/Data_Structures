#include <iostream>
#include <fstream>
#include <string>
using namespace std;

 struct Node{

    string SSN;
    string name;
    int index;
    Node* next;
    
};

void append (Node*& head, Node*& tail, Node*& node){
    if(head == NULL){
        head = node;
    }
    if (tail != NULL){
        tail->next = node;
    } 
    tail = node;
}

void print(Node* head){
    Node* node = head;
    while(node->next != NULL){
        cout << node->SSN << endl;
        node = node->next;
    }

}

int search(Node* head, string userSSN){
    Node* node = head;
    while(node->next != NULL){
        if(node->SSN.compare(userSSN) == 0){
            return node->index;
        } 
        node = node->next;
    }
    return -1;
}

int main(int argc, char* argv[]){

    Node* head = NULL;
    Node* tail = NULL;
     //declares cattalog variables;
    string fileSSN;
    string filefirstName;
    string filelastName;
    string fileleadingChar;
    string userSSN;
    int i = 0;

    //reads file name form command line
    fstream input(argv[1]);
    //check if input is near end of file
    while(!input.eof()){
        input >> fileleadingChar;
        input >> fileSSN;
        input >> filefirstName;
        input >> filelastName;
          
        Node* node = new struct Node;
        node->SSN = fileSSN;
        node->name = filefirstName + " " + filelastName;
        node->index = i;
        append(head,tail,node);

        //if at the end of file end loop
        if(!input) break;
        i++; 
    }

    //closes file;
    input.close();

    // print(head);
   
    //gets users ssn value
    cout << "Enter an SSN: " << endl;
    cin >> userSSN;
    int foundIndex = search(head, userSSN);
    if(foundIndex != -1){
        cout<< "Found at location " << foundIndex << endl;
    }
    
    return 0;

}