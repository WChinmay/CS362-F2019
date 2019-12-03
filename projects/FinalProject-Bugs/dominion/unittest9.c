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

    printf("Begin Testing bug 9:\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    G.deckCount[0] = 5;
    G.deckCount[1] = 5;
    // Setting all cards for next player to be treasure cards
    for (int i = 0; i < G.deckCount[1]; i++)
    {
        G.hand[1][i] = copper; 
        G.deck[1][i] = copper; 
    }
    int test1 = G.numActions;
    printf("Num actions is %d\n", G.numActions);
    printf("Num coins is %d\n", G.coins);
    // call the refactored function
    int r1 = cardEffect(tribute, 0, 0, 0, &G, 0, &bonus);
    int test2 = G.numActions;
    printf("Num actions is %d\n", G.numActions);
    printf("Num coins is %d\n", G.coins);

    // check if numActions stays constant since only treasure cards could be revealed
    if (test1 == test2)
    {
        myAssert();
        printf("Unit test passed! Bug 9 fixed.\n");
    }
    else
    {
        printf("Unit test failed :(. Bug 9 persists.\n");
    }
    printf("Test completed!\n");
}