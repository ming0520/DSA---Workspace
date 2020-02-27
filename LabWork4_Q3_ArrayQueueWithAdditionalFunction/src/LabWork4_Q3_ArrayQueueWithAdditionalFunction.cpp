//============================================================================
// Name        : LabWork4_Q3_ArrayQueueWithAdditionalFunction.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#define CAPACITY 10

using namespace std;

class ArrayQueue{

	public:
    int myArray[CAPACITY];
    int myFront,myBack;

    ArrayQueue(){
        myFront = myBack = 0;
    }

    bool Empty(){
        return(myBack == myFront);
    }

    bool Full(void){
    	int newBack = (myBack + 1) % CAPACITY;
    	if(newBack == myFront){
    		return true;
    	}
    	else{
    		return false;
    	}
    }

    void Enqueue(int item){
        if(Full()){
            cerr << "Full Queue" << endl;
        }
        else{
        	int newBack = (myBack + 1) % CAPACITY;
            myArray[myBack] = item;
            myBack = newBack;
        }
    }

    void Dequeue(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            myFront = (myFront + 1) % CAPACITY;
        }
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            for(int i = myFront; i != myBack; i = (i+1) % CAPACITY ){
                cout << myArray[i] << endl;
            }
        }
    }

    int Front(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            return (myArray[myFront]);
        }
        return 0;
    }

    int Bottom(void){
    	if(Empty()){
    		cerr << "Empty Queue" << endl;
    		return 0;
    	}
    	else{
    		return myArray[myBack - 1];
    	}
    }

    int nthElement(int n){
    	if(Empty()){
    		cerr << "Empty Queue" << endl;
    		return 0;
    	}
    	else{
    		int data = myArray[myFront + n - 1];
    		myFront = myFront + n;
    		return data;
    	}
    }

    int nthElementUnchange(int n){
    	if(Empty()){
    		cerr << "Empty Queue" << endl;
    		return 0;
    	}
    	else{
    		return (myArray[myFront + n - 1]);
    	}
    }
};

void br(void){
    cout << "======" << endl;
}

int bottom(ArrayQueue aq){
	if(aq.Empty()){
		cerr << "Empty Queue" << endl;
		return -99;
	}
	else{
		return aq.myArray[aq.myBack - 1];
	}
}


int main (void){
    ArrayQueue aq;
    aq.Display();
    br();
    cout << "Enqueue: ";
    for(int i = 0; i < 11; i++){
        cout << i << " ";
        aq.Enqueue(i);
    }
    cout << endl;
    aq.Display();
    br();
    cout << "Dequeue: ";
    for(int i = 0; i < 3; i++){
         cout << i << " ";
        aq.Dequeue();
    }
    cout << endl;
    aq.Display();
    br();
    cout << "Front: " << aq.Front() << endl;
    cout << "Bottom member function     : " << aq.Bottom() << endl;
    cout << "Bottom non member function : " << bottom(aq) << endl;
    br();
    cout << "3rd element without changes: " << aq.nthElementUnchange(3) << endl;
    aq.Display();
    br();
    cout << "3rd element with changes   : " << aq.nthElement(3) << endl;
    aq.Display();
}
