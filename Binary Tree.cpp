#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node *CreateNode(int val){

    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node *Insert(struct node *root,int val){

   if(root==NULL){
      root=CreateNode(val);
      return root;
   }
   queue<struct node*>Q;
   Q.push(root);
   struct node *temp;
   while(!Q.empty()){

       temp=Q.front();
       Q.pop();
       if(temp->left==NULL){
         temp->left=CreateNode(val);
         return root;
       }
       else if(temp->right==NULL){
         temp->right=CreateNode(val);
         return root;
       }
       if(temp->left)  Q.push(temp->left);
       if(temp->right) Q.push(temp->right);

   }
   return root;
}

void Search(struct node *root){

   queue<struct node*>Q;
   Q.push(root);
   struct node *temp;
   while(!Q.empty()){

       temp=Q.front();
       Q.pop();
       cout<<temp->data<<" ";
       if(temp->left)  { Q.push(temp->left);   }
       if(temp->right) { Q.push(temp->right);  }

   }
   cout<<endl;
}

int main(){

   struct node *root=NULL;
   root=Insert(root,1);
   root=Insert(root,2);
   root=Insert(root,3);
   root=Insert(root,4);
   root=Insert(root,5);
   root=Insert(root,6);
   Search(root);

}
