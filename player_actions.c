#include "player_actions.h"
#include <iostream>
int playerX = 0;
int playerY = 0;

while (1) { // Бесконечный цикл игры
    printf("Your current position: (%d, %d)\n", playerX, playerY);
    printf("Enter your move (w for up, a for left, s for down, d for right): ");
    char input = /*SOME METHOD TO GET PLAYER ACTION (GET IVENT)*/getchar();

    int newX = playerX;
    int newY = playerY;

    switch (input) {
        case 'w':
            newY--;
            break;
        case 'a':
            newX--;
            break;
        case 's':
            newY++;
            break;
        case 'd':
            newX++;
            break;
        default:
            printf("Invalid input!\n");
            continue; // Начать цикл заново
    }

    if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
        printf("You hit a wall!\n");
        continue; // Начать цикл заново
    }

    int direction = mazeplayerYplayerX;
    if (newX < playerX && (direction & 8)) { // Влево
        printf("You move left.\n");
        playerX = newX;
    } else if (newX > playerX && (direction & 2)) { // Вправо
        printf("You move right.\n");
        playerX = newX;
    } else if (newY < playerY && (direction & 1)) { // Вверх
        printf("You move up.\n");
        playerY = newY;
    } else if (newY > playerY && (direction & 4)) { // Вниз
        printf("You move down.\n");
        playerY = newY;
    } else {
        printf("You hit a wall!\n");
        continue; // Начать цикл заново
    }

    if (playerX == WIDTH - 1 && playerY == HEIGHT - 1) {
        printf("Congratulations, you won!\n");
        break; // Выход из бесконечного цикла
    }
}