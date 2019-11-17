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
    int k[10] = { adventurer, estate, minion, gardens, mine, remodel, smithy, village, baron, great_hall };

    // set up some variables
    int choice1 = 0, choice2 = 0, handPos = 0, currentPlayer = 0, numPlayers = 2;

    // declare the game states
    struct gameState G, H;
    int seed = 9769;

    printf("Begin Testing handleMinion():\n");
    
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    memset(&H, 23, sizeof(struct gameState));

    for(int i = 0; i < 100; i++)
    {
        numPlayers = rand() % 10;
        currentPlayer = rand() % 9;
        choice1 = rand() % 2;     // toggle between the two choices
        choice2 = rand() % 2;     // toggle between the two choices
        // initialize a game
        int r = initializeGame(numPlayers, k, seed, &G);
        currentPlayer = whoseTurn(&G);
        G.numActions = rand() % 30;

        // randomize variable set
        if (rand() % 10 == 3)
        {
            G.handCount[currentPlayer] = -1;
        }

        // copy over game state
        memcpy(&H, &G, sizeof(struct gameState));
        
        // call function
        handleMinion(&H, choice1, choice2, currentPlayer, handPos);

        
        // Test for numActions
        if (H.numActions - 1 == G.numActions)
        {
            myAssert();
        }
        else
        {
            printf("Test for numActions failed\n");
        }

        // Test for coins
        if (choice1)
        {
            if (H.coins - 2 == G.coins)
            {
                myAssert();
            }
            else
            {
                printf("Test for coins failed\n");
            }
        }

        // Test for deck count
        if (H.discardCount[currentPlayer] - 1 == G.discardCount[currentPlayer])
        {
            myAssert();
        }
		else
        {
			printf("Failed discard count test\n");
        }

        
    }
    printf("Random Testing completed!\n");
}