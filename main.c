#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "labirinth.h"
#include "player_actions.h"
#include "ui.h"
//#include "ficha.h"


int main() {
    int choice;

    printf("Welcome to the maze game!\n");
    printf("1. Start game\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Starting game...\n");
            // Здесь может быть вызов функции, которая запускает игру
            break;
        case 2:
            printf("Instructions:\n");
            printf("The goal of the game is to find your way out of the maze.\n");
            printf("You can move up, down, left, or right.\n");
            printf("Avoid obstacles and dead ends.\n");
            break;
        case 3:
            printf("Exiting game...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}