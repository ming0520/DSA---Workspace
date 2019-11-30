/*
 * BigNumber.h
 *
 *  Created on: Nov 30, 2019
 *      Author: mingb
 */

#ifndef BIGNUMBER_H_
#define BIGNUMBER_H_

#include <iostream>
using namespace std;

class BigNumber {
private:
	int number[100];
	int len;
	int myTop;
	int rowR;
	int colR;
	bool isOddDigit;
	bool isDisplay;
	string input;
public:
	BigNumber(void);
	BigNumber(string str);
	bool Empty(void);
	bool isDigit(void);
	void setLoop(void);
	void setNumber(string str);
	int getBlock(int index);
	int getMyTop(void);
	void storeNumber(void);
	void Display(void);


};

#endif /* BIGNUMBER_H_ */
