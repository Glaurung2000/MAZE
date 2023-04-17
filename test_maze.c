#pragma comment(linker, "/STACK:10000000000")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Y_size 5
#define X_size 5

#define DB 1 	//debug

int maze[Y_size][X_size];
int visited[Y_size][X_size];

// Функция для создания лабиринта
void createMaze(int y, int x) {
    // Заполнение лабиринта стенами
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Случайный выбор начальной точки
    srand(time(NULL));
    int start_x = rand() % y;
    int start_y = rand() % x;
    
    // Обход лабиринта в глубину
    visited[start_x][start_y] = 1;
    maze[start_x][start_y] = 0;
    
    // Стек для хранения координат точек
    int stack_x[y*x];
    int stack_y[y*x];
    int top = -1;
    int new_y, new_x;
    
    do {
        // Выбор случайной соседней точки
		int direction;
        do {
            direction = rand() % 4;
            switch(direction) {
                case 0: // Вверх
                    new_y = stack_x[top] - 1;
                    new_x = stack_y[top];
                    break;
                case 1: // Вправо
                    new_y = stack_x[top];
                    new_x = stack_y[top] + 1;
                    break;
                case 2: // Вниз
                    new_y = stack_x[top] + 1;
                    new_x = stack_y[top];
                    break;
                case 3: // Влево
                    new_y = stack_x[top];
                    new_x = stack_y[top] - 1;
                    break;
            }
			if (DB) { 
				printf("\n direcrion is %d", direction);
			}
        } while(new_y < 0 || new_y >= y || new_x < 0 || new_x >= x || visited[new_y][new_x]);
        
        // Отметка посещенной точки и удаление стены между текущей и выбранной точками
        visited[new_y][new_x] = 1;
        maze[new_y][new_x] = 0;
        maze[stack_x[top]][stack_y[top]] -= (1 << direction);
        
        // Добавление выбранной точки в стек
        top++;
		if (DB) {
			printf("\n top=");
			printf("%d", top);
		}
        stack_x[top] = new_y;
        stack_y[top] = new_x;
    } while(top < 10);
}

// Функция для вывода лабиринта в консоль
void printMaze(int y, int x) {
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if(maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Главная функция
int main() {
	printf(":|\n");
	//system("pause");
    createMaze(Y_size, X_size);
    printMaze(Y_size, X_size);
	printf("\n;D\n");
	system("pause");
    return 0;
}