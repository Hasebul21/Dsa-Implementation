#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
};
//struct node *head;
/// printing the linklist
void PrintTheList(struct node *head){

   if(head==NULL){ cout<<"Empty"<<endl; return; }
   struct node *temp=head;
   while(temp!=NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
   }
   cout<<endl;

}

/// Insertion at the beginning;
struct node* Insert_At_Beginning(struct node *head,int value){

    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
        return head;
    }
    newNode->next=head;
    head=newNode;
    return head;
}

/// Insertion at the end;
struct node* Insert_At_middle(struct node *head,int position,int value){

    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
        return head;
    }
    struct node *temp1=head;
    struct node *temp2=NULL;
    for(int i=2;i<position;i++) temp1=temp1->next;
    temp2=temp1->next;
    temp1->next=newNode;
    newNode->next=temp2;
    return head;
}

/// Insertion at the end;
struct node* Insert_At_end(struct node *head,int value){

    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
        return head;
    }
    struct node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
    newNode->next=NULL;
    return head;
}

struct node* Deletion_a_key(struct node *head,int key){

    struct node *temp=head;
    if(head==NULL){ cout<<"List is empty"<<endl; return head; }
    if(temp->data==key){
        head=temp->next;
        return head;
    }
    temp=head;
    while(temp->next->next!=NULL) temp=temp->next;
    if(temp->next->data==key){
        temp->next=NULL;
        return head;
    }
    temp=head;
    bool found=false;
    while(temp->next->data!=key){
        temp=temp->next;
        if(temp->next==NULL) { found=true; break; }
    }
    if(found==false&&temp->next->data==key) temp->next=temp->next->next;
    return head;

}
int main(){

    struct node *head=NULL;
    //head=NULL;
    head=Insert_At_Beginning(head,10);
    head=Insert_At_Beginning(head,20);
    head=Insert_At_Beginning(head,30);
    //PrintTheList(head);
    head=Insert_At_end(head,100);
    head=Insert_At_end(head,200);
    head=Insert_At_end(head,300);
    PrintTheList(head);
    head=Insert_At_middle(head,2,500);
    PrintTheList(head);
    head=Insert_At_middle(head,5,800);
    PrintTheList(head);
    head=Insert_At_middle(head,3,2200);
    PrintTheList(head);
    head=Deletion_a_key(head,30);
    PrintTheList(head);
    head=Deletion_a_key(head,300);
    PrintTheList(head);
    head=Deletion_a_key(head,800);
    PrintTheList(head);

}
