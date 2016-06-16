#include<iostream>
using namespace std;
void reversemas(int a[],int n)
{ if(n>=0)
 {   cout<<a[n]<<" ";
     reversemas(a,n-1);

 }
}
int main()
{int a[20],n,i;
cout<<"Enter n=";
cin>>n;
for(i=0;i<n;i++)
 {  cout<<"a["<<i<<"]=";
    cin>>a[i];
 }
reversemas(a,n-1);
return 0;
}
