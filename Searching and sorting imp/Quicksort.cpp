#include<iostream>
using namespace std;

int partitions(int arr[],int low,int high){

     int pivot=arr[low];
     int i=low,j=high+1;
     //cout<<"WOw"<<i<<" "<<j<<endl;
     while(i<=j){

        do{
            i++;
        }while(pivot>arr[i]);

        do{
            j--;
        }while(pivot<arr[j]);
        if(i<j) swap(arr[i],arr[j]);
     }
     cout<<i<<" "<<j<<endl;
     swap(arr[low],arr[j]);
     return j;
}

void Quicksort(int arr[],int low,int high){

    if(low<high){
    int pivot=partitions(arr,low,high);
    Quicksort(arr,low,pivot);
    Quicksort(arr,pivot+1,high);
    }
}
int main()
{
	int arr[]={0,7,0,8,0,9,2};
	Quicksort(arr,0,6);
	for(int i=0;i<7;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
