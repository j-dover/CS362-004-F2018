#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int assertSupply(int expectedSupply, int card, struct gameState *state) {
	int resultSupply = supplyCount(card, state);
	if (expectedSupply != resultSupply){
		return 0;	// False
	}
	else {
		return 1;	// True
	}
}

int assertGainCard(int expectedCard, int gainedCard) {
}

int assertHandCount(int expectedHandCount, struct gameState *state) {
	int resultHand = handCard();
}

void testGainCard() {
	struct gameState testGame;
	int k[10] = {adventurer, village, council_room, mine, smithy, remodel, great_hall, output, gardens, feast};
	int expectedSupply, expectedCard, expectedCount;
        int gainCardTest;
	int seed = 2000;

	int gameInit = initializeGame(2, k, seed, testGame);	


	// Test gainCard() in deck (flag 1)
	printf("-- Test gainCard() to deck --\n");



	// Gain kingdom card adventurer to deck


	// Gain treasure card to deck


	// Gain curse to deck


	// Gain victory to deck	
	
	
	// Test gainCard() in hand
	printf("-- Test gainCard() to hand --\n");	


	// Gain nothing to hand because empty supply in Adventurer
	testGame->supplyCount[adventurer] = 0;
	gainCard(adventurer, &testGame, 2, 0);
	expectedSupply = 0;
	if (assertSupply()) {
		printf("PASS, gain nothing to hand \n");
	}
	else {
		printf("FAIL, gained adventurer, supply count:%d", expectedSupply );
	}

	// Gain kingdom Card adventurer to hand

	
	// Gain treasure to hand	


	// Gain curse to hand

	// Gain victory to hand

	// Test gainCard() in discard
}

int main()
{
	testGainCard();
	return 0;
}
