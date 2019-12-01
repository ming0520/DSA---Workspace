/*
 * BigNumber.h
 *
 *  Created on: Nov 30, 2019
 *      Author: mingb
 */

#ifndef BIGNUMBER_H_
#define BIGNUMBER_H_
#define CAPACITY 100

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class BigNumber {

private:
	int number[CAPACITY];
	int len;
	int myTop;
	int rowR;
	int colR;
	bool isOddDigit;
	bool isDisplay;
	string input;

	bool Empty(void);
	bool isDigit(void);
	void setLoop(void);
	void storeNumber(void);

public:
	BigNumber(void);
	BigNumber(string str);
	void setNumber(string str);
	int getBlock(int index);
	int getMyTop(void);
	void Display(void);
	void push(int num);




};

#endif /* BIGNUMBER_H_ */
