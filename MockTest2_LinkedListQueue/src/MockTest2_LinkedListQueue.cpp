//============================================================================
// Name        : MockTest2_LinkedListQueue.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Queue{

	class Node{
	public:
		int Data;
		Node *Next;

		Node(int value){
			Data = value;
			Next = 0;
		}
	};

	Node *myFront, *myBack;

public:
	Queue(){
		myFront = myBack = 0;
	}

	bool Empty(){
		return (myFront == 0);
	}

	void Enqueue(int value){
		Node *temp = new Node(value);
		if(Empty()){
			myFront = myBack = temp;
		}
		else{
			myBack->Next = temp;
			myBack = temp;
		}
	}

	void Dequeue(void){
		if(Empty()){
			cerr << "Queue is empty!" << endl;
		}
		else{
			Node *temp = myFront;
			myFront = myFront->Next;
			delete temp;

			if(myFront == 0){
				myBack = 0;
			}
		}
	}

	void Display(){
		if(Empty()){
			cerr << "Queue is empty!" << endl;
		}
		else{
			for(Node *i = myFront; i != myBack; i = i->Next){
				cout << i->Data << endl;
			}
			cout << "Display completed!" << endl;
		}
	}

	void Display2(){
			if(Empty()){
				cerr << "Queue is empty!" << endl;
			}
			else{
				for(Node *i = myFront; i != myBack; i = i->Next){
					if(i->Data % 2 != 0){
						cout << i->Data << endl;
					}
				}
				cout << "Display completed!" << endl;
			}
		}

	int Number(){
		int counter = 0;
			if(Empty()){
				cerr << "Queue is empty!" << endl;
			}
			else{
				for(Node *i = myFront; i != myBack; i = i->Next){
					counter++;
				}
			}
			return counter;
		}

};

int main() {
	Queue q;
	q.Enqueue(1);
	q.Enqueue(2);
	for (int i = 0; i < 10; i++){
		q.Enqueue(i);
	}
	q.Dequeue();
	q.Display();
	cout << endl << q.Number() << endl;
	return 0;
}
