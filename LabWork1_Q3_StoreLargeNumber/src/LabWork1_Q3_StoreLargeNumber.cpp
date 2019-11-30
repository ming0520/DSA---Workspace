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
	int myTop;
	int rowR;
	int colR;
	bool isOddDigit;
	string input;

public:

	BigNumber(void){
		this->len = 0;
		this->myTop = 0;
		this->rowR = 0;
		this->colR = 3;
		this->isOddDigit = false;
	}

	bool Empty(void){
		return (len == 0);
	}

	void setLoop(){
		if((this->len % 3) == 0){
			this->rowR = this->len/3;
			this->isOddDigit = false;
		}
		else{
			this->rowR = (this->len/3) + 1;
			this->isOddDigit = true;
		}
	}

	void setNumber(string str){
		this->input =  str;
		this->len = this->input.length();
		setLoop();
		storeNumber();
	}

	int getBlock(int index){
		if(index > myTop && index <= 0){
			cout << "Invalid block! " <<endl;
			return -1;
		}
		return this->number[index];
	}

	int getMyTop(void){
		return this->myTop;
	}

	void storeNumber(void){
		if(Empty()){
			cout << "There is no number!" <<endl;
		}
		else{
			int temp = 0, row = 0, col = 0, mul = 1;

			reverse(this->input.begin(), this->input.end());

			for(row = 0; row < this->rowR; row++){
				if(mul >= 100){
					mul = 1;
					temp = 0;
				}
				if(this->isOddDigit){
					if((this->rowR - row) == 1){
						this->colR = this->len % 3;
					}
				}
				for(col = 0; col < this->colR; col++){
					temp += ((this->input[(row*3)+col] -'0') * mul);
					mul*=10;
					this->number[row] = temp;
				}
				this->myTop++;
			}

		}
	}

	void Display(void){
		cout << "Display: " << endl;
		for(int row = 0; row < this->rowR; row++){
			cout << "Block" << row << ": " << this->number[row] << endl;
		}
	}
};

int main() {
	BigNumber bignumber1;
	bignumber1.setNumber("abc");
	bignumber1.Display();
	return 0;
}
