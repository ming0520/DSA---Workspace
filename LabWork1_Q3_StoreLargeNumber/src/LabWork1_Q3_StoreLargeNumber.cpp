//============================================================================
// Name        : LabWork1_Q3_StoreLargeNumber.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "BigNumber.h"
#include "AddBigNumber.h"
using namespace std;

int main() {

//	BigNumber bignumber1;
//	bignumber1.setNumber("11111");
//	cout << bignumber1.getMyTop() << endl;
// test value:
// 123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	string str1 = "9999999999";
	string str2 = "1111111111";
	cout << "Enter first value: ";
	cin >> str1;
	cout << "Enter second value: ";
	cin >> str2;
	AddBigNumber addbignumber(str1,str2);
	BigNumber sum = addbignumber.getSum();
	sum.Display();
	return 0;
}
