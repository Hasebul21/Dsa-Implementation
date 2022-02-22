#include<iostream>
using namespace std;

/// Max Heap
const int Size=10;

struct node{

   int arr[Size+1];
   int n;
};

void show_heap(struct node *Node){

   if(Node->n==0){ cout<<"Empty"<<endl; return; }
   for(int i=1;i<=Node->n;i++) cout<<Node->arr[i]<<" ";
   cout<<endl;

}
void insert_heap(int value,struct node *Node){

     if(Size+1<Node->n){
        cout<<"Overflow"<<endl;
     }
     else {
        Node->n=Node->n+1;
        Node->arr[Node->n]=value;
        int temp=Node->n;
        while(1){
            if(temp==0||temp/2==0) break;
            int parents=Node->arr[temp/2];
            int child=Node->arr[temp];
            if(parents<child){
                swap(Node->arr[temp/2],Node->arr[temp]);
            } else break;
            temp/=2;
        }
     }
}

void delete_heap(struct node *Node){

   if(Node->n==0){ cout<<"Empty! Can not delete"<<endl; return; }
   swap(Node->arr[1],Node->arr[Node->n]);
   Node->n=Node->n-1;
   int parents=1;
   int left_child=2*parents;
   int right_child=(2*parents)+1;
   if(Node->n<=2) return;
   while(left_child<=Node->n){

     cout<<left_child<<endl;
     int Maxx=left_child;
     if(right_child<=Node->n){
        Maxx=max(Node->arr[left_child],Node->arr[right_child]);
        }
    if(Maxx==Node->arr[left_child]){
        swap(Node->arr[parents],Node->arr[left_child]);
        parents=left_child;
    }
    else if(right_child<=Node->n){
       swap(Node->arr[parents],Node->arr[right_child]);
       parents=right_child;
    }
    left_child=2*parents;
    right_child=(2*parents)+1;
   }

}
int main()
{
	struct node *Node,d;
	Node=&d;
	Node->n=0;
    cout<<"Enter The Operation"<<endl;
    cout<<"1 for insertion"<<endl;
    cout<<"2 for Deletion"<<endl;
    cout<<"3 for Show Heap"<<endl;
    cout<<"4 for Exit"<<endl;
	while(1){
        int operation;
        cin>>operation;
        if(operation==1){
            int value;
            cin>>value;
            insert_heap(value,Node);
        } else if(operation==2){
           delete_heap(Node);
        }else if(operation==3){

            show_heap(Node);
        } else return 0;

	}


}
