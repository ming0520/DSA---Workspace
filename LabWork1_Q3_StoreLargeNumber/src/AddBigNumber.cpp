/*
 * AddBigNumber.cpp
 *
 *  Created on: Dec 1, 2019
 *      Author: mingb
 */

#include "AddBigNumber.h"

BigNumber AddBigNumber::getSum(){return sum;}

AddBigNumber::AddBigNumber() {
	// TODO Auto-generated constructor stub
}

AddBigNumber::AddBigNumber(string num1, string num2) {
	// TODO Auto-generated constructor stub


	bigNumber[0].setNumber(num1);
	bigNumber[1].setNumber(num2);

//	int minBlock = (bigNumber[0].getMyTop() < bigNumber[1].getMyTop() ?
//			bigNumber[0].getMyTop() + 1: bigNumber[1].getMyTop()+ 1);

	int maxBlock = (bigNumber[0].getMyTop() < bigNumber[1].getMyTop() ?
				bigNumber[1].getMyTop() + 1: bigNumber[0].getMyTop() + 1);

	int carry = 0;
	int temp = 0;
//	cout << bigNumber[0].getMyTop() << " " <<  bigNumber[1].getMyTop()<< endl;

	for(int i = 0; i < maxBlock; i++){

		temp = bigNumber[0].getBlock(i) + bigNumber[1].getBlock(i) + carry;
//		cout << bigNumber[0].getBlock(i) << "+" << bigNumber[1].getBlock(i)
//				<< "+" << carry
//				<< "=" << temp << endl;

		if(temp / 1000 != 0)
			carry = 1;
		else
			carry = 0;
		temp %= 1000;

		sum.push(temp);
		temp = 0;

		if(i == maxBlock - 1){
			if(carry != 0){
				sum.push(carry);
			}
		}
	}
}

AddBigNumber::~AddBigNumber() {
	// TODO Auto-generated destructor stub
}


