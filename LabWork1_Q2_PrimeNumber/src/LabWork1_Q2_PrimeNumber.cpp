//============================================================================
// Name        : LabWork1_Q2_PrimeNumber.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool * SOE (int n){
	static bool isPrime[5500];
	memset(isPrime,true,sizeof(isPrime));

	for(int i = 2; i*i <= n; i++){
		if(isPrime[i] == true){
			for(int j = i*2; j <= n; j+=i){
				isPrime[j] = false;
			}
		}
	}

	return isPrime;
}
int main (){
	int n = 0;
	bool *arr;
	std::cout << "Enter n-number: ";
	cin >> n;

	arr = SOE(n);

	for(int i = 2; i <= n; i++){
		if(arr[i]){
			cout << i <<endl ;
		}
	}
	return 0;
}

