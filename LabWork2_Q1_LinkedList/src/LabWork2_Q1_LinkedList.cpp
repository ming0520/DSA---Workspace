//============================================================================
// Name        : LabWork2_Q1_LinkedList.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LinkedList{

protected:
	class Node{
	public:
		int Data;
		Node *Next;

		Node (int data){
			this->Data = data;
			this->Next = 0;
		}
	};

	Node *myFront;
	Node *myBack;

public:


	LinkedList (){
		this->myFront = 0;
		this->myBack = 0;
	}

	bool Empty(){
		return (this->myFront == 0);
	}

	void Push(int item){
		Node *temp = new Node(item);
		temp->Next = this->myFront;
		this->myFront = temp;
	}

	void Pop(){
		Node *temp = this->myFront;
		this->myFront = this->myFront->Next;
		delete temp;
	}

	void Display(){

		if(this->Empty()){
			cout << "This is Empty List!" << endl;
			return;
		}
		Node *ptr;
		for(ptr = this->myFront; ptr != 0; ptr = ptr->Next){
			cout << ptr->Data << endl;
		}

	}

	int countNode(){
		if(this->Empty()){
			return 0;
		}
		int counter = 0;

		Node *ptr;
		for(ptr = this->myFront; ptr != 0; ptr = ptr->Next){
			counter++;
		}

		return counter;
	}

	float Avg(){

		if(this->Empty()){
			return 0.0;
		}

		float sum = 0;
		for(Node *ptr = this->myFront; ptr != 0; ptr = ptr->Next){
			sum += ptr->Data;
		}
		return (sum / this->countNode());
	}

	bool isAsc(void){

		for(Node *ptr = this->myFront; ptr->Next != 0; ptr = ptr->Next){
			if((ptr->Data) > (ptr->Next->Data)){
//				cout << ptr->Data << " " << ptr->Next->Data << endl;
				return false;
			}
		}
		return true;
	}

	void Asc(){
		for(Node *ptr = this->myFront; ptr != 0; ptr = ptr->Next){
			for(Node *ptrNext = this->myFront; ptrNext != 0; ptrNext = ptrNext->Next){
//				cout << ptr->Data << " " << ptrNext->Data << endl;
				if(Empty() || ptrNext == 0){
					cout << "Return" << endl;
					return;
				}

				if(ptr->Data < ptrNext->Data){
//					Node *prev = ptr;
//					cout << "Swap " << ptr->Data  << " " << ptrNext->Data << endl;
//					Node *temp = ptrNext->Next;
//					ptrNext->Next = ptr->Next;
//					ptr->Next = temp;
					int num = ptr->Data;
					ptr->Data = ptrNext->Data;
					ptrNext->Data = num;
					if(!this->isAsc()){
						continue;
					}
				}
			}
		}
	}

	int SearchByCount(int x){
		int counter = 1;
		Node *ptr;
		for(ptr = this->myFront; ptr != 0; ptr = ptr->Next){
			if(ptr->Data == x){
				return counter;
			}
			counter++;
		}
		return -99;
	}

	Node *SearchByNode(int x){
		if(Empty()){
			return NULL;
		}
		Node *ptr;
		ptr = this->myFront;

		for(int i = 1; i < x; i++){
			ptr = ptr->Next;
		}
		return ptr;
	}

};

class Queue : public LinkedList{

public:

	Queue(){
		this->myBack = 0;
	}

	void Enqueue(int data){
		Node *temp = new Node(data);
		if(Empty()){
			this->myBack = this->myFront = temp;
		}
		else{
			this->myBack->Next = temp;
			this->myBack = temp;
		}
	}

	void Dequeue(){
		Node *temp = myFront;
		myFront = myFront->Next;
		temp = 0;
		delete temp;
	}

	void InsertToLast(int data){
		this->InsertTo(data,this->countNode());
	}

	void InsertTo(int data, int n){
		Node *temp = new Node(data);
		if(n > this->countNode() || n < 1){
			cout << "The location is invalid, should not greater than "
					<< this->countNode() << " and should not smaller than 1"
					<< endl;
			return;
		}
		if(this->Empty()){
			this->myFront = temp;
		}
		else{
			if(this->myFront->Next == 0){
				this->myFront->Next = temp;
			}
			else{
				Node *ptr = this->myFront;
//				cout<< "Insert to " << n << endl;
//				cout << ptr->Data <<endl <<endl;
				for(int i = 2; i < n; i++){
					ptr = ptr->Next;
				}
				temp->Next = ptr->Next;
				ptr->Next = temp;
			}
		}
	}

