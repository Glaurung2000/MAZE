#include "ui.h"


void main_menu(){	 	// В ui.c
	system("cls");
	printf("Main menu:\n");
    printf("1. Start game\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
}	

void instuction() {		// В ui.c
	system("cls");
	printf("Instructions:\n");
	printf("The goal of the game is to find your way out of the maze.\n");
	printf("You can move up, down, left, or right by using buttons: 'a', 'w', 's', 'd'.\n");
	printf("Press 'M' to return to main menu.\n\n");
}