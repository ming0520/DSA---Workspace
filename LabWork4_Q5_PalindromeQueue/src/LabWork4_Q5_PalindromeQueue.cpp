//============================================================================
// Name        : LabWork4_Q5_PalandromeQueue.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#define CAPACITY 10

using namespace std;

class ArrayQueue{
    private:
    char myArray[CAPACITY];
    int myFront,myBack;

    public:
    ArrayQueue(){
        myFront = myBack = 0;
    }

    bool Empty(){
        return(myBack == myFront);
    }

    void Enqueue(int item){
        int newBack = (myBack + 1) % CAPACITY;
        if(newBack == myFront){
            cerr << "Full Queue" << endl;
        }
        else{
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
                cout << myArray[i];
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

    void storeString(string str){
    	int strlen = str.size() - 1;
    	for(int i = 0; i <= strlen; i++){
    		Enqueue(str[i]);
    	}
    }

    bool palindrome (void){
    	bool isPalindrome = true;
        for (int i = myFront; i != (myBack - 1) / 2 ; i++)
        {
            if(myArray[i]!= myArray[myBack - i - 1])
            {
            	isPalindrome = false;
            }
        }
        return isPalindrome;
    }
};

int main() {
	ArrayQueue as,as2,as3;

	as.storeString("radar");
	as.Display();
	if(as.palindrome()){
		cout << " is Palindrome" << endl;
	}
	else{
		cout << " is not Palindrome" << endl;
	}


	as2.storeString("redder");
	as2.Display();
	if(as2.palindrome()){
		cout << " is Palindrome" << endl;
	}
	else{
		cout << " is not Palindrome" << endl;
	}

	as3.storeString("hello");
	as3.Display();
	if(as3.palindrome()){
		cout << " is Palindrome" << endl;
	}
	else{
		cout << " is not Palindrome" << endl;
	}

}
