//============================================================================
// Name        : LabWork3_Q4_TwoStackDynamic.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#define CAPACITY 10

class ArrayStack{
    private:
    int myTop, myTop2;
    int myArray[CAPACITY];

    public:
    ArrayStack(){
        myTop = -1;
        myTop2 = CAPACITY;
        for(int i = 0; i < CAPACITY - 1; i++){
        	myArray[i] = 0;
        }
    }

    bool Empty(int stack){
        if(stack == 1){
        	return (myTop == -1);
        }
        else if(stack == 2){
        	return (myTop2 == CAPACITY);
        }
        else{
        	cerr << "Invalid stack" << endl;
        	return 0;
        }
    }

    bool Full(void){
    	return ((myTop + 1) == (myTop2));
    }

    void Push(int item, int stack){
    	if(Full()){
    		cerr << "Both stack is full" << endl;
    		return;
    	}
    	if(stack == 1){
    			myTop++;
    			myArray[myTop] = item;
    	}
    	else if(stack == 2){
    			myTop2--;
    			myArray[myTop2] = item;
    	}
        else{
        	cerr << "Invalid stack" << endl;
        	return;
        }
    }

    void Pop(int stack){
    	if(Empty(stack)){
    		cerr << "Empty Stack" << stack << "!" << endl;
    		return;
    	}
    	else{
    		if(stack == 1){
    			myTop--;
    		}
    		else if(stack == 2){
    			myTop2++;
    		}
    	}
    }

    void DisplayArray(void){
    	if(Empty(1) && Empty(2)){
    		cerr << "Both stack is empty" << endl;
    	}
    	else{
    		for(int i = 0; i <= CAPACITY - 1; i++){
    			cout << myArray[i] << " ";
    		}
    		cout << endl;
    	}
    }

    void Display(int stack){
    	if(Empty(stack)){
    		cerr << "Empty Stack" << stack << "!" << endl;
    		return;
    	}
    	else{
    		if(stack == 1){
                for(int i = myTop; i >= 0; i--){
                    cout << myArray[i] << " ";
                }
    		}
    		else if(stack == 2){
                for(int i = myTop2; i <= CAPACITY - 1; i++){
                    cout << myArray[i] << " ";
                }
    		}
    		cout << endl;
    	}
    }

    int Top(int stack){
        if(stack == 1 && !Empty(1)){
        	return (myArray[myTop]);
        }
        else if(stack == 2 && !Empty(2)){
        	return (myArray[myTop2]);
        }
        else{
        	cerr << "Stack is empty!" << endl;
        }
        return 0;
    }
};

int main() {
	ArrayStack as;
	for(int i = 1; i <= 5; i++){
		as.Push(i,1);
		as.Push(i,2);
	}
	as.Push(6,1);
	as.Push(6,2);
	cout <<"Array : ";
	as.DisplayArray();
	as.Pop(1);
	as.Pop(2);
	as.Pop(2);
	cout << "Stack1: ";
	as.Display(1);
	cout << "Stack2: ";
	as.Display(2);
	as.Push(99,1);
	as.Push(88,1);
	as.Push(77,1);
	as.Push(66,1);
	cout << "Array : "; as.DisplayArray();
	cout << "Stack 1 Top: " << as.Top(1) << endl;
	cout << "Stack 2 Top: " << as.Top(2) << endl;
	for(int i = 0; i < 5; i++)
		as.Pop(2);
}
