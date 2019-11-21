//============================================================================
// Name        : Example0_Person.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	string name;
	int age;

public:
	void displayName(){
		std::cout << name << endl;
	}
	void setName(string name){
		this->name = name;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Person person1;
	person1.setName("My name is Jason");
	person1.displayName();
	return 0;
}
