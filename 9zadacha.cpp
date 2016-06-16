#include<iostream>
using namespace std;
int sum(int n)
{ if(n>0)
 { return (n%10)+sum(n/10);
 }
}

int main()
{int n;
do{
cout<<"Enter a number between[ 10-10000]:";
cin>>n;
}
while(n<10||n>10000);
cout<<sum(n);
return 0;
}
