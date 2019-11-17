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
    int k[10] = { adventurer, estate, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    // set up some variables
    int choice1 = 0, currentPlayer = 0, numPlayers = 2;

    // declare the game states
    struct gameState G, H;
    int seed = 9769;

    printf("Begin Testing handleBaron():\n");
    
    // set the game state
    memset(&G, 23, sizeof(struct gameState));
    memset(&H, 23, sizeof(struct gameState));

    for(int i = 0; i < 100; i++)
    {
        numPlayers = rand() % 10;
        currentPlayer = rand() % 9;
        choice1 = rand() % 2;     // toggle between the two choices
        // initialize a game
        int r = initializeGame(numPlayers, k, seed, &G);
        currentPlayer = whoseTurn(&G);
        G.numBuys = rand() % 30;

        // randomize variable set
        if (rand() % 10 == 3)
        {
            G.handCount[currentPlayer] = -1;
        }

        // for (int j = 0; j < 100; j++)
        // {
        //     gainCard(k[rand() % 10], &G, 1, currentPlayer);
        // }

        // copy over game state
        memcpy(&H, &G, sizeof(struct gameState));
        
        // call function
        handleBaron(&H, choice1, currentPlayer);

        
        // Test for numBuys
        if (H.numBuys - 1 == G.numBuys)
        {
            myAssert();
        }
        else
        {
            printf("Test for numBuys failed\n");
        }

        // Test for deck count
        if (H.deckCount[currentPlayer] == G.deckCount[currentPlayer])
        {
            myAssert();
        }
		else
        {
			printf("Failed deck count test\n");
        }

        // Test for choice1 == 0
        if (choice1 == 0)
        {
            if (supplyCount(estate, &G) > 0)
            {
                if(H.supplyCount[estate] < G.supplyCount[estate])
                {
                    myAssert();
                }
                else
                {
                    printf("Failed test for supplyCount if estate gained\n");
                }
            }
        }
    }
    printf("Random Testing completed!\n");
}