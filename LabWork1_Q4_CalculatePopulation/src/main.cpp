//============================================================================
// Name        : LabWork1_Q4_CalculatePopulation.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define URBAN 		0
#define SUBURBAN 	1
#define EXURBAN 	2

#define DECADE		5

using namespace std;


int main() {

	float annualMigration[3][3] = {
			{1.1, 0.3, 0.7,},
			{0.1, 1.2, 0.3,},
			{0.2, 0.6, 1.3}
	};
	float currentPopulation[3] = {2.1, 1.4, 0.9};
	float decadePopulation[5][3][3]= {0.0};

//calculate decade 0
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j){
				decadePopulation[0][i][j] = currentPopulation[i];
				continue;
			}
			decadePopulation[0][i][j] = currentPopulation[i]*annualMigration[i][j];
		}
	}

//	for(int i = 0; i < 3; i++){
//			for(int j = 0; j < 3; j++){
//				cout << decadePopulation[0][i][j] << " ";
//			}
//			puts("");
//		}

	for (int decade = 1; decade <= DECADE; decade++){
		for(int row = 0; row < 3; row++){
			for(int col = 0; col < 3; col++){
				decadePopulation[decade][row][col] =
						decadePopulation[decade-1][row][col] * annualMigration[row][col];
			}
		}
	}

	for (int decade = 0; decade <= DECADE; decade++){
		cout << "Decade:" << decade << endl;
			for(int row = 0; row < 3; row++){
				for(int col = 0; col < 3; col++){
					printf("%.6f\t",decadePopulation[decade][row][col]);
				}
				puts("");
			}
			puts("-----------------------------------------");
	}
	cout << "population in million" << endl;
}
