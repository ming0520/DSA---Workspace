//============================================================================
// Name        : LabWork1_Q3_StoreLargeNumber.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class BigNumber{

private:

	int number[100];
	int len;
	string input;

public:

	BigNumber(void){
		this->len = 0;
	}

	bool Empty(void){
		return (len == 0);
	}

	void setNumber(string str){
		this->input =  str;
		this->len = this->input.length();
		storeNumber();
	}

	void getNumber(void){
		cin >> this->input;
		this->len = this->input.length();
		storeNumber();
	}

	void storeNumber(void){
		if(Empty()){
			cout << "There is no number!" <<endl;
		}
		else{
			int n = 0;
			int i = 0;
			int j = 0;
			int mul = 1;

			reverse(this->input.begin(), this->input.end());

			for(i = 0; i < this->len/3; i++){
				if(mul >= 100){
					mul = 1;
					n = 0;
				}
				for(j = 0; j < 3; j++){
					cout << (this->input[(i*3)+j] -'0') * mul<<endl;
					n += ((this->input[(i*3)+j] -'0') * mul);
					mul*=10;
					this->number[i] = n;
				}
			}

			if((this->len % 3) == 0){
				return;
			}
			else{
				n = 0;
				mul = 1;
				cout << "Remainder: " << this->len%3 << endl;
				for(j = 0; j < (this->len%3) ; j++){
					n += ((this->input[(i*3)+j] -'0') * mul);
					mul*=10;
					this->number[i] = n;
				}
			}

		}
	}

	void Display(void){
		int n = 0;

		if((this->len % 3) == 0){
			n = this->len/3;
		}
		else{
			n = (this->len/3) + 1;
		}
		cout << "Display: " << endl;
		for(int i = 0; i < n; i++){
			cout << this->number[i] << endl;
		}
	}
};

int main() {
	BigNumber bignumber1;
	bignumber1.setNumber("12345");
	bignumber1.Display();
	return 0;
}
