/*#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
#include <utility>*/
#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node *next;
};

struct node* Create_node(int val){

       struct node *newNode=(struct node*)malloc(sizeof(struct node));
       newNode->data=val;
       newNode->next=NULL;
       return newNode;
}

void push(struct node **root,int val){

     struct node *newNode=Create_node(val);
     newNode->next=*root;
     *root=newNode;
     cout<<"Successfully Pushed"<<endl;
}

bool isempty(struct node *root){

   if(root==NULL) return true;
   return false;

}
void pop(struct node **root){

    if(isempty(*root)){
        cout<<"Stack is empty"<<endl;
        return;
    }
    *root=(*root)->next;
    cout<<"Successfully Poped"<<endl;

}

void Top(struct node *root){

    if(isempty(root)){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<root->data<<endl;

}
int main()
{
   struct node *root=NULL;
   Top(root);
   push(&root,10);
   push(&root,20);
   push(&root,30);
   Top(root);
   pop(&root);
   Top(root);
   pop(&root);
   pop(&root);
   pop(&root);

}
