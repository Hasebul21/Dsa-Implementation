#include<iostream>
#include<string.h>
using namespace std;

const int Size=5;

struct node{
   string name;
   string contact;
   string country;
   string occupation;
};

int usedIndex[Size]={0};


int findKey(string name){
  int key=0;
  for(int i=0;i<name.size();i++){
    key+=name[i];
  }
  return (key%Size);
}

void inserts(struct node *Arr,string name,string contact,string country,string oc){

    int key=findKey(name);
    int i=key;
    int cnt=0;
    bool check=false;
    while(true){
        if(usedIndex[i]==0){
           usedIndex[i]=1;
           Arr[i].name=name;
           Arr[i].contact=contact;
           Arr[i].country=country;
           Arr[i].occupation=oc;
           check=true;
           break;
        }
        cnt++;
        i++;
        if(i==Size) i=0;
        if(cnt>=Size) break;
    }
    //if(check==true){ cout<<"Insertion Successful "<<Arr->n<<" "<<endl; }
    if(check==false){ cout<<"Hash Table is full"<<endl; }

}

void Search_table(struct node *Arr,string name,string contact){
      int key=findKey(name);
      int i=key;
      int cnt=0;
      while(true){
         if(usedIndex[i]==0) break;
         if(Arr[i].name==name&&Arr[i].contact==contact){
            cout<<"Details Found"<<endl;
            cout<<"Name : "<<Arr[i].name<<endl;
            cout<<"Contact Number : "<<Arr[i].contact<<endl;
            cout<<"Country : "<<Arr[i].country<<endl;
            cout<<"Occupation : "<<Arr[i].occupation<<endl;
            return;
         }
         cnt++;
         i++;
         if(i==Size) i=0;
         if(cnt>=Size) break;
      }
      cout<<"Sorry! Details not found"<<endl;
      return;
}

void seeTable(struct node *temp){
    for(int i=0;i<Size;i++){
        if(usedIndex[i]==0) continue;
        cout<<"Name : "<<temp[i].name<<endl;
        cout<<"Contact Number : "<<temp[i].contact<<endl;
        cout<<"Country : "<<temp[i].country<<endl;
        cout<<"Occupation : "<<temp[i].occupation<<endl;
        cout<<endl;
    }
}
int main(){

   freopen("input.txt", "r", stdin);
   struct node Arr[Size];
   while(1){

        cout<<"Enter the Operation you want to try"<<endl;
        cout<<"1 for insertion 2 for Search 3 for see the hash table 4 for exit"<<endl;
        int operation;
        /// 1 for insertion
        /// 2 for Search
        /// 3 for see the hash table
        /// 4 for exit
        cin>>operation;
        if(operation==1){
             cout<<"Enter your name, Contact, Country, Occupation"<<endl;
             string name,contact,country,Oc;
             cin>>name>>contact>>country>>Oc;
             inserts(Arr,name,contact,country,Oc);

        }
        else if(operation==2){
               cout<<"Enter the name and contact you want to search"<<endl;
               string name,contact;
               cin>>name>>contact;
               Search_table(Arr,name,contact);
        }
        else if(operation==3) seeTable(Arr);
        else if(operation==4) return 0;
   }

}
