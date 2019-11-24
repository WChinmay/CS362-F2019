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

    printf("Begin Testing mine_action():\n");

    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    int test1 = 3;
    int choice1 = 0;
    // gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
    // gainCard(choice2+3, state, 2, currentPlayer);
    // mine_action(struct gameState *state, int choice1, int choice2, int currentPlayer, int handPos)
    // call the refactored function
    // This unit test checks if the card indicated by supplyPos is added to the discard pile
    // of the current player
    printf("supplyPos is %d\n", test1);
    int r1 = mine_action(&G, choice1, test1, 0, 0);
    printf("supplyPos is %d\n", G.hand[0][G.handCount[0]-1]);
    int test2 = G.hand[0][G.handCount[0]-1];
    if (test1 == test2)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }
    G.handCount[0] = 3;
    test1 = G.handCount[0];
    G.hand[0][1] = G.hand[0][choice1];
    G.hand[0][2] = G.hand[0][choice1];
    int r2 = mine_action(&G, choice1, test1, 0, 0);
    test2 = G.handCount[0];
    // This unit test checks if all 1 card which is similar is discarded and not all of them
    if (test2 == test1 - 2)
    {
        myAssert();
        printf("Unit test passed!\n");
    }
    else
    {
        printf("Unit test failed :(\n");
    }

    printf("Test completed!\n");
}