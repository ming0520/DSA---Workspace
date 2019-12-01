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

	string str1 = "9999999999";
	string str2 = "1111111111";
	AddBigNumber addbignumber(str1,str2);
	BigNumber sum = addbignumber.getSum();
	sum.Display();
	return 0;
}
