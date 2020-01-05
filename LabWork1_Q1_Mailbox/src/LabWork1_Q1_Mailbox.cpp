//============================================================================
// Name        : LabWork1_Q1_Mailbox.cpp
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
	bool isOpen = false;

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

int main(void) {
	Mailbox mailbox[TOTAL_MAILBOX];

	for(int i = 0; i < TOTAL_MAILBOX; i++){
		mailbox[i].close();
	}

//	for(int row = 0; row < 5 ; row++){
//		for(int col = 0; col < 30; col++){
//			int pos = (row*10)+col;
//				cout << mailbox[pos].getStatus() << " ";
//		}
//		cout << endl;
//	}
//	cout << endl << endl;

	for(int i = 1; i < TOTAL_MAILBOX; i+=2){
		mailbox[i].open();
	}

//	for(int row = 0; row < 5 ; row++){
//			for(int col = 0; col < 30; col++){
//				int pos = (row*10)+col;
//					cout << mailbox[pos].getStatus() << " ";
//			}
//			cout << endl;
//	}
//	cout << endl << endl;

	for(int i = 2; i < TOTAL_MAILBOX/2; i++){
		for(int j = i; j < TOTAL_MAILBOX; j = i + j){
			mailbox[i].flip();
		}
	}

	for(int row = 0; row < 5 ; row++){
			for(int col = 0; col < 30; col++){
				int pos = (row*10)+col;
					cout << mailbox[pos].getStatus() << " ";
			}
			cout << endl;
		}
}
