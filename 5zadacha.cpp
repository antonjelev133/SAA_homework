#include<iostream>
using namespace std;
int main()
{ int a[30],i,n,m;
cout<<"n=";
cin>>n;
  for(i=0;i<n;i++)
  {cout<<"a["<<i<<"]=";
   cin>>a[i];
  }
  m=n;

  for(i=0;i<n;i++)
  { if(a[i]==0)
    { if(a[n-1]==0)
    {
        while(a[n-1]==0)
        { n--;

        }
    }
    a[i]=a[n-1];
     a[n-1]=0;
     n--;
    }
  }
   for(i=0;i<m;i++)
  {cout<<a[i]<<" ";
  }
  return 0;
}
