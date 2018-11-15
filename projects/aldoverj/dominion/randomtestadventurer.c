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

int assertTreasures(int expectedCount, int resultCount) {
	if (expectedCount != resultCount) {
		printf("Fail Adventurer Treasure Hand Count: Expected = %d, Result = %d ", expectedCount, resultCount );
	}
	return 0;
}

int treasureHandCount(int player, struct gameState *state) {
	int handTreasures = 0;
	int handIndex = 0;
	int handCount = state->handCount[player];	
	int card;

        while(handIndex < handCount){
                card = state->hand[player][handIndex];
                if (card == copper || card == silver || card == gold) {
                        handTreasures++;
                }
                handIndex++;
        }
	return handTreasures;
}

int testAdventurer(int player, struct gameState *state) {

	int drawntreasure = 0;
	int temphand[MAX_HAND];
	int z = 0;
	int expectedCount; 
	int adventurerTest;
	int resultCount;

	// Find expected number of treasures for hand
	expectedCount = treasureHandCount(player, state);
	expectedCount = expectedCount + 2;

	// Play adventurer for result
	adventurerTest = adventurerEffect(player, state, drawntreasure, temphand, z);
	resultCount = treasureHandCount(player, state);
	
	if (assertTreasures(expectedCount, resultCount)== 0 ) {
		printf("Pass Adventurer Treasure Hand Count");
	};
}


int main() {
	
	struct gameState testGame;	// Can be randomized
	int currentPlayer;	// Can be randomized
	int intGame;
	int numPlayers;
	int kingdom[10] = {village, adventurer, smithy, council_room, remodel, gardens, sea_hag, baron, mine, steward};
	int testResult;
	int i = 0;
	int randPlayer;

	printf("Random Test: adventurerEffect\n");	

	SelectStream(2);
	PutSeed(3);
		
	numPlayers = floor(Random() * MAX_PLAYERS);
	intGame = initializeGame(numPlayers, kingdom, 1, testGame);
	
	for (i = 0; i < 20; i++) {
		randPlayer = floor(Random() * numPlayers);
		testResult = testAdventurer(randPlayer, state);
	}

	return 0;
}
