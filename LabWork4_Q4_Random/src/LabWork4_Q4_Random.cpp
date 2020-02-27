//============================================================================
// Name        : LabWork4_Q4_Random.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h> //for delay
#include <algorithm>
using namespace std;

class LinkedQueue{
    class Node{
        public:
        char Data;
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

    void Enqueue(char item){
        Node *ptr = new Node(item);
        if(Empty()){
        	myFront = myBack = ptr;
		}
		else{
			myBack->Next = ptr;
        	myBack = ptr;
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
                cout << ptr->Data;
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

    void storeString(string str){
    	int strlen = str.size() - 1;
    	for(int i = 0; i <= strlen; i++){
    		Enqueue(str[i]);
    	}
    }

   ~LinkedQueue(){
	   myFront = myBack = 0;
    }
};

#define NO_NAME 20
class randomName{
private:
	string name[NO_NAME] = {"dbrah","audrie","hank","ausannah","ethan",
			"maurita","angle","chang","douglass","barbar",
			"renea","bari","simonne","Llinette","teisha",
			"silvia","chae","hope","kala","anissa"};

	int getRand(void){
		return rand() % NO_NAME;
	}
public:
	string getName(void){
		return name[getRand()];
	}
};

int main(void) {
	randomName rn;
	LinkedQueue qAnswer,qGuess;
	string guess, answer;
	string stop = "stop";

	while(true){
		//display insturction
		cout << "Press any key to display the word" << endl;
		cout << "or type stop when answering to quit the program" << endl;
		system("PAUSE");
		//generate random answer
		answer = rn.getName();
		// store answer into queue
		qAnswer.storeString(answer);
		//display answer for a second
		qAnswer.Display();
		cout << endl;
		Sleep(1000);
		//clear screen
		system ("CLS");

		//accept guess from user
		cout << "Please enter the answer: ";
		cin >> guess;
		//clear buffer
		cin.sync();
		cout << endl;
		// convert string to lowercase only
		transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

		//store guess into queue
		qGuess.storeString(guess);
		//quit program if user type stop
		if((guess.compare(stop)) == 0){
			break;
		}
		//display result
		cout << "Your answer is ";
		qGuess.Display();
		cout << endl;
		cout << "Answer is ";
		qAnswer.Display();
		cout << endl;
		//compare guess with answer
		if(guess.compare(answer) == 0){
			cout << "Your answer is correct!" << endl;
		}
		else{
			cout << "Your answer is wrong!" << endl;
		}
		system("PAUSE");
		system ("CLS");
		qAnswer.~LinkedQueue();
		qGuess.~LinkedQueue();
	}

	return 0;
}
