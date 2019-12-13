//============================================================================
// Name        : LabWork1_Q5_MagicSquare.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Math.h>
#include <bits/stdc++.h>
#define CAPACITY 100
using namespace std;

class MagicSquare{
private:
	int n;
	int matrix[CAPACITY][CAPACITY];

public:

	MagicSquare(){
		cout << "Constructing..." <<endl;
		this->n = 0;
//		for(int i = 0; i < CAPACITY - 1; i++){
//			for(int j = 0; j < CAPACITY - 1; j++){
//				this->matrix[i][j] = 0;
//			}
//		}
		memset(this->matrix, 0, sizeof(this->matrix));
	}

	bool Odd(){
		return (this->n % 2 != 0);
	}

	void setN(int n){
		this->n = n;
		if(!Odd()){
			cout << "Please enter odd number!" << endl;
			this->n = 0;
		}
	}

	void place(int row, int col){
		cout << "Placing..." << endl;
		row--;col--;

		if(row > this->n || col > this->n){
			cout << "Invalid location, please try again!" << endl;
			return;
		}
		if(row <= 0 && col <= 0 ){
			cout << "Location should not less than 1 !" << endl;
			return;
		}

		this->matrix[row][col] = 1;
//		cout << 1 << ": " << row << " " << col << " " << endl;
		row--;
		col++;
		int border = this->n; // this->n - 1
		for(int i = 2; i <= pow(this->n,2);){
			if(row == -1 && col == border){
				row += 2;
				col --;
//				col = border - 2;
//				row = 0;
			}
			else{
				if(col == border){
					col = 0;
				}

				if(row < 0){
					row = border - 1;
				}
			}

			if(this->matrix[row][col] != 0){
				row += 2;
				col --;
//				col -= 2;
//				row++;
				continue;
			}
			else{
				this->matrix[row][col] = i++;
			}
			row--;col++;
			//i   //j
		}

//		int max = pow(this->n,2);
//		int border = this->n - 1;
//		cout << "border: " << border <<endl;
//		row--;col++;
//		string rule;
//		for(int i = 2; i <= max;){
//			cout << "Pre: "<< i << ": " << row << " " << col << " " << rule << endl;
//			if(row < 0 && col > (border)){
//				rule = "rule3(ii) put at down";
//				row=0;
//				col-=2;
//			}
//			else{
//				if(row < 0){
//					rule = "rule1 put at bottom";
//					row = border;
//				}
//				if(col > (border)){
//					rule = "rule2 col is 0";
//					col = 0;
//				}
//			}
//			cout <<"Pos: "<< i << ": " << row << " " << col << " " << rule << endl;
//			if(this->matrix[row][col] != 0){
//				cout << i << ": "<< row << " " << col << " not empty!" << endl;
//				rule = "rule3(i) is not empty";
//				col-=2;
//				row++;
//				continue;
//			}
//			else{
//				this->matrix[row][col] = i;
//				i++;
//				row--;col++;
//				rule = "";
//			}
//
//		}
	}

	void Display(){
//		printf(" COL  ");
//		for (int i = 0; i < this->n; i++){
//			printf("%02i ",i);
//		}
//		puts("");
//		printf("------");
//		for (int i = 0; i < this->n; i++){
//			printf("---");
//		}
		puts("");
		for(int i = 0; i < this->n ; i++){
//			printf("ROW%02i ",i);
			for(int j = 0; j < this->n; j++){
				printf("%02i ",this->matrix[i][j]);
			}
			puts("");
		}
	}
};

int main() {
	MagicSquare ms1;
	int input = 3;
	ms1.setN(input);
	do{
		cout << "Enter any odd value n: ";
		cin >> input;
	}while(input %2 == 0);

	ms1.setN(input);

	int row = 1;
	int col = input/2;
	col++;
	ms1.place(row,col);

	ms1.Display();
	return 0;
}
