/*
 * AddBigNumber.h
 *
 *  Created on: Dec 1, 2019
 *      Author: mingb
 */
#include "BigNumber.h"
#include <iostream>

#ifndef ADDBIGNUMBER_H_
#define ADDBIGNUMBER_H_

class AddBigNumber: public BigNumber{
private:
	BigNumber bigNumber[2];
	BigNumber sum;
public:
	AddBigNumber(void);
	AddBigNumber(string num1, string num2);
	BigNumber getSum();
	virtual ~AddBigNumber(void);
};

#endif /* ADDBIGNUMBER_H_ */
