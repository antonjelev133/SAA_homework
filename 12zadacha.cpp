#include <iostream>
#include <windows.h>
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void insertionSort(int arr[], int length)
{
	int j, temp;

	for (int i = 0; i < length; i++)
	{
		j = i;

		while (j > 0 && arr[j] < arr[j - 1])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

void bubbleSort(int arr[], int length){
	int i, j, temp;

	for (i = 1; i < length; ++i)
	{
		for (j = 0; j < (length - i); ++j)
		if (arr[j]>arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}

void selectionSort(int arr[], int length){
	int c = 0, swap = 0, n = 0, d = 0, position = 0;
	n = length;
	for (c = 0; c < (n - 1); c++)
	{
		position = c;

		for (d = c + 1; d < n; d++)
		{
			if (arr[position] > arr[d])
				position = d;
		}
		if (position != c)
		{
			swap = arr[c];
			arr[c] = arr[position];
			arr[position] = swap;
		}
	}
}

void quickSort(int arr[100], int first, int last){
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (arr[i] <= arr[pivot] && i<last)
				i++;
			while (arr[j]>arr[pivot])
				j--;
			if (i<j){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quickSort(arr, first, j - 1);
		quickSort(arr, j + 1, last);
	}
}
void mergeSort(int arr[], int low, int mid, int high){

	int i, m, k, l, temp[100];

	l = low;
	i = low;
	m = mid + 1;

	while ((l <= mid) && (m <= high)){

		if (arr[l] <= arr[m]){
			temp[i] = arr[l];
			l++;
		}
		else{
			temp[i] = arr[m];
			m++;
		}
		i++;
	}

	if (l>mid){
		for (k = m; k <= high; k++){
			temp[i] = arr[k];
			i++;
		}
	}
	else{
		for (k = l; k <= mid; k++){
			temp[i] = arr[k];
			i++;
		}
	}

	for (k = low; k <= high; k++){
		arr[k] = temp[k];
	}
}

void partition(int arr[], int low, int high){

	int mid;

	if (low<high){
		mid = (low + high) / 2;
		partition(arr, low, mid);
		partition(arr, mid + 1, high);
		mergeSort(arr, low, mid, high);
	}
}

int main()
{
	int length = 100;
cout<<"For 100 elements"<<endl;
	int arr1[100] = { 74, 50, 69, 56, 82
		, 87, 59, 1, 16, 14
		, 97, 35, 84, 100, 76
		, 85, 62, 74, 3, 57
		, 14, 88, 65, 91, 25
		, 23, 4, 59, 40, 63
		, 6, 76, 18, 30, 92
		, 26, 55, 12, 86, 100
		, 12, 14, 87, 64, 42
		, 53, 57, 98, 17, 53
		, 49, 85, 62, 81, 74
		, 4, 35, 69, 34, 44
		, 24, 10, 57, 30, 2
		, 21, 22, 67, 53, 8
		, 53, 64, 17, 81, 65
		, 54, 67, 46, 36, 49
		, 32, 80, 53, 97, 34
		, 9, 37, 33, 55, 73
		, 67, 81, 84, 79, 60
		, 47, 60, 85, 57, 36 };

	StartCounter();
	insertionSort(arr1, length);
	cout << "Insertion sort: " << GetCounter() << "\n";

	int arr2[100] = { 74, 50, 69, 56, 82
		, 87, 59, 1, 16, 14
		, 97, 35, 84, 100, 76
		, 85, 62, 74, 3, 57
		, 14, 88, 65, 91, 25
		, 23, 4, 59, 40, 63
		, 6, 76, 18, 30, 92
		, 26, 55, 12, 86, 100
		, 12, 14, 87, 64, 42
		, 53, 57, 98, 17, 53
		, 49, 85, 62, 81, 74
		, 4, 35, 69, 34, 44
		, 24, 10, 57, 30, 2
		, 21, 22, 67, 53, 8
		, 53, 64, 17, 81, 65
		, 54, 67, 46, 36, 49
		, 32, 80, 53, 97, 34
		, 9, 37, 33, 55, 73
		, 67, 81, 84, 79, 60
		, 47, 60, 85, 57, 36 };

	StartCounter();
	bubbleSort(arr2, length);
	cout << "Bubble sort: " << GetCounter() << "\n";

	int arr3[100] = { 74, 50, 69, 56, 82
		, 87, 59, 1, 16, 14
		, 97, 35, 84, 100, 76
		, 85, 62, 74, 3, 57
		, 14, 88, 65, 91, 25
		, 23, 4, 59, 40, 63
		, 6, 76, 18, 30, 92
		, 26, 55, 12, 86, 100
		, 12, 14, 87, 64, 42
		, 53, 57, 98, 17, 53
		, 49, 85, 62, 81, 74
		, 4, 35, 69, 34, 44
		, 24, 10, 57, 30, 2
		, 21, 22, 67, 53, 8
		, 53, 64, 17, 81, 65
		, 54, 67, 46, 36, 49
		, 32, 80, 53, 97, 34
		, 9, 37, 33, 55, 73
		, 67, 81, 84, 79, 60
		, 47, 60, 85, 57, 36 };

	StartCounter();
	selectionSort(arr3, length);
	cout << "Selection sort: " << GetCounter() << "\n";


	int arr4[100] = { 74, 50, 69, 56, 82
		, 87, 59, 1, 16, 14
		, 97, 35, 84, 100, 76
		, 85, 62, 74, 3, 57
		, 14, 88, 65, 91, 25
		, 23, 4, 59, 40, 63
		, 6, 76, 18, 30, 92
		, 26, 55, 12, 86, 100
		, 12, 14, 87, 64, 42
		, 53, 57, 98, 17, 53
		, 49, 85, 62, 81, 74
		, 4, 35, 69, 34, 44
		, 24, 10, 57, 30, 2
		, 21, 22, 67, 53, 8
		, 53, 64, 17, 81, 65
		, 54, 67, 46, 36, 49
		, 32, 80, 53, 97, 34
		, 9, 37, 33, 55, 73
		, 67, 81, 84, 79, 60
		, 47, 60, 85, 57, 36 };

	StartCounter();
	quickSort(arr4, 0, 99);
	cout << "Quick sort: " << GetCounter() << "\n";
	int arr5[100] = { 74, 50, 69, 56, 82
		, 87, 59, 1, 16, 14
		, 97, 35, 84, 100, 76
		, 85, 62, 74, 3, 57
		, 14, 88, 65, 91, 25
		, 23, 4, 59, 40, 63
		, 6, 76, 18, 30, 92
		, 26, 55, 12, 86, 100
		, 12, 14, 87, 64, 42
		, 53, 57, 98, 17, 53
		, 49, 85, 62, 81, 74
		, 4, 35, 69, 34, 44
		, 24, 10, 57, 30, 2
		, 21, 22, 67, 53, 8
		, 53, 64, 17, 81, 65
		, 54, 67, 46, 36, 49
		, 32, 80, 53, 97, 34
		, 9, 37, 33, 55, 73
		, 67, 81, 84, 79, 60
		, 47, 60, 85, 57, 36 };

	StartCounter();
	partition(arr5, 0, 99);
	cout << "Merge sort: " << GetCounter() << "\n";

	return 0;
}
