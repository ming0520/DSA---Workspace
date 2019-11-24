//============================================================================
// Name        : LabWork1_Q2_PrimeNumber.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#define CAPACITY 30
using namespace std;

int main (){
	int n = 0;
	int list[CAPACITY];

	n = 30;
	for(int i = 1; i <= n; i++){
		list[i-1] = i;
	}

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

	for(int i = 0; i < n/10 ; i++){
		for(int j = 0 ; j < 10; j++){
			cout << list[(i*10)+j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

