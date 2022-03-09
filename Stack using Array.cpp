#include<iostream>
using namespace std;

#define Size 5
int arr[Size];
int top=-1;

bool isEmpty(){
    if(top==-1) return true;
    return false;
}

/// Using 0 based indexing
bool isFull(){
    if(top+1==Size) return true;
    return false;
}

void push(int val){

  if(isFull()){
    cout<<"Stack is Full"<<endl;
    return;
  }
  top++;
  arr[top]=val;
}

void pop(){

  if(isEmpty()){
    cout<<"Stack is empty"<<endl;
    return;
  }
  top--;

}

void _top(){

  if(isEmpty()){
    cout<<"Stack is empty"<<endl;
    return;
  }
  cout<<"Top Most Element is "<<arr[top]<<endl;
}

int main(){

  pop();
  _top();
  push(10);
  _top();
  push(20);
  push(30);
  _top();
  pop();
  _top();
  push(40);
  push(50);
  push(60);
  push(70);
  _top();

}
