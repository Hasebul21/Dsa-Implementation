#include<iostream>
using namespace std;

int main(){

  int arr[]={6,3,5,5,4,2,16,11,10};

  int Size=sizeof(arr)/sizeof(arr[0]); /// Size of the array

  for(int i=1;i<Size;i++){

    int key=arr[i];
    int j=i-1;
    /// Sorting in Ascending order
    while(key<arr[j]&&j>=0){

        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
  }
  for(int i=0;i<Size;i++) cout<<arr[i]<<" ";
  cout<<endl;

}
