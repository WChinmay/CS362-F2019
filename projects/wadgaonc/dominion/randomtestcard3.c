#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int myAssert()
{
    return 1;
}

int main()
{
    // set your card array
    int k[10] = { copper, estate, minion, province, mine, tribute, smithy, village, baron, great_hall };

    // set up some variables
    int nextPlayer = 0, currentPlayer = 0, numPlayers = 2;
    int tributeRevealedCards[2] = {copper, province};

    // declare the game states
    struct gameState G, H;
    int seed = 9769;

    printf("Begin Testing handleMinion():\n");
    
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    memset(&H, 23, sizeof(struct gameState));

    for(int i = 0; i < 100; i++)
    {
        numPlayers = (rand() % 9) + 1;
        // initialize a game
        int r = initializeGame(numPlayers, k, seed, &G);
        currentPlayer = whoseTurn(&G);
        nextPlayer = (currentPlayer + 1) % numPlayers;
        G.deckCount[nextPlayer] = rand() % 2;
        G.discardCount[nextPlayer] = rand() % 2;
        // copy over game state
        memcpy(&H, &G, sizeof(struct gameState));
        
        // call function
        handleTribute(&H, nextPlayer, currentPlayer, tributeRevealedCards);

        
        // Test for coins
        if (H.coins - 2 == G.coins)
        {
            myAssert();
        }
        else
        {
            printf("Test for coins failed\n");
        }

        // Test for deck count
        if (H.handCount[currentPlayer] - 2 == G.handCount[currentPlayer])
        {
            myAssert();
        }
		else
        {
			printf("Failed current player 2x gain card test\n");
        }

        
    }
    printf("Random Testing completed!\n");
}