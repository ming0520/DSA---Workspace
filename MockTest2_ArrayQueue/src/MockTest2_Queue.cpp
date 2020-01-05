//============================================================================
// Name        : MockTest2_Queue.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define CAPACITY 10
using namespace std;

class Queue{
private:

	int myArray[CAPACITY];
	int myFront;
	int myBack;

public:
	Queue(){
		myFront = myBack = 0;
	}

	bool Empty(void){
		return (myFront == myBack);
	}

	void Enqueue(int value){
		int newBack = (myBack + 1) % CAPACITY;
		if(newBack == myFront){
			cerr << "Queue is full! " << endl;
		}
		else{
			myArray[myBack] = value;
			myBack = newBack;
		}
	}

	void Dequeue(void){
		if(!Empty()){
			myFront = (myFront + 1) % CAPACITY;
		}
	}

	void Display(void){
		for(int i = myFront; i != myBack; i = (i+1) % CAPACITY){
			cout << myArray[i] << endl;
		}
	}

	void Display2(void){
		for(int i = myFront; i != myBack; i = (i+1) % CAPACITY){
			if(myArray[i]%2 != 0){
				cout << myArray[i] << endl;
			}
		}
	}

	int Number(void){
		int count = 0;
		for(int i = myFront; i != myBack; i = (i+1) % CAPACITY){
					count++;
		}
		return count;
	}


};

int main() {
	Queue q;
	for (int i = 0; i < 10; i++){
		q.Enqueue(i);
	}
	q.Display2();
	cout << endl << q.Number() << endl;

	return 0;
}
