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

    printf("Begin Testing bug 8:\n");
    printf("Begin Testing in Tribute:\n");
    memset(&G, 23, sizeof(struct gameState));
    // set the game state
    int r = initializeGame(2, k, seed, &G);
    // initialize a new game

    // set any other variables
    G.deckCount[0] = 4;
    G.deckCount[1] = 4;
    // Setting all cards for next player to be village
    for (int i = 0; i < G.deckCount[1]; i++)
    {
        G.hand[1][i] = copper; 
        G.deck[1][i] = copper; 
    } 
    int test1 = G.coins;
    printf("Num coins before function call is %d\n", G.coins);
    // call the refactored function
    int r1 = cardEffect(tribute, 0, 0, 0, &G, 0, &bonus);
    printf("Num coins after cardEffect() call is %d\n", G.coins);
    G.handCount[0] = 5;
    int r2 = updateCoins(0, &G, bonus);
    printf("Num coins after updateCoins() call is %d\n", G.coins);
    int test2 = G.coins;

    // check if number of coins reflects the bonus
    if (test1 + 2 == test2)
    {
        myAssert();
        printf("Unit test passed! Bug 8 fixed for Tribute.\n");
    }
    else
    {
        printf("Unit test failed :(. Bug 8 persists for Tribute.\n");
    }

    printf("Begin Testing in Baron:\n");
    // set any other variables
    G.deckCount[0] = 4;
    G.deckCount[1] = 4;
    // Setting all cards for next player to be estate
    for (int i = 0; i < G.deckCount[1]; i++)
    {
        G.hand[1][i] = estate; 
        G.deck[1][i] = estate; 
    } 
    test1 = G.coins;
    printf("Num coins before function call is %d\n", G.coins);
    // call the refactored function
    r1 = cardEffect(baron, 1, 0, 0, &G, 0, &bonus);
    printf("Num coins after cardEffect() call is %d\n", G.coins);
    G.handCount[0] = 5;
    r2 = updateCoins(0, &G, bonus);
    printf("Num coins after updateCoins() call is %d\n", G.coins);
    test2 = G.coins;

    // check if number of coins reflects the bonus
    if (test1 + 4 == test2)
    {
        myAssert();
        printf("Unit test passed! Bug 8 fixed for Baron.\n");
    }
    else
    {
        printf("Unit test failed :(. Bug 8 persists for Baron.\n");
    }

    printf("Begin Testing in Minion:\n");
    // set any other variables
    G.coins = 3;
    test1 = G.coins;
    printf("Num coins before function call is %d\n", G.coins);
    // call the refactored function
    r1 = cardEffect(minion, 1, 0, 0, &G, 0, &bonus);
    printf("Num coins after cardEffect() call is %d\n", G.coins);
    // G.handCount[0] = 5;
    r2 = updateCoins(0, &G, bonus);
    printf("Num coins after updateCoins() call is %d\n", G.coins);
    test2 = G.coins;

    // check if number of coins reflects the bonus
    if (test1 + 2 == test2)
    {
        myAssert();
        printf("Unit test passed! Bug 8 fixed for Minion.\n");
    }
    else
    {
        printf("Unit test failed :(. Bug 8 persists for Minion.\n");
    }

    printf("Begin Testing in Embargo:\n");
    test1 = G.coins;
    printf("Num coins before function call is %d\n", G.coins);
    // call the refactored function
    r1 = cardEffect(embargo, 0, 0, 0, &G, 0, &bonus);
    printf("Num coins after cardEffect() call is %d\n", G.coins);
    G.handCount[0] = 5;
    r2 = updateCoins(0, &G, bonus);
    printf("Num coins after updateCoins() call is %d\n", G.coins);
    test2 = G.coins;

    // check if number of coins reflects the bonus
    if (test1 + 2 == test2)
    {
        myAssert();
        printf("Unit test passed! Bug 8 fixed for Embargo.\n");
    }
    else
    {
        printf("Unit test failed :(. Bug 8 persists for Embargo.\n");
    }
    printf("Test completed!\n");
}