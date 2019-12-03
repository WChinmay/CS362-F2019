#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"


void confirm (int passed) {
	if (passed == 1)
		printf("PASSED: ");
	else
		printf("FAILED: ");
}


int main() {
        printf("\n----------------- Testing getCost: ----------------\n");
	// ----------- TEST getCost for silver, copper, gold --------------
	printf("\n-- Test copper, silver, gold cost are correct --\n");
        
        confirm(getCost(estate) == 2);
	printf("Estate: Function Return = %d, Expected = %d\n", getCost(estate), 2);
        confirm(getCost(village) == 3);
	printf("Village: Function Return = %d, Expected = %d\n", getCost(village), 3);
        confirm(getCost(gold) == 6);
	printf("Gold: Function Return = %d, Expected = %d\n", getCost(gold), 6);



        int card = remodel;
    	int choice1, choice2, result, handPos;
        int choice3 = -1;
        int* bonus = 0;
      	int seed = 1000;
    	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};



	printf("\n----------- Testing cardEffect for Remodel: ----------\n");

	// ----------- TEST 1: Choice 1 and 2 are valid --------------
	printf("\n-- TEST 1: Choice 1 and 2 are valid --\n");

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

        // Set player hand
	G.handCount[thisPlayer] = 5;
	G.hand[thisPlayer][0] = mine;
	G.hand[thisPlayer][1] = copper;
	G.hand[thisPlayer][2] = village;
	G.hand[thisPlayer][3] = estate;
	G.hand[thisPlayer][4] = feast;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 3;
	choice2 = village;
        handPos = 0;

        result = cardEffect(card, choice1, choice2, choice3, &testG, handPos, bonus);

	discardCard(handPos, thisPlayer, &G, 0);
	discardCard(choice1, thisPlayer, &G, 1);
	gainCard(choice2, &G, 0, thisPlayer);

	confirm(result == 0);
	printf("Function Return = %d, Expected = %d\n", result, 0);
	confirm(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	printf("Hand Count = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        	

	// ----------- TEST 2: Choice 2 costs more than the cost of the trashed card + 3 --------------
	printf("\n-- TEST 2: Choice 2 is too expensive --\n");

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// Set player hand
        G.handCount[thisPlayer] = 5;
	G.hand[thisPlayer][0] = mine;
	G.hand[thisPlayer][1] = estate;
	G.hand[thisPlayer][2] = duchy;
	G.hand[thisPlayer][3] = smithy;
	G.hand[thisPlayer][4] = feast;

	// Copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2 = gold;
	handPos = 0;
	result = cardEffect(card, choice1, choice2, choice3, &testG, handPos, bonus);
        		
	confirm(result == -1);
	printf("Function Return = %d, Expected = %d\n", result, -1);
        confirm(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	printf("Hand Count = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);

	printf("\n >>>>> Testing complete <<<<<\n\n");
	return 0;
}
