#include<iostream>
using namespace std;
int digit(int b)
{
    if(b/10>=1)
    {
        return b%10+digit(b/10);
    }
    else return b;
}
int ab(int a,int b)
{ if(b==a) return digit(a);
  else return ab(a,b-1)+digit(b);
}

int main()
{int a,b;
do{
cout<<"Enter a number between A and B: A<B , a&b=>1 a&b<=10001"<<endl;
cout<<"a=";
cin>>a;
cout<<"b=";
cin>>b;
}
while(a<1||a>10001||b<1||b>10001||a>=b);
cout<<"Sum="<<ab(a,b);
return 0;
}
