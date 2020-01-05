//============================================================================
// Name        : LabWork2_Q3_ArrayBasedLinkList.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define CAPACITY 10

using namespace std;


class List{

	int first = 0, free = 0, mySize = -1, myBack = 0;
	class Node{
	public:
		char Data;
		int Next = -1;
	};

public:
	Node myList[CAPACITY];
	List(void){
		int i = 0;
		for(; i < CAPACITY - 1; i++){
			this->myList[i].Data = '\0';
			this->myList[i].Next = i+1;
		}
		this->myList[i].Next = -1;
	}

	void Initialize(void){
		char data[] = {'J','Z','C','P','B','M','K','Q','?','?'};
		int next[] = {3,6,0,-1,2,1,7,8,9,-1};

		for(int i = 0; i < 10; i++){
			this->myList[i].Data = data[i];
			this->myList[i].Next = next[i];
		}
		first = 4, free = 5, mySize = 4, myBack = 3;

	}

	bool Empty(void){
		return(mySize == -1);
	}

	bool Full(void){
		return (this->mySize == CAPACITY - 1);
	}

	void DisplayElement(void){
		printf("Node\tData\tNext\n");
		int counter = 0;
		for(int i = 0; i < CAPACITY; i++){
			printf("%i\t%c\t%i\n",counter,this->myList[i].Data,this->myList[i].Next);
			counter++;
		}
	}

	void Display(void){
		if(this->Empty()){
			cerr << "List is empty!" << endl;
			return;
		}
		printf("Node\tData\tNext\n");
		for(int i = this->first; i != -1; i = this->myList[i].Next){
			printf("%i\t%c\t%i\n",i,this->myList[i].Data,this->myList[i].Next);;
		}
	}

	void Insert(char data){
		if(this->Full()){
			cout << "List is full!" << endl;
			return;
		}
		if(this->first == -1){
			this->first = free;
			this->myList[this->free].Data = data;
		}
		else{
			this->myList[this->free].Data = data;
			this->myList[this->myBack].Next = free;
		}

		this->myBack = free;
		this->free = this->myList[this->free].Next;
		this->myList[this->myBack].Next = -1;
		this->mySize++;


	}

	void DisplayInfo(void){
		cout << "First: " << first << " Free: " << free << " myBack: " << myBack
				<< " mySize " << mySize << endl;
	}

	int CountNode(void){
		int counter = 0;
		for(int i = this->first; i != -1; i = this->myList[i].Next){
			counter ++;
		}
		return counter;
	}

	bool isAsc(void){
		for(int ptr = this->first; this->myList[ptr].Next != -1; ptr = this->myList[ptr].Next){
			char data = this->myList[ptr].Data;
			char nextData = this->myList[this->myList[ptr].Next].Data;
//			cout << "Data: " << data << " Next Data: " << nextData << endl;
			if(data > nextData){
				return false;
			}
		}
		return true;
	}

	void Delete(char data){
		if(this->Empty()){
			cerr << "List is empty!" << endl;
			return;
		}
		int prev = this->first;
		int i = this->myList[prev].Next;

		if(this->myList[prev].Data == data){
			this->first = i;
			this->myList[prev].Data = '\0';
			this->myList[prev].Next = free;
			free = prev;
			this->mySize = -1;
			return;
		}

		for(; i != -1; i = this->myList[i].Next){
			if(this->myList[i].Data == data){
				this->myList[prev].Next = this->myList[i].Next;
				this->myList[i].Data = '\0';
				this->myList[i].Next = this->free;
				this->free = i;
				this->mySize--;
				break;
			}
			prev = this->myList[prev].Next;
		}
	}

	void Asc(){
		if(this->isAsc() == true){
			return;
		}
		for(int ptr = this->first; this->myList[ptr].Next != -1; ptr = this->myList[ptr].Next){
				char temp, curr, next;
				curr = this->myList[ptr].Data;
				next = this->myList[this->myList[ptr].Next].Data;
				if(curr > next){
//					cout << curr <<" Swap " << next << endl;
					temp = curr;
					curr = next;
					next = temp;
					this->myList[ptr].Data = curr;
					this->myList[this->myList[ptr].Next].Data = next;
				}
		}
		if(this->isAsc() == false){
			this->Asc();
		}
	}

	void BreakLine(){
		puts("---------------Break Line---------------------");
	}
};

int main() {
	List l;
	l.Initialize();


	cout << "Question 3 a" << endl;
	l.DisplayElement();
	l.BreakLine();


	cout << "Question 3 b" << endl;
	l.Display();
	l.BreakLine();


	cout << "Question 3 c" << endl;
	l.Insert('F');
	l.Display();
	l.DisplayInfo();
	l.BreakLine();


	cout << "Question 3 d" << endl;
	cout << "Delete J,P,C,B" << endl;
	l.Delete('J');
	l.Delete('P');
	l.Delete('C');
	l.Delete('B');

	cout << "Question 3 e" << endl;
	cout << "Insert A, Delete P, Insert K, Delete C" << endl;

	l.Insert('A');
	l.Delete('P');
	l.Insert('K');
	l.Delete('C');
	l.Display();
	l.BreakLine();

	cout << "Question 3 f" << endl;
	cout << "Node count: " << l.CountNode() <<endl;
	l.BreakLine();


	cout << "Question 3 g" << endl;
	if(l.isAsc() == true){
		cout << "Is ascending order" << endl;
	}
	else{
		cout << "Not ascending order" << endl;
	}
	l.BreakLine();

	cout << "After arrange" <<endl;
	l.Asc();
	l.Display();
	if(l.isAsc() == true){
		cout << "Is ascending order" << endl;
	}
	else{
		cout << "Not ascending order" << endl;
	}
}
