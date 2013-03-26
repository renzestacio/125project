/*
DELA ROSA, Ralph
ESTACIO, Reneelou

CMSC 125 Project: ICS-OS To-Do List Manager

Notes:
> 
> 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_TASKS 10

//Declaration of structure.
typedef struct{
	int TID;
	char TNAME[30];
	char TDESC[50];
	int priority;
//	int deadline[5];
//	int day;
//	int month;
//	int year;
}task;

int displayArray[MAX_TASKS][5];

//Declaration of function prototypes.
void printMenu(int counter);
int createNewTask(task tasks[MAX_TASKS], int counter);
int viewTaskList(task tasks[MAX_TASKS], int counter);

main(){
	int choice, counter = 0, count = 0;
	task tasks[MAX_TASKS];

	system("clear");

	do{
		printMenu(count);
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:	system("clear");
					printf("Create New Task");
					putchar('\n');
					count = createNewTask(tasks, count);
					break;
			case 2:	system("clear");
					printf("View Task List");
					putchar('\n');
					viewTaskList(tasks, count);
					break;
			case 3:	printf("Edit Task");
					break;
			case 4:	printf("Delete Task");
					break;
			case 5:	system("clear");
					exit(0);
					system("clear");
					break;
			default: system("clear");
					break;
		}
	}while(choice != 5);
}

void printMenu(int counter){
	printf("ICS-OS To-Do List Manager");
	putchar('\n');
	printf("[1] Create New Task");
	putchar('\n');
	printf("[2] View Task List (%d)", counter);
	putchar('\n');
	printf("[3] Edit Task");
	putchar('\n');
	printf("[4] Delete Task");
	putchar('\n');
	printf("[5] Exit");
	putchar('\n');
}

int createNewTask(task tasks[MAX_TASKS], int counter){
	counter++;
	tasks[counter].TID = counter;
	printf("Task name: ");
	gets(tasks[counter].TNAME);
	gets(tasks[counter].TNAME);
	printf("Task description: ");
	gets(tasks[counter].TDESC);
	printf("Priority: ");
	scanf("%d", &tasks[counter].priority);
//	printf("Deadline: ");
//	scanf("%d", &tasks[counter].deadline);

	system("clear");
	printf("New task created!\n");
	sleep(1);
	system("clear");
	return counter;
}

int viewTaskList(task tasks[MAX_TASKS], int counter){
	int iTask;

	if(counter == 0){
		printf("No task yet.\n");
	}
	else{
		for(iTask = 0; iTask < counter; iTask++){
//			iTask++;
			printf("\nTask ID: %d\n", tasks[iTask+1].TID);
			printf("Task Name: ");
			puts(tasks[iTask+1].TNAME);
			printf("Task Description: ");
			puts(tasks[iTask+1].TDESC);
			printf("Task Priority: %d\n", tasks[iTask+1].priority);
//			printf("\nTask Deadline: %d\n", tasks[iTask++].deadline);
		}
	}

	getchar();
	getchar();
	return 0;
}
