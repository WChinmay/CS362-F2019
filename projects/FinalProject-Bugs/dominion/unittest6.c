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

    memset(&G, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &G);          
    G.handCount[p] = handCount;              
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);
    int bonus = 0; 
    
    G.discardCount[p] = 0;

    G.handCount[p] = 3; 
    G.hand[p][0] = 9;   // Gives 4 coins
    G.hand[p][1] = 6;   
    G.hand[p][2] = 6;   
    // G.coins = 13;
    updateCoins(p,&G,0); 

    int prev_coins = G.coins;

    cardEffect(feast, copper, 0, 0, &G, 0, &bonus);

    printf("\nCurrent coins are %d, Coins before using feast are %d\n", G.coins, prev_coins);

    if(G.coins != prev_coins){
        printf("\nError in feast function\n\n");
    } else {
        printf("\nAll good, assert passed\n\n");
    }
} 
