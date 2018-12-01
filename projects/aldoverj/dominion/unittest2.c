#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int assertSupply(int expectedSupply, int card, struct gameState *state) {
	int resultSupply = supplyCount(card, state);
	if (expectedSupply == resultSupply){
		return 1;	// True
	}
	else {
		return 0;	// False
	}
}

int assertHandCount(int expectedHandCount, struct gameState *state) {
	int resultHand = state->handCount[0];
    if (expectedHandCount == resultHand) {
            return 1;       // True
    }
    else {
            return 0;       // False
    }	
}

int assertDiscardCount(int expectedCount, struct gameState *state) {
	int result = state->discardCount[0];
    if (expectedCount == result) {
            return 1;       // True
    }
    else {
            return 0;       // False
    }	
}

int assertDeckCount(int expectedCount, struct gameState *state) {
	int result = state->deckCount[0];
    if (expectedCount == result) {
            return 1;       // True
    }
    else {
            return 0;       // False
    }	
} 

void testGainCard() {
	struct gameState state;
	int k[10] = {adventurer, village, council_room, mine, smithy, remodel, great_hall, outpost, gardens, feast};
	int expectedSupply, expectedCard, expectedCount;
    int gainCardTest;
    struct gameState *ptr = &testGame;
    int flag;
	int seed = 2000;

	int gameInit = initializeGame(2, k, seed, state);	


	// Test gainCard() in deck (flag 1)
	printf("-- Test gainCard() to deck --\n");

	// Gain kingdom card adventurer to deck
	printf("-- Test gainCard() to hand --\n");	
	ptr->supplyCount[adventurer] = 10;
	flag = 1;
	gainCardTest = gainCard(adventurer, &state, flag, 0);
	expectedSupply = 10;
	expectedCount = 5;
	if (assertSupply(expectedSupply, adventurer, ptr) && assertDeckCount(expectedCount, ptr)) {
		printf("PASS, gain adventurer \n");
	}
	else {
		printf("FAIL gaining adventurer, expected supply: %d, count: %d; result supply: %d, count: %d \n", expectedSupply, expectedCount, ptr->supplyCount, ptr->deckCount);
	}

	
	// Test gainCard() in hand
	printf("-- Test gainCard() to hand --\n");	
	ptr->supplyCount[adventurer] = 10;
	flag = 2;
	gainCardTest = gainCard(adventurer, &state, flag, 0);
	expectedSupply = 9;
	expectedCount = 6;
	if (assertSupply(expectedSupply, adventurer, ptr) && assertHandCount(expectedCount, ptr)) {
		printf("PASS, gained adventurer \n");
	}
	else {
		printf("FAIL gaining adventurer, expected supply: %d, count: %d; result supply: %d, count: %d \n", expectedSupply, expectedCount, ptr->supplyCount, ptr->handCount);
	}


	// Test gainCard() in discard pile to simulate buying
	printf("-- Test gainCard() to discard pile --\n");

	// Gain nothing to discard pile because empty supply in Adventurer
    ptr->supplyCount[adventurer] = 0;
	flag = 0;
	gainCardTest = gainCard(adventurer, &state, flag, 0);
	expectedSupply = 0;
	expectedCount = 0;
	if (assertSupply(expectedSupply, adventurer, ptr) && assertDiscardCount(expectedCount, ptr)) {
		printf("PASS, gain nothing to hand \n");
	}
	else {
		printf("FAIL gaining adventurer, expected supply: %d, count: %d; result supply: %d, count: %d \n", expectedSupply, expectedCount, ptr->supplyCount, ptr->discardCount);
	}
}

int main()
{
	testGainCard();
	return 0;
}
