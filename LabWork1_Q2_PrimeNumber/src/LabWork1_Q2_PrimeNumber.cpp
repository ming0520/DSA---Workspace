//============================================================================
// Name        : LabWork1_Q2_PrimeNumber.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
// SET CAPACITY value for n-number
#define CAPACITY 5500
using namespace std;

/*
 * Purpose: Search desired value via binary search in recursive
 */
int binarySearch(int arr[], int first, int last, int search){
	if(last >= 1){
		int middle = (first + last - 1) / 2;
		if(arr[middle] == search){
			return middle;
		}
		else if(arr[middle] < search){
			return binarySearch(arr, middle + 1, last, search);
		}
		return binarySearch(arr, first, middle - 1, search);
	}
	return -1;
}
/*
 * Purpose: Display desired value in array in recursive
 */
int recurPrint(int arr[], int start, int n){
	//back to previous function when start value
	//greater or equal to end value
	if(start >= n){
		return 0;
	}

		std::cout << arr[start] << " ";
		//print next value, increase start value by 1
		return recurPrint(arr,start+1,n);
}
int main (){
	int n = 30;
	int list[CAPACITY];
	//Store all the possible value into array until number-n
	for(int i = 1; i <= n; i++){
		list[i-1] = i;
	}
	//remove all non prime number (Sieve of Eratosthenes)
	for (int i = 1; i <= n; i++){
		for(int j = i+1; j <=n; j++){
			if(list[i] == 0){
				break;
			}
			int remainder = list[j] % list[i];
			if(remainder == 0){
				list[j] = 0;
			}
		}
	}

	std::sort(std::begin(list), std::end(list));
	int firstPrime = binarySearch(list, 0, n, 1);
	recurPrint(list,firstPrime, n);

	return 0;
}

