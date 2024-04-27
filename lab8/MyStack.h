#include <iostream>
#include <queue>
using namespace std;

template <class T>
class MyStack {

  // define two instance variables
  // by default, they are private
  queue <T> first; 
  queue <T> second;

 public:

  // return the latest value of MyStack
  T top(){
    return first.back();
  }

  // add value val to MyStack
  void push(T val){
    first.push(val);
  }

  // remove the oldest value from MyStack
  void pop(){
    while(!first.empty()){
      T front = first.front();
      first.pop();
      if(!first.empty()){
        second.push(front);
      } 
    }
    while(!second.empty()){
      first.push(second.front());
      second.pop();     
    }
  }
};
