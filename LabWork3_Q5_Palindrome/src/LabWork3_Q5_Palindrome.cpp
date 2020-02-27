//============================================================================
// Name        : LabWork3_Q5_Palindrome.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

#define CAPACITY 10

class ArrayStack{


    public:

	int myTop;
	char myArray[CAPACITY];

    ArrayStack(){
        myTop = -1;
    }

    bool Empty(void){
        return (myTop == -1);
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
                cout << myArray[i];
            }
        }

    }

    int Top(){
        if(Empty()){
        	cerr << "Stack is empty!" << endl;
        	return 0;
        }
        else{
        	return (myArray[myTop]);
        }
    }

    void Push(string str){
    	int size = str.size();
    	for(int i = 0; i < size; i++){
            if(myTop == (CAPACITY - 1)){
                cerr << "Full Stack" << endl;
            }
            else{
                myTop++;
                myArray[myTop] = str[i];
            }
    	}
    }

    bool palindrome (void){
    	bool isPalindrome = true;
        for (int i = 0; i < myTop / 2 ; i++)
        {
            if(myArray[i]!= myArray[myTop - i])
            {
            	isPalindrome = false;
            }
        }
        return isPalindrome;
    }
};

int main() {
	ArrayStack as,as2,as3;

	as.Push("radar");
	as.Display();
	if(as.palindrome()){
		cout << " is Palindrome" << endl;
	}
	else{
		cout << " is not Palindrome" << endl;
	}


	as2.Push("redder");
	as2.Display();
	if(as2.palindrome()){
		cout << " is Palindrome" << endl;
	}
	else{
		cout << " is not Palindrome" << endl;
	}

	as3.Push("hello");
	if(as3.palindrome()){
		cout << "hello is Palindrome" << endl;
	}
	else{
		cout << "hello is not Palindrome" << endl;
	}

//	cout << "myTop: " << as.myTop << endl;
//	cout << "myArray: " << as.myArray << endl;
}
