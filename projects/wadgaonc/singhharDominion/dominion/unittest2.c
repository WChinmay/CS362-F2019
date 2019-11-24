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

    printf("Begin Testing minion_action():\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    int test1 = G.coins;
    printf("Num coins is %d\n", G.coins);
    // call the refactored function
    int r1 = minion_action(&G, 1, 0, 0, 0);
    int test2 = G.coins;
    printf("Num coins is %d\n", G.coins);
    // check if num coins incremented by 2 after one call to handleMinion
    if (test1 == test2 - 2)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }
    test1 = G.handCount[0];
    printf("Hand count is %d\n", G.handCount[0]);
    // call the refactored function
    int r2 = minion_action(&G, 0, 1, 0, 0);
    test2 = G.handCount[0];
    printf("Hand count is %d\n", G.handCount[0]);
    // check if player drew card 4 times by using handCount
    if (test1 == test2 - 4)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }
    // another call to handleMinion() to get higher coverage
    // set any other variables
    // setting handcount of other player to be more than 4 to execute left over code block
    G.handCount[1] = 5;
    // call the refactored function
    int r3 = minion_action(&G, 0, 1, 0, 0);
    printf("Test completed!\n");
}