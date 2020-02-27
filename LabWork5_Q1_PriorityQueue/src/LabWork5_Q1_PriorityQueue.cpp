//============================================================================
// Name        : LabWork5_Q1_PriorityQueue.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LinkedQueue{
    class Node{
        public:
        int Data;
        Node *Next;

        Node(int item){
            Data = item;
            Next = 0;
        }
    };
    Node *myFront, *myBack;
    public:
    LinkedQueue(){
        myFront = myBack = 0;
    }

    bool Empty(){
        return (myFront == 0);
    }

    void Enqueue(int item){
        Node *ptr = new Node(item);

        if(Empty() || myFront->Data < ptr->Data){
        	ptr->Next = myFront;
        	myFront = ptr;
        	return;
		}
		else{
	        Node *i = myFront;
	        while(i->Next != NULL && i->Next->Data > ptr->Data)
	        		i = i->Next;
	        ptr->Next = i->Next;
	        i->Next = ptr;

		}
    }

    void Dequeue(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            Node* ptr = myFront;
            myFront = myFront->Next;
            delete ptr;

            if(myFront == 0){
                myBack = 0;
            }
        }
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            for(Node *ptr = myFront; ptr != 0; ptr = ptr->Next){
                cout << ptr->Data << endl;
            }
        }
    }

    int Front(){
        if(Empty()){
            cerr << "Empty Queue" << endl;
            return 0;
        }
        else{
            return(myFront->Data);
        }
    }
};

void br(){
    cout << "======" << endl;
}

int main (void){
    LinkedQueue lq;
    lq.Display();
    br();
    cout << "Enqueue: " ;
    for(int i = 10; i > 5; i--){
        cout << i << " ";
        lq.Enqueue(i);
    }
    cout << endl;

    lq.Display();
    br();
    cout << "Dequeue: ";
    for(int i = 0; i < 3; i++){
        cout << lq.Front() << " ";
        lq.Dequeue();
    }
    cout << endl;
    lq.Display();
    br();

    cout << "Front: " << lq.Front() << endl;
}
