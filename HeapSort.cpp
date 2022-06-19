#include<stdio.h>
#include <iostream>

using namespace std;


void heapify(int array[], int length, int i)
{
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < length && array[left] > array[largest])
		largest = left;
	if (right < length && array[right] > array[largest])
		largest = right;
	if (largest != i) {
		swap(array[i], array[largest]);
		heapify(array,length, largest);
	}
}

void heapSort(int array[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
		heapify(array, length, i);

	for (int i = length - 1; i > 0; i--) {
		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}


void printArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
		cout << array[i] << " ";
		cout << "\n";
}


int main()
{
	int array[] = { 12, 11, 13, 5, 6, 7 };
	int length = sizeof(array) / sizeof(array[0]);
	
	cout<<"Unsorted Array: "<<endl;
	printArray(array, length);

	heapSort(array, length);

	cout << "\nSorted arrayay:\n";
	printArray(array, length);
}

