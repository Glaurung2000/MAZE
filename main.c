//#include <cstdlib>
#include <stdio.h>
#include "labirinth.h"
//#include "player_actions.h"
#include "ui.h"
//#include "ficha.h"



int main() {
    char choice;
	int exit = -1; // Выход из программы
	int end_game = -1; //  Выход из лабиринта
	int maze_size;
	int MAX_maze_size = 25;
	bool new_line = 1;
	system("cls");
	printf("Welcome to the maze game !\n");
	printf("Main menu:\n");
    printf("1. Start game\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
	//main_menu();
	
	while (exit < 0){
		if (choice != 10) {
			printf("Enter your choice:\n");
		}
		new_line = -1;
		scanf("%c",&choice);
		switch(choice) {
			case '1':
				printf("Starting game...\n");
				printf("Choose size of maze form 3 to %d: ", MAX_maze_size);
				scanf("%d", &maze_size);
				if (maze_size < 3) maze_size = 3;
				else if (maze_size > MAX_maze_size) maze_size = MAX_maze_size;
				crceate_fild(maze_size);
				end_game = 1;
				break;
			case '2':
				instuction();
				break;
			case '3':
				printf("Exiting game...\n");
				exit = 1;
				break;
			case 'M':
				main_menu();
				end_game = 1;
				break;
			case 10:
				break;
			default:
				printf("%d\n", choice);
				break;
		}
	}
    return 0;
}


