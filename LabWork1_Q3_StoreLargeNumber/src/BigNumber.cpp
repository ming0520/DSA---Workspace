/*
 * BigNumber.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: mingb
 */

#include "BigNumber.h"

BigNumber::BigNumber(void){
		this->len = 0;
		this->myTop = -1;
		this->rowR = 0;
		this->colR = 3;
		this->isOddDigit = false;
		this->isDisplay = false;
		for(int i = 0; i < CAPACITY; i++){
			this->number[i] = 0;
		}
	}

BigNumber::BigNumber(string str){
			this->len = 0;
			this->myTop = -1;
			this->rowR = 0;
			this->colR = 3;
			this->isOddDigit = false;
			this->isDisplay = false;
			this->setNumber(str);
			for(int i = 0; i < CAPACITY; i++){
				this->number[i] = 0;
			}
		}

	bool BigNumber::Empty(void){return (len == 0);}

	int BigNumber::getMyTop(void){return this->myTop;}

	bool BigNumber::isDigit(){
		int i = 0;
		while(i < this->len){
			if(!(this->input[i] >= '0' && this->input[i] <= '9')){
				return false;
			}
			i++;
		}
		return true;
	}

	void BigNumber::setLoop(){
		if((this->len % 3) == 0){
			this->rowR = this->len/3;
			this->isOddDigit = false;
		}
		else{
			this->rowR = (this->len/3) + 1;
			this->isOddDigit = true;
		}
	}

	void BigNumber::setNumber(string str){
		this->input =  str;
		this->len = this->input.length();

		if(this->len > CAPACITY * 3){
			cout << "Please enter a number that less than 300 digit" <<endl;
			return;
		}

		if(!isDigit()){
			cout << "Invalid input! Please enter natural number" << endl;
			return;
		}
		setLoop();
		storeNumber();
	}

	int BigNumber::getBlock(int index){
		if(index > myTop && index <= 0){
			cout << "Invalid block! " <<endl;
			return -1;
		}
		return this->number[index];
	}

	void BigNumber::storeNumber(void){
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
			this->isDisplay = true;
		}
	}

	void BigNumber::Display(void){
		if(!this->isDisplay){
			cout << "Not able to display, please check the number." << endl;
			return;
		}
		cout << "Display: " << endl;
		for(int row = this->myTop; row >= 0; row--){
			cout << this->number[row] << ",";
		}
		puts("");
	}

	void BigNumber::push(int number){
		if(myTop == CAPACITY){
			cout << "The block is full !" << endl;
			return;
		}
		if(number/1000 != 0){
			cout << "The number is too big! " << endl;
			return;
		}
		myTop++;
		this->number[myTop] = number;
		this->isDisplay = true;

	}

