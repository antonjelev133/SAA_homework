#include<iostream>
using namespace std;
void shakerSort(int a[],int n)
{int i,swap,exchange;
do {
  exchange = 0;
  for(i=n-1;i>0;i--)
    {
	if(a[i-1]>a[i])
	{
	  swap=a[i-1];
	  a[i-1]=a[i];
	  a[i]=swap;
	  exchange = 1;
	}
  }

  for(i=1;i<n;i++)
  {
	if(a[i-1]>a[i])
    {
	  swap=a[i-1];
	  a[i-1]=a[i];
	  a[i]=swap;
	  exchange = 1;
	}
  }
} while(exchange);
 }

int main()
{
	int a[30], n, i;
	cout << "n=";
	cin >> n;
	for (i = 0; i<n; i++)
		cin >> a[i];
	for (i = 0; i<n; i++)
		cout << a[i] << " ";
	shakerSort(a, n);
	cout <<endl<< "After sorting:" << endl;
	for (i = 0; i<n; i++)
		cout << a[i] << " ";
	return 0;
}

