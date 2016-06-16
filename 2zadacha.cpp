#include<iostream>
using namespace std;
int minRow(int a[][10],int n,int row)
{ int j,min=0;
for(j=1;j<n;j++)
{ if(a[row][min]>a[row][j])
  {min=j;}
}
return min;
}
int maxRow(int a[][10],int n,int row)
{ int j,max=0;
for(j=1;j<n;j++)
{ if(a[row][max]<a[row][j])
  {max=j;}
}
return max;
}
int minColon(int a[][10],int n,int col)
{ int j,min=0;
for(j=1;j<n;j++)
{ if(a[min][col]>a[j][col])
  {min=j;}
}
return min;
}
int maxColon(int a[][10],int n,int col)
{ int j,max=0;
for(j=1;j<n;j++)
{ if(a[max][col]<a[j][col])
  {max=j;}
}
return max;
}
int main()
{int a[10][10],n,i,j,count=0,min,max;
cout<<"n=";
cin>>n;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{cout<<"a["<<i<<","<<j<<"]=";
cin>>a[i][j];
}
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}
for(i=0;i<n;i++)
{min=minRow(a,n,i);
max=maxRow(a,n,i);
if(minColon(a,n,max)==i) {count++;}
if(maxColon(a,n,min)==i) {count++;}
}
if(count==0){cout<<"Nqma sedlovi tochki!"<<endl;}
else cout<<"Broi sedlovi tochki:"<<count<<endl;
return 0;
}
