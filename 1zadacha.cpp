#include<iostream>
using namespace std;
    int main()
    {
    int a[5][5],n,i,j,di_1=0,di_2=0;
    cout<<"n=";
    cin>>n;
    for(i=0;i<n;i++)
     {  a[i][n]=0;
        a[n][i]=0;
     }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        cout<<"a["<<i<<"]["<<j<<"]=";
        cin>>a[i][j];
        if(i==j)
        {
            di_1=di_1+a[i][j];
        }
        if((i+j)==n-1)
        {
            di_2=di_2+a[i][j];
        }
        a[n][j]=a[n][j]+a[i][j];
        a[i][n]=a[i][n]+a[i][j];
    }

    for(i=0;i<n;i++)
     {  if(a[i][n]!=a[n][i]||di_1!=di_2||di_1!=a[i][n])
      { cout<<"It`s NOT a magic square!"<<endl; return 1;}
     }
     cout<<"It`s a magic square!"<<endl;
     return 0;
    }
