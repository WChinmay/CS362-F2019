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
        printf("\n--------------------------- Unit Test 1: --------------------------\n");
        printf("\n------------------- Testing getCost: -----------------\n");
	// ----------- TEST getCost for silver, copper, gold --------------
	printf("\n-- Test copper, silver, gold cost are correct --\n");
        
        confirm(getCost(copper) == 0);
	printf("Copper: Function Return = %d, Expected = %d\n", getCost(copper), 0);
        confirm(getCost(silver) == 3);
	printf("Silver: Function Return = %d, Expected = %d\n", getCost(silver), 3);
        confirm(getCost(gold) == 6);
	printf("Gold: Function Return = %d, Expected = %d\n", getCost(gold), 6);



        int card = mine;
    	int choice1, choice2, result, handPos;
        int choice3 = -1;
        int* bonus = 0;
      	int seed = 1000;
    	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};



        printf("\n---------------- Testing discardCard: ----------------\n");

        // initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
        
	// ----------- TEST card is trashed --------------
	printf("\n-- Test played card count does not increase when card is trashed --\n");
        
        // Set player hand
	G.handCount[thisPlayer] = 1;
	G.hand[thisPlayer][0] = mine;
        // Create empty played cards stack
        G.playedCardCount = 0;
        G.playedCards[0] = -1;
        //Trash card
        discardCard(0, thisPlayer, &G, 1);
        confirm(G.playedCardCount == 0);
        printf("Played Card Count = %d, Expected = %d\n", G.playedCardCount, 0);

        // ----------- TEST card is not trashed --------------
        printf("\n-- Test played card count increases when card is not trashed --\n");
        // Set player hand
	G.handCount[thisPlayer] = 1;
	G.hand[thisPlayer][0] = mine;
        // Set played cards
        G.playedCardCount = 0;
        G.playedCards[0] = -1;
        // Discard card
        discardCard(0, thisPlayer, &G, 0);

        confirm(G.playedCardCount == 1);
        printf("Played Card Count = %d, Expected = %d\n", G.playedCardCount, 1);



	printf("\n------------ Testing cardEffect for Mine: ------------\n");

	// ----------- TEST 1: Choice 1 and 2 are valid --------------
	printf("\n-- TEST 1: Choice 1 and 2 are valid --\n");

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

        // Create empty played cards stack
        G.playedCardCount = 0;
        G.playedCards[0] = -1;
        G.playedCards[1] = -1;

	// Set player hand
	G.handCount[thisPlayer] = 5;
	G.hand[thisPlayer][0] = mine;
	G.hand[thisPlayer][1] = copper;
	G.hand[thisPlayer][2] = village;
	G.hand[thisPlayer][3] = estate;
	G.hand[thisPlayer][4] = feast;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	choice2 = silver;
        handPos = 0;
        result = cardEffect(card, choice1, choice2, choice3, &testG, handPos, bonus);
	discardCard(handPos, thisPlayer, &G, 0);
	discardCard(choice1, thisPlayer, &G, 1);
	gainCard(silver, &G, 2, thisPlayer);

	confirm(result == 0);
	printf("Function Return = %d, Expected = %d\n", result, 0);
	confirm(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	printf("Hand Count = %d, Expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        confirm(G.playedCardCount == testG.playedCardCount);
        printf("Played Card Count = %d, Expected = %d\n", testG.playedCardCount, G.playedCardCount);


	// ----------- TEST 2: Choice 2 equals -1 --------------
	printf("\n-- TEST 2: Choice 2 is not a card --\n");

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// Set player hand
        G.handCount[thisPlayer] = 5;
	G.hand[thisPlayer][0] = mine;
	G.hand[thisPlayer][1] = copper;
	G.hand[thisPlayer][2] = duchy;
	G.hand[thisPlayer][3] = smithy;
	G.hand[thisPlayer][4] = feast;

	// Copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	choice2 = -1;
	handPos = 0;
	result = cardEffect(card, choice1, choice2, choice3, &testG, handPos, bonus);
		
	confirm(result == -1);
	printf("Function Return = %d, Expected = %d\n", result, -1);
	        

	printf("\n >>>>> Testing complete <<<<<\n\n");
	return 0;
}

