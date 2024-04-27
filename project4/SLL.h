#include <iostream>
#include "node.h"
using namespace std;

template <class U>
class SLL
{

  Node<U> *headPtr;
  int size;

public:
  // default constructor
  SLL()
  {
    // implement this method
    headPtr = nullptr;
    size = 0;
  }

  // destructor
  ~SLL()
  {
    Node<U> *temp;
    Node<U> *toDelete;
    temp = headPtr;
    while (temp != nullptr)
    {
      toDelete = temp;
      temp = temp->next;
      delete toDelete;
    }
  }

  Node<U> *getHeadPtr()
  {
    return headPtr;
  }

  // insert (item1, item2) to the list
  void insert(U ssn, U name)
  {
    Node<U> *insertingNode = new struct Node<U>;
    insertingNode->SSN = ssn;
    insertingNode->name = name;

    if (headPtr == nullptr)
    {
      headPtr = insertingNode;
      insertingNode->next = nullptr;
      size++;
      return;
    }

    Node<U> *currNode = headPtr;
    Node<U> *lastNode = nullptr;
    while (currNode != nullptr)
    {
      lastNode = currNode;
      currNode = currNode->next;
    }

    lastNode->next = insertingNode;
    insertingNode->next = nullptr;
    size++;
  }

  // if find the item1 value, return the pointer to the node
  // otherwise, return nullptr
  Node<U> *search(U ssn)
  {
    Node<U> *currNode = headPtr;
    while (currNode != nullptr)
    {
      if (currNode->SSN == ssn)
      {
        return currNode;
      }
      else
      {
        currNode = currNode->next;
      }
    }
    return nullptr;
  }

  // remove the node with key value: item1
  bool remove(U ssn)
  {
    // cout << "we got here" << endl;
    Node<U> *currNode = headPtr;
    Node<U> *prevNode = nullptr;
    if (headPtr != nullptr && headPtr->SSN == ssn)
    {
      // cout << "deleting headnode" << endl;

      headPtr = headPtr->next;
      delete currNode;
      size--;
      return true;
    }

    while (currNode != nullptr)
    {

      if (currNode->SSN == ssn)
      {
        // cout << "deleting currnode" << endl;
        // cout << prevNode << endl;

        prevNode->next = currNode->next;
        delete currNode;
        size--;
        return true;
      }
      prevNode = currNode;
      currNode = currNode->next;
    }

    return false;
  }

  int getSize()
  {

    return size;
  }

  // display the SSN values of each node in the linked list
  void display()
  {
    Node<U> *temp;
    temp = headPtr;
    while (temp != nullptr)
    {
      cout << temp->SSN << endl;
      temp = temp->next;
    }
  }
};
