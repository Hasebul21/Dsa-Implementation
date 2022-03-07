#include<iostream>
using namespace std;

double binary_(int n,int start,int ends,double ans){

   //cout<<start<<" "<<ends<<endl;
   if(start>ends) return ans;
   int mid=(start+ends)/2;
   if(mid*mid==n)
   {
     ans=mid;
     return ans;
   }
   if(mid*mid<n)
   {
       ans=mid;
       binary_(n,mid+1,ends,ans);
   }
   else{
     binary_(n,start,mid-1,ans);
   }

}

int main(){
    int n=10;
    double ans=binary_(n,0,n,0);
    double inc=0.1;
    for(int i=0;i<10;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    cout<<ans<<endl;
}
