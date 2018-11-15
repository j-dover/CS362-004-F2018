#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * randomtestadventurer.c
 *
 *    
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 */

int testAdventurer(int player, struct gameState *state, int drawntreasure, int *temphand, int z) {

	int adventurerTest;
	adventurerTest = adventurerEffect(player, state, drawntreasure, temphand, z);
	
}

int main() {
	

	struct gameState testGame;
	printf("Testing adventurerEffect\n");	
	printf("RANDOM TESTS \n");

	SelectStream(2);
	PutSeed(3);

	
	exit(0);

	return 0;
}
