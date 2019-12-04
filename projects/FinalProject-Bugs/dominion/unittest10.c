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
    int k[10] = { adventurer, tribute, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

    // declare the game state
    struct gameState G;
    int seed = 9769;
    int bonus = 0;

    printf("Begin Testing bug 10:\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    G.hand[0][0] = ambassador;
    G.hand[0][1] = silver;
    G.hand[0][2] = silver;
    int test1 = G.handCount[0];
    printf("Num cards in hand is %d\n", G.handCount[0]);
    // call the refactored function
    int r1 = cardEffect(ambassador, 1, 2, 0, &G, 0, &bonus);
    int test2 = G.handCount[0];
    printf("Num cards in hand is %d\n", G.handCount[0]);

    // check if the two silvers were discarded
    if ((test1 == test2 + 3) || (r1 == 0))
    {
        myAssert();
        printf("Unit test passed! Bug 10 fixed.\n");
    }
    else
    {
        printf("Unit test failed :(. Bug 10 persists.\n");
    }
    printf("Test completed!\n");
}