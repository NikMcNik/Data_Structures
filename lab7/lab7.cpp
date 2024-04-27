#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//
struct Node{

    int SSN;
    string name;
    int index;
    Node* next;
    Node* past;
    
};

//finds next hgihset valuse and places before;
void insert (Node*& head, Node*& newNode){    
    Node* node = head;
    Node* prevNode = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    //goes through list;
    while(node != NULL){
        if(node->SSN > newNode->SSN){
            
            newNode->past = prevNode;
            newNode->next = node;
            node->past = newNode;

            if (prevNode != NULL){
                prevNode->next = newNode; 
            } else {
                head = newNode;
            }
            return;
        }
        
        prevNode = node;
        node = node->next;

    }

    newNode->next = NULL;
    newNode->past = prevNode;
    prevNode->next = newNode;

}


void print(Node* head){
    Node* node = head;
    while(node != NULL){
        printf("%09d",node->SSN);
        cout << endl; 
        node = node->next;
    }

}

int search(Node* head, int userSSN){
    Node* node = head;
    while(node->next != NULL){
        if(node->SSN == userSSN){
            return node->index;
        } 
        node = node->next;
    }
    return -1;
}

int main(int argc, char* argv[]){
    Node* head = NULL;  

    int fileSSN;
    string filefirstName;
    string filelastName;
    string fileleadingChar;
    int userSSN;
    int i = 0;

    //reads file name form command line
    fstream input(argv[1]);
    //check if input is near end of file
    while(!input.eof()){
        input >> fileleadingChar;
        input >> fileSSN;
        input >> filefirstName;
        input >> filelastName;
        // cout << fileSSN << endl;

        Node* node = new struct Node;
        node->SSN = fileSSN;
        node->name = filefirstName + " " + filelastName;
        node->index = i;
        insert(head,node);
        

        //if at the end of file end loop
        if(!input) break;
        i++; 
    }

    //closes file;
    input.close();
    
    print(head);

    //gets users ssn value
    cout << "Enter an SSN: " << endl;
    cin >> userSSN;
    int foundIndex = search(head, userSSN);
    if(foundIndex != -1){
        cout<< "Found at location " << foundIndex << endl;
    } else {
        cout << "-1" << endl;
    }
    

    return 0;
}