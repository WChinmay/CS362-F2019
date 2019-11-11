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
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    // declare the game state
    struct gameState G;
    int seed = 9769;

    printf("Begin Testing handleBaron():\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    int test1 = G.numBuys;
    printf("Num buys is %d\n", G.numBuys);
    // call the refactored function
    int r1 = handleBaron(&G, 0, 0);
    int test2 = G.numBuys;
    printf("Num buys is %d\n", G.numBuys);
    // check if numBuys incremented by 1 after one call to handleBaron
    if (test1 == test2 -1)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }

    // call the refactored function
    int r2 = handleBaron(&G, 1, 0);

    // Second unit test could only be solved by changing a hardcoded value for card_not_discarded
    // in dominion.c. 

    // set any other variables
    // changing values to achieve coverage
    G.supplyCount[estate] = 2;
    G.handCount[0] = -1;

    // call the refactored function
    int r3 = handleBaron(&G, 1, 0);
    printf("Test completed!\n");
}