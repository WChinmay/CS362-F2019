#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };  // declarethe game state
    struct gameState G;// declarethe arrays 
    int seed = 1241;
    int coppers[MAX_HAND];
    int p = 0;
    int handCount = p;

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, k, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    
    int i;
    for (i=0;i<25;i++) {
        G.supplyCount[i] = 2;
    }
    G.supplyCount[0] = 0;
    G.supplyCount[26] = 0;
    G.supplyCount[23] = 0;

    printf("Supply count is 0 for cards 0, 23, 26\n");

    if (isGameOver(&G) == 0) {
        printf("\nGame not over, error in game over function\n\n");
    } else {
        printf("\nAll good, assert passed\n\n");
    }
}