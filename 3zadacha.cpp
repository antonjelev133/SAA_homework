#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{ int a[10][10],n,i,j,k,top=1,counter1=0,counter2=0;
int *m;
cout<<"n=";
cin>>n;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{cout<<"a["<<i<<"]["<<j<<"]=";
cin>>a[i][j];
}
k=n-2;
m=(int*)calloc(k,sizeof(int));
if(m==NULL)
{
    cout<<"Error: memory could not be allocated";
    return 1;
}
while(top<=k)
{for(i=0;i<=top;i++)
 { for(j=0;j<=top;j++)
   {
    if(i==0||j==0||i==top||j==top)
    {
        m[top-1]+=a[i][j];
    }
   }
 }
   top++;
}
cout<<"Sums of squares:"<<endl;
for(i=0;i<top-1;i++)
cout<<m[i]<<" ";
cout<<endl;
for(i=0;i<top-2;i++)
{  if(m[i]>m[i+1]) counter1++;
   if(m[i]<=m[i+1]) counter2++;
}
if(counter1==top-2||counter2==top-2)
{
    cout<<"Monotonous!"<<endl;
}
else{ cout<<"NOT monotonous!"<<endl;}
free(m);
return 0;
}
