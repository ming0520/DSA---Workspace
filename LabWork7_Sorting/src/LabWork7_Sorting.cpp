//============================================================================
// Name        : LabWork7_Sorting.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 20
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Merge(int A[], int left_index, int mid, int right_index){
	int p = left_index, q = mid+1;
	int k = 0;
	int tempArr[right_index-left_index+1];

	for(int i = left_index; i <= right_index; i++){
		//check if first part comes to an end or not
		if(p > mid){
			tempArr[k++] = A[q++];
		}
		//check if second part comes to an end or not
		else if(q > right_index){
			tempArr[k++] = A[p++];
		}
		//check which part has smaller element
		else if(A[p] < A[q]){
			tempArr[k++] = A[p++];
		}
		else{
			tempArr[k++] = A[q++];
		}
	}
	for(int p = 0; p < k; p++){
		A[left_index++] = tempArr[p];
	}
}


void MergeSort(int A[], int left_index, int right_index){
	if(left_index < right_index){
		//same as (l+r)/2 but avoid overflow
		int mid = (left_index + right_index)/2;
		MergeSort(A,left_index,mid);
		MergeSort(A,mid+1,right_index);
		Merge(A,left_index,mid,right_index);
	}



}

void SelectionSort(int A[],int n){
	for(int i = 0; i <= n - 1; i++){
		int min = i;
		for(int j = i+1; j <= n; j++ ){
			if(A[j] < A[min]){
				min = j;
			}
		}
		if (min != i){
			swap(&A[min], &A[i]);
		}
	}
}

// Insertion sort
void InsertionSort(int A[], int n)
{
	int i, j, element;
	for(i = 1; i <= n - 1; i++){
		element = A[i]; // insert ith element in 0 to i - 1 array
		j = i;
		while((j > 0) && (A[j - 1] > element)) 	//compare if A[j - 1] > element
		{
			A[j] = A[j - 1]; // shift elements
			j = j - 1;
		}

		A[j] = element; // place element at jth position
	}
}

//bubblesort
void bubblesort(int A[max], int n)
{
	int i, j;
	for(i = 1; i <= n - 1; i++){
		for(j = 0; j <= n - 1 - i; j++){
			if( A[j] > A[j + 1] ){
				swap(&A[j],&A[j+1]);
			}
		}
	}
}

void Display (int A[], int n){
	for (int i = 0; i <= n - 1; i++)
		cout << A[i] << " ";
	cout << endl;
}


int main() {
	int arr[17] = {23, 56, 21, 6, 89, 45,
			15, 67, 34, 55, 3, 99, 35,
			20, 11, 55, 76};

	int arr1[17], arr2[17], arr3[17],arr4[17];

	for(int i = 0; i < 17; i++){
		arr1[i] = arr[i];
		arr2[i] = arr[i];
		arr3[i] = arr[i];
		arr4[i] = arr[i];
	}

	cout << "Before sort" << endl;
	Display(arr,17);
	cout << "=============================" << endl;

	SelectionSort(arr1,17);
	cout << "Selection sort: " << endl;
	Display(arr1,17);

	MergeSort(arr2,0,17);
	cout << "Merge sort: " << endl;
	Display(arr2,17);

	bubblesort(arr3,17);
	cout << "Selection sort: " << endl;
	Display(arr3,17);

	InsertionSort(arr4,17);
	cout << "Insertion sort: " << endl;
	Display(arr4,17);




}
