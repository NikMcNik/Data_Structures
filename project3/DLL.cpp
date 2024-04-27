#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor is already implemented
// do not modify the default constructor
DLL::DLL()
{
    headPtr = nullptr;
    itemCount = 0;
}

// return the head pointer of the list
// it is already implemented, do not modify it
Node *DLL::getHeadPtr()
{
    return headPtr;
}

// copy construct, which copies an existing list n
// the new list is a different object from n
// the new list and object n have the same contents
// Please implement it
DLL::DLL(DLL &n)
{
    int count = 0;
    DLL newList;
    Node *node = headPtr;
    while (node != NULL)
    {
        newList.insert(node->ssn, node->name, count);
        node = node->succ;
    }
}

// destructor
// release every node of the list
// Please implement it
DLL::~DLL()
{
    Node *node = headPtr;
    Node *temp;

    while (node != NULL)
    {
        temp = node->succ;
        delete node;
        node = temp;
    }
}

// if some node has SSN matcthes string ss
// return the index value of the node
// the index value of the first node is 0, the second node is 1, etc.
// if there is node matching ss, return -1
int DLL::search(string ss) const
{
    int currentIndex = 0;
    Node *node = headPtr;

    while (node != NULL)
    {
        if (node->ssn == ss)
        {
            return currentIndex;
        }
        node = node->succ;
        currentIndex++;
    }
    return -1;
}

// insert (ss, name) to the existing list
// the SSN values are each node are organized in INCREASING order
// if there is a node matching ss value, return false; otherwise true
// else create a node with (ss, name), insert the node to the proper position
// parameter count is the counter of number of valid insertion
// when you implement this method, consider the following situations:
// 1. list is empty
// 2. node should be inserted to the beginning of the list
// 3. node should be inserted to the middle of the list
// 4. node should be inserted to the end of the list
bool DLL::insert(string ss, string name, int &count)
{
    // cout << "we are inserting: " << ss << endl;
    Node *node = headPtr;
    // checks if givien value exists in the list and if we can add it
    while (node != NULL)
    {
        if (node->ssn == ss)
        {
            return false;
        }
        node = node->succ;
    }

    // creats new node and assings its string values
    Node *insertingNode = new struct Node;
    insertingNode->ssn = ss;
    insertingNode->name = name;
    insertingNode->succ = NULL;
    insertingNode->pred = NULL;

    // if list is empty sets the new nodes pointers
    if (headPtr == NULL)
    {

        // sets headPtr tp insertingNode
        headPtr = insertingNode;
        insertingNode->succ = NULL;
        insertingNode->pred = NULL;
        // cout << "inserted in beggining" << endl;
        count++;
        return true;
    }

    Node *lastnode = headPtr;
    node = headPtr;
    while (node != NULL)
    {
        if (ss < node->ssn)
        {
            // cout << "found larger node" << endl;
            break;
        }
        lastnode = node;
        node = node->succ;
    }

    if (node == NULL)
    {
        lastnode->succ = insertingNode;
        insertingNode->pred = lastnode;
        insertingNode->succ = NULL;
        // cout << "inserted at end" << endl;
    }
    else
    { // node is equal to node with higher value must insert before it
        insertingNode->succ = node;
        insertingNode->pred = node->pred;
        if (node->pred != NULL)
        {
            // cout << "updating pred node" << endl;
            node->pred->succ = insertingNode;
        }
        node->pred = insertingNode;
        // cout << "inserted before larger " << node->ssn << " node" << endl;

        // inserted new node at he beggining
        if (node == headPtr)
        {
            // cout << "inserted before first node" << endl;
            headPtr = insertingNode;
        }
    }
    count++;
    return true;
}

// remove node containing ss value
// if there is no node containing ss, return false; otherwise true
// consider the following situations:
// 1. list is empty
// 2. node containing ss value is the first node
// 3. node containing ss value is in the middle of the list
// 4. node containing ss value is the last node of the list
bool DLL::remove(string ss, int &count)
{
    Node *node = headPtr;

    while (node != NULL)
    {
        if (node->ssn == ss)
        {
            // found node;
            // if its the first node
            if (node->pred == NULL)
            {
                headPtr = node->succ;

                if (headPtr->succ != NULL)
                {
                    node->succ->pred = NULL;
                }
            }
            else
            {
                node->pred->succ = node->succ;
                if (node->succ != NULL)
                {
                    node->succ->pred = node->pred;
                }
            }
            delete node;
            count++;
            return true;
        }
        node = node->succ;
    }
    return false;
}

// return the number of the nodes
// it is already implemented, do not modify it
int DLL::size()
{

    return itemCount;
}

// iterate through each node
// print out SSN and memory address of each node
// do not modify this method
void DLL::display()
{
    Node *temp;
    temp = headPtr;
    while (temp != nullptr)
    {
        cout << temp->ssn << "\t" << temp << endl;
        temp = temp->succ;
    }
}
