#include<iostream>
using namespace std;

int main(){

  int arr[]={6,3,5,5,4,2,16,11,10};

  int Size=sizeof(arr)/sizeof(arr[0]);

  for(int i=0;i<Size;i++){

    int minimum=arr[i],idx=i;

    for(int j=i+1;j<Size;j++){

        if(minimum>arr[j]){

            minimum=arr[j];
            idx=j;
        }
    }
    swap(arr[i],arr[idx]);
  }
  for(int i=0;i<Size;i++) cout<<arr[i]<<" ";
  cout<<endl;

}
