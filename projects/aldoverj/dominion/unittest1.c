#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void testUpdateCoins() {
	struct gameState* testGameState = newGame();
	testGameState->whoseTurn = 0;
	testGameState->coins = 0;
	testGameState->hand[0][0] = estate;
	testGameState->hand[0][1] = estate;
	testGameState->hand[0][2] = estate;
	testGameState->hand[0][3] = estate;
	testGameState->hand[0][4] = estate;
	int testBonus;

	/* Test Case: Expect 0 coins */
	testBonus = 0;
	if(testUpdateCoins(gameState->whoseTurn, testGameState, testBonus) == 0) {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, all cards in hand are estate");
	}
	else {
		printf("updateCoins(): FAIL when player 0 coins is 0, player 0 coins is 0, bonus is 0")
	}

	/* Test Case: Expect 1 coins */
	testGameState->hand[0][4] = copper;
	if(testUpdateCoins(gameState->whoseTurn, testGameState, testBonus) == 1) {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, one card is copper");
	}
	else {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, one card is copper");
	}

	/* Test Case: Expect 2 coins */
	testGameState->hand[0][4] = silver;
	if(testUpdateCoins(gameState->whoseTurn, testGameState, testBonus) == 2) {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, one card is silver");
	}
	else {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, one card is silver");
	}

	/* Test Case: Expect 3 coins */
	testGameState->hand[0][4] = gold;
	if(testUpdateCoins(gameState->whoseTurn, testGameState, testBonus) == 3) {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, one card is gold");
	}
	else {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, one card is gold");
	}

	/* Test Case: Expect 6 */
	testGameState->hand[0][0] = gold;
	testGameState->hand[0][1] = silver;
	testGameState->hand[0][2] = copper;
	testGameState->hand[0][4] = estate;

	if(testUpdateCoins(gameState->whoseTurn, testGameState, testBonus) == 3) {
		printf("updateCoins(): PASS when player 0's coins is 6, bonus is 0, hand has gold, silver, copper, and two estates");
	}
	else {
		printf("updateCoins(): PASS when player 0's coins is 0, bonus is 0, hand has gold, silver, copper, and two estates");
	}


}

int main() {
	testUpdateCoins();
	return 0;
}