	void Delete(int x){
		if(this->Empty()){
			cerr << "Empty list! " << endl;
			return;
		}

		Node *ptr, *prev;
		ptr = prev = this->myFront;
		int pos = this->SearchByCount(x) - 1;
		if(pos == 0){
			this->myFront = this->myFront->Next;
			return;
		}
		if(ptr->Next == 0){
			delete ptr;
			return;
		}

		for(int i = 0; i < pos; i++){
			ptr = ptr->Next;
		}

		for(int i = 0; i < pos - 1; i++){
			prev = prev->Next;
		}

		prev->Next = ptr->Next;
		delete ptr;


	}

	void DeleteNode(int pos){

		pos--;

		if(this->Empty()){
			cerr << "Empty list! " << endl;
			return;
		}

		if(pos < 0 || pos > this->countNode()){
			cerr << "Invalid location!" << endl;
			return;
		}


		Node *ptr, *prev;
		ptr = prev = this->myFront;

		if(ptr->Next == 0){
			delete ptr;
			return;
		}

		if(pos == 0){
			this->myFront = this->myFront->Next;
			return;
		}

		for(int i = 0; i < pos; i++){
			ptr = ptr->Next;
		}

		for(int i = 0; i < pos - 1; i++){
			prev = prev->Next;
		}

		prev->Next = ptr->Next;
		delete ptr;
	}

	void ShuffleCat(Queue *y){
		Node *xPtr, *yPtr ,*tempX,*tempY;
		int nodeCount;
		xPtr = this->SearchByNode(1);
		yPtr = y->SearchByNode(1);
		tempY = yPtr->Next;
		tempX = xPtr->Next;

		if(this->countNode() > y->countNode()){
			nodeCount = y->countNode();
			for(int i = 0; i < nodeCount ;i++){
				xPtr->Next = yPtr;
				xPtr = tempX;
				yPtr->Next = xPtr;
				tempX = tempX->Next;
				yPtr = tempY;
				if(yPtr->Next != 0){
					tempY = tempY->Next;
				}
			}
		}
		else if(y->countNode() >= this->countNode()){
			nodeCount = this->countNode();
			for(int i = 0; i < nodeCount ;i++){
				xPtr->Next = yPtr;
				xPtr = tempX;
				yPtr->Next = xPtr;
				if(xPtr->Next == 0){
					xPtr->Next = tempY;
					break;
				}
				tempX = tempX->Next;
				yPtr = tempY;
				if(yPtr->Next != 0){
					tempY = tempY->Next;
				}
			}
		}
	}

	void MergeAsc(Queue *y){
		this->ShuffleCat(y);
		this->Asc();
	}

	Queue ShuffleMerge(Queue *y){
		//Initialize
		Node *xPtr, *yPtr;
		Queue q;

		//Get myFront of x and y in address form
		xPtr = this->SearchByNode(1);
		yPtr = y->SearchByNode(1);

		//Ensure the myFront is correct address
//		cout << "xPtr Data: " << xPtr->Data << endl;
//		cout << "yPtr Data: " << yPtr->Data << endl;

		//condition 1
		//if node of x greater than y
		if(this->countNode() > y->countNode()){
			//Shuffle x and y and store into new queue until end of y
			for(int i = 0; i < y->countNode(); i++){
				q.Enqueue(xPtr->Data);
				q.Enqueue(yPtr->Data);
				xPtr = xPtr->Next;
				yPtr = yPtr->Next;
			}
			//Continue store the remaining in x
			for(Node *ptr = xPtr; ptr != 0; ptr = ptr->Next){
				q.Enqueue(ptr->Data);
			}
		}
		//condition 2
		//if number of node for x is smaller than y
		else if(this->countNode() < y->countNode()){
			//Shuffle x and y and store into new queue until end of x
			for(int i = 0; i < this->countNode(); i++){
				q.Enqueue(xPtr->Data);
				q.Enqueue(yPtr->Data);
				xPtr = xPtr->Next;
				yPtr = yPtr->Next;
			}
			//continue to store the remaining in y
			for(Node *ptr = yPtr; ptr != 0; ptr = ptr->Next){
				q.Enqueue(ptr->Data);
			}

		}
		//condition 3
		//if number of node for x and y are equal
		else if(this->countNode() == y->countNode()){
			//shuffle x and y and store into new queue;
			for(int i = 0; i < this->countNode(); i++){
				q.Enqueue(xPtr->Data);
				q.Enqueue(yPtr->Data);
				xPtr = xPtr->Next;
				yPtr = yPtr->Next;
			}
		}
		//return the shuffled queue as object
		return q;

	}

