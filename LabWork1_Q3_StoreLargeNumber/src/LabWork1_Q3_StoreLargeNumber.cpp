//============================================================================
// Name        : LabWork1_Q3_StoreLargeNumber.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BigNumber.h"
using namespace std;

int main() {
	string str = "";
	for(int i = 0; i < 100; i++){
		str += "123";
	}
	BigNumber bignumber1(str);
	bignumber1.Display();
	return 0;
}
