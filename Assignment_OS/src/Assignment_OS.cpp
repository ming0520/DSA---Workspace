//============================================================================
// Name        : Assignment_OS.cpp
// Author      : Zhong Ming Tan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

#define CAPACITY 5

struct Process{
	int pid = 0;
	int burst_time = 0;
	int priority = 0;
	int waiting_time = 0;
	int turn_around_time = 0;
};

void findWaitingTime(struct Process process[],int n){
	for(int i = 1; i <= n - 1; i++){
		process[i].waiting_time = process[i-1].burst_time +
				process[i-1].waiting_time;
	}
}

void findTurnAroundTime(struct Process process[],int n){
	for(int i = 0; i <=  n - 1; i++){
		process[i].turn_around_time = process[i].burst_time +
				process[i].waiting_time;
	}
}

float findAvgWaitingTime(struct Process process[],int n){
	int sum = 0;
	float avg = 0.0;
	findWaitingTime(process,n);
	findTurnAroundTime(process,n);
	for(int i = 0; i <= n - 1; i++){
		sum += process[i].waiting_time;
	}
	avg = (float)sum / n;
	return avg;
}

float findAvgTurnAroundTime(struct Process process[],int n){
	int sum = 0;
	float avg = 0;
	findWaitingTime(process,n);
	findTurnAroundTime(process,n);
	for(int i = 0; i <= n - 1; i++){
		sum += process[i].turn_around_time;
	}
	avg = (float)sum / n;
	return avg;
}

void Display(struct Process process[], int n){
	printf("Process BurstTime Priority WaitingTime TurnAroundTime\n");
	for(int i = 0; i <= n - 1; i++){
		printf("%i\t  %i\t    %i\t    %i\t\t%i\n",
				process[i].pid,
				process[i].burst_time,
				process[i].priority,
				process[i].waiting_time,
				process[i].turn_around_time);
	}
}

void Clear(struct Process process[], int n){
	for(int i = 0; i <= n - 1; i++){
		process[i].waiting_time = 0;
		process[i].turn_around_time = 0;
	}
}

void SJF(struct Process process[], int n){
    int i, j;
    for (i = 0; i <= n-1; i++){
    	// Last i elements are already in place
		for (j = 0; j <= n-i-1; j++){
			if (process[j].burst_time > process[j+1].burst_time){
				Process temp = process[j];
				process[j] = process[j+1];
				process[j+1] = temp;
			}
		}
    }
}

void br(){
	printf("==========================================================\n");
}
//Default option: FCFS

int main() {
	struct Process process[CAPACITY];
	float avgWaitingTime;
	float avgTurnAroundTime;
	int pid[CAPACITY] = {1,2,3,4,5};
	int bt[CAPACITY] = {2,1,8,4,5};
	int priority[CAPACITY] = {2,1,4,2,3};


	for(int i = 0; i <= CAPACITY - 1; i++){
		process[i].pid = pid[i];
		process[i].burst_time = bt[i];
		process[i].priority = priority[i];
	}


	avgWaitingTime = findAvgWaitingTime(process,CAPACITY);
	avgTurnAroundTime = findAvgTurnAroundTime(process,CAPACITY);
	printf("First Come First Serve\n");
	Display(process,CAPACITY);
	printf("Average waiting time = %.2f\n",avgWaitingTime);
	printf("Average turn around time = %.2f\n", avgTurnAroundTime);
	br();

	Clear(process,CAPACITY);
	SJF(process,CAPACITY);
	avgWaitingTime = findAvgWaitingTime(process,CAPACITY);
	avgTurnAroundTime = findAvgTurnAroundTime(process,CAPACITY);
	printf("Shortest Job First\n");
	Display(process,CAPACITY);
	printf("Average waiting time = %.2f\n",avgWaitingTime);
	printf("Average turn around time = %.2f\n", avgTurnAroundTime);

}
