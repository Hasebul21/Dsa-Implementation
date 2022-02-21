#include<iostream>
using namespace std;

int main(){

  int arr[]={6,3,5,5,4,2,16,11,10};

  int Size=sizeof(arr)/sizeof(arr[0]); /// Size of the array

  while(1){

     bool temp=false;
     for(int i=0;i<Size-1;i++){

        if(arr[i]>arr[i+1]) { swap(arr[i],arr[i+1]); temp=true; }
      }
      if(temp==false) break;
  }
  for(int i=0;i<Size;i++) cout<<arr[i]<<" ";
  cout<<endl;

}
