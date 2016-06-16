#include<iostream>
using namespace std;
int main()
{int a[40],i,n;
cout<<"n=";
cin>>n;
 for(i=0;i<n;i++)
 {cout<<"a["<<i<<"]=";
  cin>>a[i];
 }
 for(i=1;i<n-1;i=i+2)
 { if(a[i-1]>=a[i]||a[i+1]>=a[i])
   { cout<<"NO ";  return 1;
   }
 }
 if(n%2==0)
    {if(a[n-1]<=a[n-2])
        {cout<<"NO ";  return 1;
        }
    }
 cout<<"a0 < a1 > a2 < a3.... ";
 return 0;
 }
