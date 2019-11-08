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

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

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

void checkQuick() {
	//quick sort
	const long size = 175;//where to change the size n of two types of sort method
	int array[size];

	srand((unsigned)time(0));

	for (int i = 0; i < size; i++) {
		array[i] = (rand() % 100) + 1;
		//cout << array[i] << " ";
	}

	int n = sizeof(array) / sizeof(array[0]);
	quickSort(array, 0, n - 1);
}

void checkInsertion() {
	//insertion sort
	const long size = 175;//where to change the size n of two types of sort method
	int array1[size];

	srand((unsigned)time(0));

	for (int i = 0; i < size; i++) {
		array1[i] = (rand() % 100) + 1;
		//cout << array[i] << " ";
	}

	int n1 = sizeof(array1) / sizeof(array1[0]);
	insertionSort(array1, n1);
}

int main()
{
	for (int j = 0; j < 3; j++) {
		std::clock_t start_time = std::clock();
		for (long i = 0; i < 1000; i++)
			checkQuick();
		std::clock_t tot_time = std::clock() - start_time;
		std::cout << "Time: "
			<< ((double)tot_time) / (double)CLOCKS_PER_SEC / 1000
			<< " seconds" << std::endl;
		cout << "Quick Sorted \n";


		std::clock_t start_time1 = std::clock();
		for (long i = 0; i < 1000; i++)
			checkInsertion();
		std::clock_t tot_time1 = std::clock() - start_time1;
		std::cout << "Time: "
			<< ((double)tot_time1) / (double)CLOCKS_PER_SEC / 1000
			<< " seconds" << std::endl;
		cout << "Insertion Sorted \n" << endl;

	}
	
	return 0;
}

