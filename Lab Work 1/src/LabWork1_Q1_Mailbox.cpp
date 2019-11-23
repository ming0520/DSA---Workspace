//============================================================================
// Name        : LabWork1_Q1.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define TOTAL_MAILBOX 150
using namespace std;

class Mailbox{
private:
	bool isOpen;

public:
	Mailbox(){
		this->isOpen = false;
	}

	void open(){
		this->isOpen = true;
	}

	void close(){
		this->isOpen = false;
	}

	void flip(){
		this->isOpen =! this->isOpen;
	}

	bool getStatus(){
		return this->isOpen;
	}

};

int main() {
	Mailbox mailbox[TOTAL_MAILBOX];

	for(int i = 1; i < 150; i+2){
		switch(i%2){
		case 0:
			mailbox[i].close();
			break;
		default:
			mailbox[i].open();
		}
	}

	for(int i = 0; i < TOTAL_MAILBOX; i+3){
	}

}
