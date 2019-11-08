// QuickvsInsertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <random>     // mt19937 and uniform_int_distribution
#include <algorithm>  // generate
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind

using namespace std;

const long Size = 5000;//where to change the size n of two types of sort method

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);

	}
}

void hybridSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//cout << high-low << " ";
		if (high - low < 500) {
			insertionSort(arr, high - low + 1);
			return;
		}
		else {
			/* pi is partitioning index, arr[p] is now
			at right place */
			int pi = partition(arr, low, high);

			// Separately sort elements before  
			// partition and after partition  
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void checkHybrid() {
	//quick sort
	int array[Size];

	srand((unsigned)time(0));

	for (int i = 0; i < Size; i++) {
		array[i] = (rand() % 100) + 1;
		//cout << array[i] << " ";
	}

	int n = sizeof(array) / sizeof(array[0]);
	hybridSort(array, 0, n - 1);
}

void checkQuick() {
	//quick sort
	int array[Size];

	srand((unsigned)time(0));

	for (int i = 0; i < Size; i++) {
		array[i] = (rand() % 100) + 1;
		//cout << array[i] << " ";
	}

	int n = sizeof(array) / sizeof(array[0]);
	quickSort(array, 0, n - 1);
}

void checkInsertion() {
	//insertion sort
	
	int array1[Size];
	
	srand((unsigned)time(0));

	for (int i = 0; i < Size; i++) {
		array1[i] = (rand() % 100) + 1;
		//cout << array[i] << " ";
	}

	int n1 = sizeof(array1) / sizeof(array1[0]);
	insertionSort(array1, n1);
}

int main()
{
	for (int j = 175; j < 501; j+=25) {
		if (j != 375 && j != 425 && j != 450 && j != 475)
		{
			//hybrid
			const long Size = j;
			std::clock_t start_time2 = std::clock();
			for (long i = 0; i < 1000; i++)
				checkHybrid();
			std::clock_t tot_time2 = std::clock() - start_time2;
			std::cout << "Time: "
				<< ((double)tot_time2) / (double)CLOCKS_PER_SEC / 1000
				<< " seconds" << std::endl;
			cout << "n:" << j << " hybrid Sorted \n" << endl;
		}
		

	}
	
	return 0;
}

