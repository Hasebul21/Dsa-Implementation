#include<iostream>
using namespace std;

int bin_high(int arr[],int key,int low,int high){
    int middle;
    if(low>high) return high;
    middle=(low+high)/2;
    if(key<arr[middle]) bin_high(arr,key,low,middle-1);
    else bin_high(arr,key,middle+1,high);
}

int bin_low(int arr[],int key,int low,int high){
    int middle;
    if(low>high) return low;
    middle=(low+high)/2;
    if(key>arr[middle]) bin_low(arr,key,middle+1,high);
    else bin_low(arr,key,low,middle-1);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
	int Size=sizeof(arr)/sizeof(arr[0]);
	int Low=bin_low(arr,8,0,Size-1);
	int High=bin_high(arr,8,0,Size-1);
	cout<<"Low : "<<Low<<endl;
	cout<<"High : "<<High<<endl;
	cout<<"Size : "<<" "<<(High-Low)+1<<endl;

}