	void Reverse(){
		Node *prev, *curr, *next;

		curr = this->myFront;
		prev = next = 0;

		while(curr != 0){
			next = curr->Next;
			curr->Next = prev;
			prev = curr;
			curr = next;
		}
		this->myBack = this->myFront;
		this->myFront = prev;
	}

};

int main() {
	Queue q;
	q.Enqueue(99);
	q.Enqueue(4);
	q.Enqueue(20);
	q.Enqueue(35);
	q.Enqueue(5);
	cout << "Display: X" << endl;
	q.Display();
	cout << "Count: " << q.countNode() << endl;
	cout << "Display completed!" << endl<<endl;

	cout << "-----------Break line for enqueue, dequeue, insert test----------------" << endl;
	cout << "After Dequeue" << endl;
	q.Dequeue();

	cout << "Display: " << endl;
	q.Display();
	cout << "Display completed!" << endl<<endl;

	cout << "Insert 30 to 3rd node" << endl;
	q.InsertTo(30,3);
	cout << "Insert 25 before last node" << endl;
	q.InsertToLast(25);

	cout << "Display: " << endl;
	q.Display();
	cout << "Display completed!" << endl<<endl;
	cout << "-----------Break line for average----------------" << endl;
	cout << "Avg: " << q.Avg() << endl;

	cout << "-----------Break line before sort ----------------" << endl;
	q.Display();
	q.Asc();
	cout << "-----------Break line after sort----------------" << endl;

	if(q.isAsc() == true){
		cout << "Is ascending order" << endl;
	}
	else{
		cout << "Not ascending order" << endl;
	}
	q.Display();

	printf("-----------Break line for search----------------\n");
		int x = 5;
		printf("%i is at node%i and address is ",
				x,q.SearchByCount(x));
		cout << q.SearchByNode(x) << endl;
	printf("-----------Break line for delete function----------------\n");
	cout << "After delete 5 in list" << endl;
	q.Delete(5);
	q.Display();
	cout << "Display completed!" << endl<<endl;
	cout << "After delete node1 in list" << endl;
	q.DeleteNode(1);
	q.Display();
	cout << "Display completed!" << endl<<endl;
	cout << "Number of node: " << q.countNode() << endl;

	cout << "======================Shuffle merger test================================" << endl;
	Queue newX,newY;

	for(int i = 0; i < 10; i++){
		newX.Enqueue(i);
	}

	for(int i = 80; i > 0; i-=10){
		newY.Enqueue(i);
	}
	cout << "----------------Before merge------------------" << endl;
	cout << "X: " << endl;
	newX.Display();
	cout << "Display completed" << endl;
	cout << "Y: " << endl;
	newY.Display();
	cout << "Display completed" << endl;

	cout << "----------------After shuffle x and y and create a new list----------------" << endl;
	Queue merged = newX.ShuffleMerge(&newY);
	cout << "Z: " << endl;
	merged.Display();
	cout << "Display completed" << endl;
	cout << "----------------After shuffle x and y by change the link----------------" << endl;
	newX.ShuffleCat(&newY);
	cout << "X: " << endl;
	newX.Display();
	cout << "Display completed" << endl;

	Queue newA,newB;
	cout << "----------------Before merge----------------" << endl;
	for(int i = 0; i < 6; i++){
		newA.Enqueue(i);
	}

	for(int i = 80; i > 0; i-=10){
		newB.Enqueue(i);
	}

	cout << "A: " << endl;
	newA.Display();
	cout << "Display completed" << endl;
	cout << "B: " << endl;
	newB.Display();
	cout << "Display completed" << endl;

	cout << "---------------------After merge in ascending order-----------------" << endl;
	newA.MergeAsc(&newB);
	newA.Display();
}
