#include<iostream>
using namespace std;
int main()
{ int a[50],n,i,j,counter=0,length=1,length_max=0;
cout<<"n=";
cin>>n;
for(i=0;i<n;i++)
{
    cout<<"a["<<i<<"]=";
    cin>>a[i];
}
for(i=0;i<n-1;i++)
{
    if(a[i]>a[i+1])
    {   if(length==1)
        {
            counter++;
        }
        length++;
        j=i+1;
       while(j<n)
       {
           if(a[j]>a[j+1])
           {
               length++;
               j++;
           }
           else
           {   cout<<"Length:"<<length<<endl;
           if(length_max<length)
           {
               length_max=length;
           }
               length=1;
               i=j;
               break;
           }

       }

    }
}
if(counter==0)
{
    cout<<"No decreasing row in array!"<<endl;
}
else{
cout<<"The count of decreasing rows is "<<counter<<endl;
cout<<"The max length of a decreasing row is "<<length_max<<endl;
}
return 0;


}
