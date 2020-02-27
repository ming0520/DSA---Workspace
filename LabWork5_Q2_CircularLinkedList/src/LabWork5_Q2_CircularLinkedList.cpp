//============================================================================
// Name        : LabWork5_Q2_CircularLinkedList.cpp
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
    Node *myFront;
    public:
    LinkedQueue(){
        myFront = 0;
    }

    bool Empty(){
        return (myFront == 0);
    }

    void Insert(int item){
        Node *ptr = new Node(item);
        Node *current = myFront;
        ptr->Next = myFront;
        if(Empty()){
        	 myFront = ptr->Next = ptr;
		}
		else{
//			myBack->Next = ptr;
//        	myBack = ptr;
			while(current->Next != myFront){
				current = current->Next;
			}
			current->Next = ptr;
		}
    }

    int nthSucessor(int item){
    	if(Empty()){
    		cerr << "Empty List" << endl;
    	}
    	else{
     	   Node *ptr;
     	   Node *succ = myFront;
     	   ptr = succ->Next;
     	   int counter = 0;
     	   do {
     	      if(ptr->Data == item){
     	    	  return succ->Data;
     	      }
     	     counter++;
     	     ptr=ptr->Next;
     	     succ = succ->Next;
     	   } while(ptr != myFront);
    	}
    	return -1;
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty List" << endl;
        }
        else{
        	   Node *ptr;
        	   ptr = myFront;
        	   do {
        	      cout<<ptr->Data <<" ";
        	      ptr = ptr->Next;
        	   } while(ptr != myFront);
        	   cout << endl;
        }
    }

};

int main (void){
    LinkedQueue lq;
    lq.Display();
    for(int i = 0; i < 5; i++){
        lq.Insert(i);
    }
    lq.Display();
    cout << "'3' successor is ";
    if(lq.nthSucessor(3) != -1){
    	cout << lq.nthSucessor(3);
    }
    cout << endl;
}
