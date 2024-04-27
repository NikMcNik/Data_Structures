#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue {
    // these two stck are instance variables
    // by default, the access is private
    stack<T> first;
    stack<T> second;
    
    public:

    // return the value of the oldest member
    T front(){
      while(!first.empty()){
        second.push(first.top());
        first.pop();
      }
      T front = second.top();

      while(!second.empty()){
        first.push(second.top());
        second.pop();
      }
      return front;
    }

    // add value val to MyQueue
    void push(T val){
      first.push(val); 
    }


    // remove the oldest member from MyQueue
    void pop(){
      while(!first.empty()){
        second.push(first.top());
        first.pop();
      }
      
      second.pop();

      while(!second.empty()){
        first.push(second.top());
        second.pop();
      }
    }
};
