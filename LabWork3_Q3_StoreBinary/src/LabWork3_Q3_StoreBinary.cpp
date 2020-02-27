//============================================================================
// Name        : LabWork3_Q4_StoreBinary.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class LinkedStack{
    class Node{
        public:
        int Data;
        Node *Next;

        Node(int item){
            Data = item;
            Next = 0;
        }
    };
    public:
    Node *myTop;

    LinkedStack(){
        myTop = 0;
    }

    void Push(int item){
        Node *ptr = new Node(item);
        ptr->Next = myTop;
        myTop = ptr;
    }

    void Pop(){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            Node *ptr = myTop;
        myTop = myTop->Next;
        delete ptr;
        }
    }

    bool Empty(){
        return(myTop == 0);
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            for(Node *ptr = myTop; ptr != 0; ptr = ptr->Next){
                cout << ptr->Data;
            }
        }
    }
};

void dec2bin(int value){
	LinkedStack ls;
	int remainder;
	value = abs(value);
	while(value != 0){
		remainder = value % 2;
		ls.Push(remainder);
		value /= 2;
	}
	ls.Display();
}

int main() {
	dec2bin(64);
}
