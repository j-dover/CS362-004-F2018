#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * randomtestadvenuter.c
 *
 *    
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
