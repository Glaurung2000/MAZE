
#include "labirinth.h"

int X, Y;
int fX, FY; // finish
int N, M;
//int matrix[n]; // тут строка 20
int **MAZE;
void crceate_fild(int n){
	system("cls");
	//time_t THE_time;
	srand(time(NULL));
	//int start_time = THE_time;
	N=n;
	printf("Maze size:%d", N);
	printf("x%d\n", N);
	//printf("\n");
	
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
//==================================================================|BFS|=================================================================

	int cur_x = 0, cur_y = 0; // Current x & y
	dist[cur_y][cur_x] = 1;
	int dir, popytka, sosed;
	int ddy [4] = { -1, 0, 1, 0};
	int ddx [4] = { 0, 1, 0, -1};
	while(dist[N-1][N-1] == -1)  {
		/*if (THE_time - start_time > 3) {
			printf("ERROR: timeout exception\n");
			return 0;
		}*/	
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
		MAZE = maze;
	}
	
	
	
//==================================================/Печать массива в консоль/=================================================
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (maze[i][j] == 0) printf("%c", 219);
			else if (maze[i][j] == 1) printf("%c", 176);
		}
		printf("\n");
	}
	system("pause");
//=============================================================================================================================	

}
bool is_finish(int x, int y){
	printf("TODO: is_finish\n");
	return 0;
}
void move(int x, int y, int direction){ // direction 0 - down, 1 - up, 2 - left, 3 - right
	printf("TODO: move\n");
}