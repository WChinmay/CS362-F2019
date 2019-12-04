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

    G.handCount[p] = 0;
    G.discardCount[p] = 1; 
    G.discard[p][0] = 2;  // Score is +3
    
    G.deckCount[p] = 2;
    G.deck[p][0] = 16;   // score is +1
    G.deck[p][1] = 3;    // Score is +6

    printf("Begin testing bug 5\n");
    printf("Hand count is %d\n", G.handCount[p]);
    printf("Discard count is %d\n", G.discardCount[p]);
    printf("Deck count is %d\n", G.deckCount[p]);
    printf("Total score is 10\n");

    int score_obtained = scoreFor(p, &G);

    if (score_obtained != 10) {
        printf("score obtained is %d\n", score_obtained);
        printf("\nError in ScoreFor function\n\n");
    } else {
        printf("\nAll good, assert passed\n\n");
    }
}