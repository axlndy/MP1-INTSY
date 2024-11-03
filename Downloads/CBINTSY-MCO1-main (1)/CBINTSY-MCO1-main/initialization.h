#include "initialization.c"
void initializeDestinations(desType *destinations);
int validateDestinationIndex(Node board[][MAX_GRID], int x, int y);
void putToIndex(Node board[][MAX_GRID], desIdx *indexesOfDestinations, int ID, int max, int type, char symbol);
void initializeBoard(Node board[][MAX_GRID], desIdx *indexesOfDestinations, int difficulty);
