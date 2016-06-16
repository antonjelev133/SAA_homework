#include<iostream>
using namespace std;
void red(int n,int num1,int num2)
{ if(n>0)
 { red(--n,++num1,++num2);
 }
 else {cout<<num1<<":"<<num2;
 }
}

int main()
{int n;
do{
cout<<"Enter a number between[ 0-20]:";
cin>>n;
}
while(n<0||n>20);
red(n,0,1);
return 0;
}
