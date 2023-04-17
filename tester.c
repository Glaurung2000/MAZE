#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
int N;
//int M;
scanf ("%d",&N);
//scanf("%d", &M);
int **maze = (int **)malloc(N*sizeof(int *));
for(int i = 0; i < N; i++) {
    maze[i] = (int *)malloc(N*sizeof(int));
}
printf("%d", maze[1][2]);
*/
/**/
int main (){

	int N;

	printf("Maze size:");
	scanf ("%d",&N);
	printf("Maze size:%d", N);
	printf("x%d", N);
	printf("\n");
	
	int **maze = (int **)malloc(N*sizeof(int *));
	int **dist = (int **)malloc(N*sizeof(int *));
	for(int i = 0; i < N; i++) {
		maze[i] = (int *)malloc(N*sizeof(int));
		dist[i] = (int *)malloc(N*sizeof(int));
		for(int j = 0; j < N; j++) {
			if((i % 2 == 0)&&(j % 2 == 0)){
				maze[i][j]= 1;
				dist[i][j]=-1;
			}else {
				maze[i][j] = 0;
				dist[i][j] = 0;
			}
		}
	}
	system("pause");
//================================================================================================================================================
/*	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%3d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%3d", dist[i][j]);
		}
		printf("\n");
	}
	system("pause");
*/	
//==================================================================|BFS|=================================================================
	srand(time(NULL));
	int cur_x = 0, cur_y = 0; // Current x & y
	dist[cur_y][cur_x] = 1;
	int dir, popytka, sosed;
	int ddy [4] = { -1, 0, 1, 0};
	int ddx [4] = { 0, 1, 0, -1};
	while(dist[N-1][N-1] == -1)  {
		dir=  -1; 		//???
		popytka = 8; 	//???
		int new_x;
		int new_y;
		while((dir < 0)&&(popytka > 0)) {
			sosed = rand()%4;		// Ищем рандомного соседа 
			new_x = cur_x + ddx[sosed]*2;
			new_y = cur_y + ddy[sosed]*2;
			if( ((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] == -1) ) dir = sosed; // Проверяем что там еще не были
			popytka= popytka - 1;
		}
		if (dir >= 0)  {		// Если сосед действительно новый
			maze[cur_y + ddy[dir]][cur_x + ddx[dir]] = 1;
			dist[cur_y + ddy[dir]][cur_x + ddx[dir]] = dist[cur_y][cur_x] + 1;
			dist[new_y][new_x] = dist[cur_y][cur_x] + 2;
			cur_x = new_x;
			cur_y = new_y;
		}
		else {  		// Если сосед уже посещен
			for (sosed = 0; sosed <= 3; sosed++)  {
				if( ((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] + 2 == dist[cur_y][cur_x]) ) dir = sosed; // Ищем именно предыдущего соседа
			}
			if(dir >= 0) { // Если нашли возвращаемся в него
				cur_x = new_x;
				cur_y = new_y;
			}
		}
		
	}
/*	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%4d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%4d", dist[i][j]);
		}
		printf("\n");
	}
	system("pause");*/
//=========================================| Добавляем рандомную хрень чтобы путь был не очевиден |=======================================
	int w_m = N*N*10; // ways_multiplicator
	for(int i = 0; i < N; i+=2) {
		for(int j = 0; j < N; j+=2) {
			if (dist[i][j] == -1){
				int deeper = 4;
				while(deeper > 0) {
					cur_y = i;
					cur_x = j;
					dist[cur_y][cur_x] = 1*w_m;	
					dir=  -1; 		//???
					popytka = 4; 	//???
					int new_x;
					int new_y;
					while((dir < 0)&&(popytka > 0)) {
						sosed = rand()%4;		// Ищем рандомного соседа 
						new_x = cur_x + ddx[sosed]*2;
						new_y = cur_y + ddy[sosed]*2;
						if( ((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] == -1) ) dir = sosed; // Проверяем что там еще не были
						popytka= popytka - 1;
					}
					if (dir < 0) {
						for (sosed = 0; sosed <= 3; sosed++)  {
							if( ((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] == -1) ) dir = sosed; // Ищем именно предыдущего соседа
						}
					}
					if (dir >= 0)  {		// Если сосед действительно новый
						maze[cur_y + ddy[dir]][cur_x + ddx[dir]] = 1;
						dist[cur_y + ddy[dir]][cur_x + ddx[dir]] = dist[cur_y][cur_x] + 1;
						dist[new_y][new_x] = dist[cur_y][cur_x] + 2;
						cur_x = new_x;
						cur_y = new_y;
					}
					else {  		// Если сосед уже посещен
						deeper--;
						for (sosed = 0; sosed <= 3; sosed++)  {
							if( ((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] + 2 == dist[cur_y][cur_x]) ) dir = sosed; // Ищем именно предыдущего соседа
						}
						if(dir >= 0) { // Если нашли возвращаемся в него
							cur_x = new_x;
							cur_y = new_y;
						}
					}
				}
			}
		}
	}
	for (int h = 0; h < 100; h++) {
		for(int i = 0; i < N; i+=2) {
			for(int j = 0; j < N; j+=2) {
				if((i % 2 == 0)&&(j % 2 == 0)){
					int new_x;
					int new_y;
					dir=  -1;
					for(int k = 0; k < 50;) {
						sosed = rand()%4;
						//printf("%d\n", sosed);
						new_x = cur_x + ddx[sosed]*2;
						new_y = cur_y + ddy[sosed]*2;
						if (((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] > N*N)) dir = sosed;
						if (dir >=0) {
							maze[cur_y + ddy[dir]][cur_x + ddx[dir]] = 1;
							cur_x = new_x;
							cur_y = new_y;
							k+=10;
						}
						k++;
						
					}
					if (dir < 0) {
						for (sosed = 3; sosed > 0; sosed-=1){
							new_x = cur_x + ddx[sosed]*2;
							new_y = cur_y + ddy[sosed]*2;
							if (((new_y >= 0)&&(new_x >= 0)&&(new_y < N)&&(new_x < N)) && (dist[new_y][new_x] > N*N)) dir = sosed;
							if (dir >=0) {
								maze[cur_y + ddy[dir]][cur_x + ddx[dir]] = 1;
								cur_x = new_x;
								cur_y = new_y;
							}
						}
					}
				}
			}
		}
	}
	
	
	
//========================================================================================================================================
	
/*	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%5d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
/*	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%5d", dist[i][j]);
		}
		printf("\n");
	}
	system("pause");
	printf("\n");*/
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (maze[i][j] == 0) printf("%c", 219);
			else if (maze[i][j] == 1) printf("%c", 176);
		}
		printf("\n");
	}
	system("pause");
	/*for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			//if (maze[i][j] == 1) printf("%c", 219);
			//else if (maze[i][j] == 0) printf("%c", 176);
			printf("%1d", maze[i][j]);
		}
		printf("\n");
	}*/	
   return 0;
}
/**/
/*
int main(){
	int maze [5] = {1,244,3554,4,7549875};
	for(int i = 0; i < 5; i++) {
		printf("%10d \n", maze[i]);
	}
	return 0;
}
*/

/**
int main(){
	int maze [5] = {1,244,3554,4,7549875};
	for(int i = 0; i < 225; i++) {
		printf("%3d", i);
		printf("%3c \n", i);
	}
	return 0;
}
/**/

/**
int main(){
	srand(time(NULL));
	int maze [5] = {1,244,3554,4,7549875};
	for(int i = 0; i < 5; i++) {
		int r = rand()%4;
		printf("%30d\n", r);
	}
	return 0;
}
/**/
