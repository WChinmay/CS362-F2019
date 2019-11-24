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

    printf("Begin Testing tribute_action():\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    int tributeRevealedCards[2] = {copper, province};
    int test1 = G.coins;
    printf("Num coins is %d\n", G.coins);
    // call the refactored function
    // This unit test checks if the number of coins increments by 2 for each treasure card
    int r1 = tribute_action(&G, 1, tributeRevealedCards, 0);
    int test2 = G.coins;
    printf("Num coins is %d\n", G.coins);
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
    printf("Handcount for player 0 is %d\n", G.handCount[0]);
    // call the refactored function
    // this unit test checks if current player draws two cards for a action card
    int r2 = tribute_action(&G, 1, tributeRevealedCards, 0);
    test2 = G.handCount[0];
    printf("Handcount for player 0 is %d\n", G.handCount[0]);
    if (test1 == test2 - 2)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }
    // for code coverage
    G.deckCount[1] = 1;
    int r3 = tribute_action(&G, 1, tributeRevealedCards, 0);
    G.discardCount[1] = 0;
    G.deckCount[1] = 0;
    int r4 = tribute_action(&G, 1, tributeRevealedCards, 0);
    G.discardCount[1] = 1;
    int r5 = tribute_action(&G, 1, tributeRevealedCards, 0);
    printf("Test completed!\n");
}