//============================================================================
// Name        : LabWork3_Q2_ArrayBasedStack.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define CAPACITY 10

class ArrayStack{

    public:
    int myTop;
    int myArray[CAPACITY];

    ArrayStack(){
        myTop = -1;
    }

    bool Empty(void){
        return (myTop == -1);
    }

    void Push(int item){
        if(Full()){
            cerr << "Full Stack" << endl;
        }
        else{
            myTop++;
            myArray[myTop] = item;
        }
    }

    void Pop(){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            myTop--;
        }
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            for(int i = myTop; i >= 0; i--){
                cout << myArray[i] << endl;
            }
        }

    }

    bool Full(void){
    	return (myTop ==(CAPACITY - 1));
    }

    int Top(){
        if(Empty()){
        	cerr << "Stack is empty!" << endl;
        }
        else{
        	return (myArray[myTop]);
        }
        return 0;
    }

    int Bottom(void){
        if(Empty()){
        	cerr << "Stack is empty!" << endl;
        }
        else{
        	return (myArray[0]);
        }
        return 0;
    }

    int nthElement(int n){
    	if(Empty()){
    		cerr << "Stack is empty!" << endl;
    		return 0;
    	}
    	else{
    		int data = myArray[myTop - n];
    		myTop = myTop - n - 1;
    		return data;
    	}
    }

    int nthElementUnchange(int n){
    	if(Empty()){
    		cerr << "Stack is empty!" << endl;
    		return 0;
    	}
    	else{
    		return (myArray[myTop - n]);
    	}
    }
};

int Bottom(int *arr, int myTop){
    if(myTop == -1){
    	cerr << "Stack is empty!" << endl;
    }
    else{
    	return (*arr);
    }
    return 0;
}

void br(){
    cout << "======" << endl;
}

int main (void){
    ArrayStack as;
    as.Display();
    br();
    for(int i = 0; i < 11; i++)
        as.Push(i);
    as.Display();
    br();
    as.Pop();
    as.Display();
    cout << "Top: " << as.Top() << endl;
    cout << "b.Bottom: " << as.Bottom() << endl;
    cout << "c.Bottom: " << Bottom(as.myArray,as.myTop) << endl;
    cout << "e. 5th Element Unchange: " << as.nthElementUnchange(5) << endl;
    as.Display();
    cout << "d.5th Element Changed: " << as.nthElement(5) <<endl;
    as.Display();

}
