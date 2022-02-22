#include<iostream>
using namespace std;

void Merge(int arr[],int low,int mid,int high){

     int n1=(mid-low)+1;
     int n2=high-mid;
     int brr[n1+1],crr[n2+1];
     for(int i=0;i<n1;i++){
        brr[i]=arr[low+i];
     }
     for(int i=0;i<n2;i++){
        crr[i]=arr[mid+1+i];
     }
     int i=0,j=0,k=low;
     while(i<n1&&j<n2){
        if(brr[i]<crr[j]){
            arr[k]=brr[i];
            i++;
        }
        else {
           arr[k]=crr[j];
           j++;
        }
        k++;
     }
     while(i<n1){ arr[k++]=brr[i++]; }
     while(j<n2){ arr[k++]=crr[j++]; }
}

void Merge_sort(int arr[],int low,int high){

       if(low<high){
        int mid=(low+high)/2;
        Merge_sort(arr,low,mid);
        Merge_sort(arr,mid+1,high);
        Merge(arr,low,mid,high);
       }

}
int main()
{
	int arr[] = {6, 5, 4, 3, 1, 2, 0};
	int Size=sizeof(arr)/sizeof(arr[0]);
	Merge_sort(arr,0,Size-1);
	for(int i=0;i<Size;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
