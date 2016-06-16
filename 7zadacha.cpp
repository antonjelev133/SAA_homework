 #include<iostream>
using namespace std;
int out(int a[][10],int begin,int n)
{
    int i,count1=0,count2=0;
    for(i=begin;i<n-1;i++)
    {   if(a[begin][i]>a[begin][i+1]&&a[i][n-1]>a[i+1][n-1]&&
             a[n-1][i]<a[n-1][i+1])
             {   if(i==begin)
                 {
                     count1++;
                 }
                else {if(a[i][begin]<a[i+1][begin]) count1++;}


             }
              if(a[begin][i]<a[begin][i+1]&&a[i][n-1]<a[i+1][n-1]&&
             a[n-1][i]>a[n-1][i+1])
             {
                 if(i==begin)
                 {
                     count2++;
                 }
                else {if(a[i][begin]>a[i+1][begin]) count2++;}
             }
    }
    if(count1==(n-1)&&count2==0) return 1;
        else
        if(count2==(n-1)&&count1==0) return 2;
    else return 0;
}
int four(int a[][10],int begin,int end)
{ int i,count1=0,count2=0;
    for(i=begin;i<end-1;i++)
{   //namalqshta
    if(a[begin][i]>a[begin][i+1]&&a[i][end-1]>a[i+1][end-1]&&a[end-1][i]<a[end-1][i+1]
       &&a[end-1][begin]>a[end-2][begin]&&a[end-2][begin]>a[begin+1][begin]&&a[begin+1][begin]>a[begin+1][begin+1]
       &&a[begin+1][begin+1]>a[begin+1][end-2]&&a[begin+1][end-2]>a[end-2][end-2]&&a[end-2][end-2]>a[end-2][begin+1])
    {
        count1++;
    }
    if(a[begin][i]<a[begin][i+1]&&a[i][end-1]<a[i+1][end-1]&&a[end-1][i]>a[end-1][i+1]
       &&a[end-1][begin]<a[end-2][begin]&&a[end-2][begin]<a[begin+1][begin]&&a[begin+1][begin]<a[begin+1][begin+1]
       &&a[begin+1][begin+1]<a[begin+1][end-2]&&a[begin+1][end-2]<a[end-2][end-2]&&a[end-2][end-2]<a[end-2][begin+1])
    {
        count2++;
    }
}

if(count1==3&&count2==0) {return 1;}
 else if(count2==3&&count1==0) {return 2;}
      else return 0;
}
int three(int a[][10],int begin,int end)
{ int i,count1=0,count2=0;
    for(i=begin;i<end-1;i++)
    {//namalqshto
        if(a[begin][i]>a[begin][i+1]&&a[i][end-1]>a[i+1][end-1]
           &&a[end-1][i]<a[end-1][i+1]&&a[end-1][begin]>a[end-2][begin]&&a[end-2][begin]>a[end-2][begin+1])
        {
            count1++;
        }
        if(a[begin][i]<a[begin][i+1]&&a[i][end-1]<a[i+1][end-1]
           &&a[end-1][i]>a[end-1][i+1]&&a[end-1][begin]<a[end-2][begin]&&a[end-2][begin]<a[end-2][begin+1])
        {
            count2++;
        }
    }

    if(count1==2&&count2==0) {return 1;}//namalqshta
 else if(count2==2&&count1==0) {return 2;}
      else return 0;
}
int main()
{int a[10][10],n,i,j,count=0,begin=0,check=1;
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
if(n==4||n==3)
{
    if(n==4)
    {
        if(four(a,0,n)==0) cout<<"Ne e trionoobrazna redica!"<<endl;
         else cout<<"Trionoobrazna redica!"<<endl;
    }
     if(n==3)
    {
        if(three(a,0,n)==0) cout<<"Ne e trionoobrazna redica!"<<endl;
         else cout<<"Trionoobrazna redica!"<<endl;
    }
}
else{
if(out(a,0,n)==0)
{cout<<"Ne e trionoobrazna redica!"<<endl;
 return 0;
}
if(n%2==0)
{
    begin++;
    n--;
    while((n-begin)>4)
    {   if(out(a,begin,n)==0)
        {
            check=0;
            break;
        }
        begin++;
        n--;
    }
    if(check==0)
    {
        cout<<"Ne e trionoobrazna redica!"<<endl;
    }
    else
        {if(four(a,begin,n)!=0)
        {cout<<"Trionoobrazna redica"<<endl;}
         else {cout<<"Ne e trionoobrazna redica!"<<endl;}
        }
}
if(n%2!=0)
{ begin++;
    n--;
    while((n-begin)>3)
    {   if(out(a,begin,n)==0)
        {
            check=0;
            break;
        }
        begin++;
        n--;
    }
    if(check==0)
    {
        cout<<"Ne e trionoobrazna redica!"<<endl;
    }
    else
        {if(three(a,begin,n)!=0)
        {cout<<"Trionoobrazna redica"<<endl;}
         else {cout<<"Ne e trionoobrazna redica!"<<endl;}
        }
}
}
return 0;
}
