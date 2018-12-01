#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 */


void testSmithy(struct gameState *state) {
	int smithytest;
	int expectedHand;
	int handCount;	// starting handcount
	int resultHand; // handCount after Smithy

	// Test 
	printf("-- Test Smithy --\n");

	// Test Number of Cards Added in hand of 5
	handCount = state->handCount[0]; 
	state->hand[0][count] = smithy;
	state->handCount[0]++;

	smithytest = smithyEffect(0, &state, 6);
	expectedHand = 8;
	resultHand = state->handCount[0];


	if (resultHand == expectedHand) {
		printf("PASS, drew 3 cards to hand of 6, discard Smithy, 7 cards total \n");
	}
	else {
		printf("FAIL, expected hand: %d, result hand: %d", expected, resultHand);
	}

	// Test Number of Cards Added in smaller deck of 2
	handCount = state->handCount[0]; 
	state->hand[0][count] = smithy;
	state->handCount[0]++;
	smithytest = smithyEffect(0, &state, int handPos);
	expectedHand = 9;
	resultHand = state->handCount[0];	
	if (resultHand == expectedHand) {
		printf("PASS, drew 2 cards to hand of 9, discard Smithy, 10 cards total \n");
	}
	else {
		printf("FAIL, expected hand: %d, result hand: %d", expected, resultHand);
	}	 
}

int main()
{
	// test Smithy
	struct gameState state;
	int k[10] = {adventurer, village, council_room, mine, smithy, remodel, great_hall, outpost, gardens, feast};
    int gainCardTest;
	int seed = 2000;
	int gameInit = initializeGame(2, k, seed, &state);	

	testSmithy(&state);

	return 0;
}