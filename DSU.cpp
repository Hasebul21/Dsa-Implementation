#include<bits/stdc++.h>
using namespace std;

void makeset(int arr[],int Sizes[],int n){

  for(int i=0;i<n;i++) {
        arr[i]=i;
        Sizes[i]=1;
  }
}

int Find(int arr[],int x){

   if(arr[x]==x) return x;
   return arr[x]=Find(arr,arr[x]);
}

void Union(int arr[],int Sizes[],int a,int b){

   a=Find(arr,a);
   b=Find(arr,b);
   if(a!=b){

      /// A is bigger
      if(Sizes[a]<Sizes[b]) swap(a,b);
      arr[b]=a;
      Sizes[a]+=Sizes[b];
   }
}

int main(){



}
