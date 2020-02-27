//============================================================================
// Name        : LabWork5_Q2_CircularLinkedList.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class DoubleLinkedList{
	public:
    class Node{
        public:
        int Data;
        Node *Prev;
        Node *Next;

        Node(int item){
            Data = item;
            Next = 0;
            Prev = 0;
        }
    };
    Node *myFront;
    DoubleLinkedList(){
        myFront = 0;
    }

    bool Empty(){
    	return myFront == 0;
    }

    void Insert(int item){
    	Node *ptr = new Node(item);

    	ptr->Prev = 0;
    	ptr->Next = myFront;

    	if(myFront!=0)
    		myFront->Prev = ptr ;

    	myFront = ptr;
    }

    void Display(void){
       Node *ptr;
       ptr = myFront;

       while(ptr!=0){
          cout<<ptr->Data<<" ";
          ptr = ptr->Next;
      }
       cout<<endl;
    }

    void Count(void){
       Node *ptr = myFront;
       int count=0;

       while(ptr!=0){
          count++;
          ptr = ptr->Next;
      }
      cout<<"Number of nodes: "<<count<<endl;
    }

    Node* search(int item){
        Node *ptr = myFront;
        bool found = false;

        if(Empty())
            cout<<"Empty List"<<endl;
        else{
            for(; ptr!=0; ptr=ptr->Next){
                if(ptr->Data == item){
                    cout<<"\nItem found."<<endl;
                    found = true;
                    break;
                }
            }
            if(!found)
                cout<<"\nItem not found."<<endl;
        }

        return ptr;
    }

    void Reverse(void){
        Node *previous=0, *current=0, *NextNode=0;
        current = myFront;
        while(current!=0){
            NextNode = current->Next;
            current->Next = previous;
            previous = current;
            current = NextNode;
        }
        myFront = previous;
    }

    bool isAsc(void){
        Node *ptr;

        if(Empty() || myFront->Next==0)
            cout<<"\nLinked list is empty or has only one item."<<endl;
        else{
            for(ptr=myFront; ptr!=0; ptr=ptr->Next){
                if(ptr->Data > ptr->Next->Data){
                    return false;
                    break;
                }
                else{
                    if(ptr->Next->Next==0){
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

int main (void){
	DoubleLinkedList dll;
//	int arr[6] = {99,55,100,500,30,5};
	int arr[6] = {5,4,3,2,1,0};
	for(int i = 0; i < 6; i++){
		dll.Insert(arr[i]);
	}
	dll.Display();
	dll.Count();
	if(dll.isAsc()){
		cout << "Ordered List" << endl;
	}
	else{
		cout << "Unorderd List" << endl;
	}
	dll.Reverse();
	dll.Display();
	cout<<"The item found address is "<<dll.search(100)<<endl;
	return 0;
}
