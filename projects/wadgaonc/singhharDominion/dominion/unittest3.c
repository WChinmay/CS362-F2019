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

    printf("Begin Testing ambassador_action():\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    // int card = G.hand[currentPlayer][choice1]
    int choice1 = 0;
    int card = G.hand[0][choice1];
    int test1 = G.supplyCount[choice1];
    printf("Supply count for card is %d\n", G.supplyCount[choice1]);
    // call the refactored function
    int r1 = ambassador_action(&G, choice1, 0, 2, 0);
    int test2 = G.supplyCount[choice1];
    printf("Supply count for card is %d\n", G.supplyCount[choice1]);
    // check if supplyCount decrements by one since Ambassador is trashed and nothing should be
    // gained for current player
    if (test1 == test2 - 1)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }
    // set any other variables
    test1 = G.handCount[0];
    choice1 = 3;
    int choice2 = 2;
    // call the refactored function
    int r2 = ambassador_action(&G, choice1, choice2, 2, 0);
    test2 = G.handCount[0];
    // The number of discarded cards should be equal to choice2 since 
    // choice2 is the number of max discards.
    if (test1 == test2 - choice2)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }
    // calls for coverage
    G.handCount[0] = 5;
    G.hand[0][0] = G.hand[0][choice1];
    int r3 = ambassador_action(&G, choice1, choice2, 4, 0);
    int r4 = ambassador_action(&G, choice1, -1, 4, 0);
    printf("Test completed!\n");
}