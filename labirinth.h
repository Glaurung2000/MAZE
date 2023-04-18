#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void crceate_fild(int);	// creats fild - matrix(n*m): 0 - road, 1 - wall

bool is_finish(int, int);	// checks if current X & Y is equal to finish X & Y

void move(int, int, int);	// changes X & Y if there's no wall, else doesn't do anything 
 