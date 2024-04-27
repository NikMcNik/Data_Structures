#include <iostream>
#include "SLL.h"
using namespace std;

template <class V>
class HashTable
{
  int tableSize; // table size number of buckets

  SLL<V> *table;

public:
  // default constructor, which uses default table size 3
  HashTable()
  {
    tableSize = 3;
    table = new SLL<V>[tableSize];
  }

  // constructor, which use size as the table size
  HashTable(int size)
  {
    table = new SLL<V>[size];
    tableSize = size;
  }

  // search item in the table
  // if found, return true; otherwise, return false
  bool find(V ssn)
  {
    SLL<V> *bucket;
    int index = stoi(ssn) % tableSize;
    bucket = &table[index];
    Node<V> *found = bucket->search(ssn);
    if (found == nullptr)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  // insert (item1, item2) to the table
  // use item1 as the key
  // if inserted, return true
  // otherwise, return false
  bool insert(V ssn, V name)
  {
    SLL<V> *bucket;
    int index = stoi(ssn) % tableSize;
    bucket = &table[index];
    bucket->insert(ssn, name);
    return true;
  }

  // delete the pair whose key value is item
  // if deleted, return true
  // otherwise, return false
  bool erase(V ssn)
  {

    SLL<V> *bucket;
    int index = stoi(ssn) % tableSize;
    bucket = &table[index];
    // cout << "removing from list " << ssn << endl;
    return bucket->remove(ssn);
  }

  // return the total number of nodes in the hash table
  int getSize()
  {
    int listSize = 0;
    SLL<V> *bucket;
    for (int i = 0; i < tableSize; i++)
    {
      bucket = &table[i];
      listSize += bucket->getSize();
    }
    return listSize;
  }
};
